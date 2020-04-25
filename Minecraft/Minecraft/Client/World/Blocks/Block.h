#pragma once
#include "Sounds/SoundType.h"
#include "../Items/Item.h"
#include "Materials/Material.h"
#include "State/BlockState.h"
#include "../AABB/AABB.h"
#include "Physics/BlockAABB.h"
#include "../Creative/CreativeTabs.h"

struct BlockMetaData{
    unsigned short id;
    unsigned char meta;
};

class Block{
public:
    Block() {

    }
    Block(Material mat) : blockSoundType(SoundTypes::STONE){
        enabledStats = true;
        particleGravity = 1.0f;
        sliperiness = 0.6f;
        material = mat;

        state = createDefaultState();
        fullBlock = mat.isOpaque();
        lightingOpacity = fullBlock ? 255 : 0;
        
        translucent = mat.blocksLight();

        blockHardness = 1.0f;
        blastResistance = 1.0f;
        randomTicking = false;
        lightValue = 15;
        tab = CreativeTabs::BUILDING_BLOCKS;
    }

    //Common properties and functions

    inline bool isOpaque() { return material.isOpaque(); }
    inline bool isFullBlock() { return fullBlock; }
    inline bool canMobSpawn() { return true; }
    inline char getOpacity() { return lightingOpacity; }
    inline char getLValue() { return lightValue; }
    inline bool nearestNeighborLighting() { return nearestNeighborLighting; }
    

    inline bool isBlockNormalCube() { return material.blocksMovement && isFullBlock; }
    
    inline Material getMaterial() { return material; }

    inline BlockStateBase<char> createDefaultState() { return BlockStateBase<char>(); }

    inline float getHardness() {
        return blockHardness;
    }

    //TODO: GET MAP COLORS!!!

    inline BlockMetaData getID() { return id; }

    inline Block setCreativeTab(CreativeTab t) {
        tab = t;
    }

    inline bool getRandomTick() {
        return randomTicking;
    }

    inline bool hasTileEntity() {
        return isBlockContainer;
    }

    inline AABB* getBoundingBox() {
        return &BlockFullAABB;
    }

    inline bool isOpaqueCube() {
        return true;
    }

    inline bool isCollidable() {
        return true;
    }

    //HANDLES TICK EVENT! UPDATES STATE
    inline void randomTick() {

    }

    inline void destroyedByPlayer() {

    }

    inline void neighborUpdate() {

    }

    inline short tickRate() {
        return 10;
    }

    inline void onBlockAdded() {

    }

    inline void breakBlock() {

    }

    inline char quantityDropped() {
        return 1;
    }

    inline Item getItemDrop(int fortune) {
        //Item needs a static method for this 
        //TODO: DROPS!
    }

    inline void onBlockDestroyedByExplosion() {

    }

    inline bool canPlaceBlockOnSide() {
        return true;
    }

    inline bool canPlaceBlockIn() {
        return material.isReplaceable();
    }

    inline bool onBlockActivated() {
        return false;
    }

    inline void onEntityWalk() {

    }

    inline void onBlockPlaced() {

    }

    inline void onBlockClicked() {

    }

    inline char getWeakPower() {
        return 0;
    }

    inline char getStrongPower() {
        return 0;
    }

    inline bool canProvidePower(){
        return false;
    }

    inline void harvestBlock() {

    }

    inline bool silkHarvest() {

    }

    inline void onBlockPlacedBy() {

    }

    inline bool canSpawnInBlock() {
        return (!material.isSolid() && !material.isLiquid());
    }
    
    inline Block setUnlocalizedName(std::string n) {
        name = n;
        return *this;
    }

    inline std::string getUnlocalizedName() {
        return name;
    }

    inline bool getEnabledStats() { return enabledStats; }

    inline Block disableStats() {
        enabledStats = false;
        return *this;
    }

    inline char getMobilityFlag() {
        return material.getMobility();
    }

    inline bool requiresUpdates() {
        return true;
    }

    inline bool canDropFromExplosion() {
        return true;
    }

    BlockMetaData id;

    bool fullBlock;
    //How much blocks
    unsigned char lightingOpacity;
    CreativeTab tab;

    //How much emits
    unsigned char lightValue;

    bool nearestNeighborLighting;
    bool translucent;

    float blockHardness;
    float blastResistance;
    bool enabledStats;
    bool randomTicking;
    bool isBlockContainer;
    SoundType blockSoundType;
    float particleGravity;
    Material material;
    float sliperiness;

    //Smallest data values
    BlockStateBase<char> state;

    std::string name;

    inline Block setSoundType(SoundType s) {
        blockSoundType = s;
        return *this;
    }

    inline Block setLightOpacity(char opacity) {
        lightingOpacity = opacity;
        return *this;
    }

    inline Block setLightLevel(float level) {
        lightValue = (int)(15.0f * level);
        return *this;
    }

    inline Block setResistance(float resistance) {
        blastResistance = resistance;
        return *this;
    }

    inline Block setHardness(float hardness) {
        blockHardness = hardness;

        if (blastResistance < hardness * 5.0f) {
            blastResistance = hardness * 5.0f;
        }
        return *this;
    }

    inline Block setUnbreakable() {
        blockHardness = -1;
        return *this;
    }

    inline Block setTickRandomly() {
        randomTicking = true;
        return *this;
    }

private:

};

#include "BlockSubtypes.h"
#include "../Items/DyeColors.h"
#include "../Registry/BlockRegistry.h"
class Blocks {
    void init(){
    g_BlockRegistry.addElement(0, "air", ( BlockAir()).setUnlocalizedName("air"));
    g_BlockRegistry.addElement(1, "stone", ( BlockStone()).setHardness(1.5F).setResistance(10.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("stone"));
    g_BlockRegistry.addElement(2, "grass", ( BlockGrass()).setHardness(0.6F).setSoundType(SoundTypes::PLANT).setUnlocalizedName("grass"));
    g_BlockRegistry.addElement(3, "dirt", ( BlockDirt()).setHardness(0.5F).setSoundType(SoundTypes::GROUND).setUnlocalizedName("dirt"));
    g_BlockRegistry.addElement(4, "cobblestone", ( Block(Materials::ROCK)).setHardness(2.0F).setResistance(10.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("stonebrick").setCreativeTab(CreativeTabs::BUILDING_BLOCKS));
    g_BlockRegistry.addElement(5, "planks", ( BlockPlanks()).setHardness(2.0F).setResistance(5.0F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("wood"));
    g_BlockRegistry.addElement(6, "sapling", ( BlockSapling()).setHardness(0.0F).setSoundType(SoundTypes::PLANT).setUnlocalizedName("sapling"));
    g_BlockRegistry.addElement(7, "bedrock", ( BlockEmptyDrops(Materials::ROCK)).setUnbreakable().setResistance(6000000.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("bedrock").disableStats().setCreativeTab(CreativeTabs::BUILDING_BLOCKS));
    g_BlockRegistry.addElement(8, "flowing_water", ( BlockDynamicLiquid(Materials::WATER)).setHardness(100.0F).setLightOpacity(3).setUnlocalizedName("water").disableStats());
    g_BlockRegistry.addElement(9, "water", ( BlockStaticLiquid(Materials::WATER)).setHardness(100.0F).setLightOpacity(3).setUnlocalizedName("water").disableStats());
    g_BlockRegistry.addElement(10, "flowing_lava", ( BlockDynamicLiquid(Materials::LAVA)).setHardness(100.0F).setLightLevel(1.0F).setUnlocalizedName("lava").disableStats());
    g_BlockRegistry.addElement(11, "lava", ( BlockStaticLiquid(Materials::LAVA)).setHardness(100.0F).setLightLevel(1.0F).setUnlocalizedName("lava").disableStats());
    g_BlockRegistry.addElement(12, "sand", ( BlockSand()).setHardness(0.5F).setSoundType(SoundTypes::SAND).setUnlocalizedName("sand"));
    g_BlockRegistry.addElement(13, "gravel", ( BlockGravel()).setHardness(0.6F).setSoundType(SoundTypes::GROUND).setUnlocalizedName("gravel"));
    g_BlockRegistry.addElement(14, "gold_ore", ( BlockOre()).setHardness(3.0F).setResistance(5.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("oreGold"));
    g_BlockRegistry.addElement(15, "iron_ore", ( BlockOre()).setHardness(3.0F).setResistance(5.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("oreIron"));
    g_BlockRegistry.addElement(16, "coal_ore", ( BlockOre()).setHardness(3.0F).setResistance(5.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("oreCoal"));
    g_BlockRegistry.addElement(17, "log", ( BlockOldLog()).setUnlocalizedName("log"));
    g_BlockRegistry.addElement(18, "leaves", ( BlockOldLeaf()).setUnlocalizedName("leaves"));
    g_BlockRegistry.addElement(19, "sponge", ( BlockSponge()).setHardness(0.6F).setSoundType(SoundTypes::PLANT).setUnlocalizedName("sponge"));
    g_BlockRegistry.addElement(20, "glass", ( BlockGlass(Materials::GLASS)).setHardness(0.3F).setSoundType(SoundTypes::GLASS).setUnlocalizedName("glass"));
    g_BlockRegistry.addElement(21, "lapis_ore", ( BlockOre()).setHardness(3.0F).setResistance(5.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("oreLapis"));
    g_BlockRegistry.addElement(22, "lapis_block", ( Block(Materials::IRON)).setHardness(3.0F).setResistance(5.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("blockLapis").setCreativeTab(CreativeTabs::BUILDING_BLOCKS));
    g_BlockRegistry.addElement(23, "dispenser", ( BlockDispenser()).setHardness(3.5F).setSoundType(SoundTypes::STONE).setUnlocalizedName("dispenser"));
    g_BlockRegistry.addElement(24, "sandstone", ( BlockSandStone()).setSoundType(SoundTypes::STONE).setHardness(0.8F).setUnlocalizedName("sandStone"));
    g_BlockRegistry.addElement(25, "noteblock", ( BlockNote()).setSoundType(SoundTypes::WOOD).setHardness(0.8F).setUnlocalizedName("musicBlock"));
    g_BlockRegistry.addElement(26, "bed", ( BlockBed()).setSoundType(SoundTypes::WOOD).setHardness(0.2F).setUnlocalizedName("bed").disableStats());
    g_BlockRegistry.addElement(27, "golden_rail", ( BlockRailPowered()).setHardness(0.7F).setSoundType(SoundTypes::METAL).setUnlocalizedName("goldenRail"));
    g_BlockRegistry.addElement(28, "detector_rail", ( BlockRailDetector()).setHardness(0.7F).setSoundType(SoundTypes::METAL).setUnlocalizedName("detectorRail"));
    g_BlockRegistry.addElement(29, "sticky_piston", ( BlockPistonBase()).setUnlocalizedName("pistonStickyBase"));
    g_BlockRegistry.addElement(30, "web", ( BlockWeb()).setLightOpacity(1).setHardness(4.0F).setUnlocalizedName("web"));
    g_BlockRegistry.addElement(31, "tallgrass", ( BlockTallGrass()).setHardness(0.0F).setSoundType(SoundTypes::PLANT).setUnlocalizedName("tallgrass"));
    g_BlockRegistry.addElement(32, "deadbush", ( BlockDeadBush()).setHardness(0.0F).setSoundType(SoundTypes::PLANT).setUnlocalizedName("deadbush"));
    g_BlockRegistry.addElement(33, "piston", ( BlockPistonBase()).setUnlocalizedName("pistonBase"));
    g_BlockRegistry.addElement(34, "piston_head", ( BlockPistonExtension()).setUnlocalizedName("pistonBase"));
    g_BlockRegistry.addElement(35, "wool", ( BlockColored(Materials::CLOTH)).setHardness(0.8F).setSoundType(SoundTypes::CLOTH).setUnlocalizedName("cloth"));
    g_BlockRegistry.addElement(36, "piston_extension",  BlockPistonMoving());
    g_BlockRegistry.addElement(37, "yellow_flower", ( BlockYellowFlower()).setHardness(0.0F).setSoundType(SoundTypes::PLANT).setUnlocalizedName("flower1"));
    g_BlockRegistry.addElement(38, "red_flower", ( BlockRedFlower()).setHardness(0.0F).setSoundType(SoundTypes::PLANT).setUnlocalizedName("flower2"));
    g_BlockRegistry.addElement(39, "brown_mushroom", ( BlockMushroom()).setHardness(0.0F).setSoundType(SoundTypes::PLANT).setLightLevel(0.125F).setUnlocalizedName("mushroom"));
    g_BlockRegistry.addElement(40, "red_mushroom", ( BlockMushroom()).setHardness(0.0F).setSoundType(SoundTypes::PLANT).setUnlocalizedName("mushroom"));
    g_BlockRegistry.addElement(41, "gold_block", ( Block(Materials::IRON)).setHardness(3.0F).setResistance(10.0F).setSoundType(SoundTypes::METAL).setUnlocalizedName("blockGold").setCreativeTab(CreativeTabs::BUILDING_BLOCKS));
    g_BlockRegistry.addElement(42, "iron_block", ( Block(Materials::IRON)).setHardness(5.0F).setResistance(10.0F).setSoundType(SoundTypes::METAL).setUnlocalizedName("blockIron").setCreativeTab(CreativeTabs::BUILDING_BLOCKS));
    g_BlockRegistry.addElement(43, "double_stone_slab", ( BlockDoubleStoneSlab()).setHardness(2.0F).setResistance(10.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("stoneSlab"));
    g_BlockRegistry.addElement(44, "stone_slab", ( BlockHalfStoneSlab()).setHardness(2.0F).setResistance(10.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("stoneSlab"));
    g_BlockRegistry.addElement(45, "brick_block", ( Block(Materials::ROCK)).setHardness(2.0F).setResistance(10.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("brick").setCreativeTab(CreativeTabs::BUILDING_BLOCKS));
    g_BlockRegistry.addElement(46, "tnt", ( BlockTNT()).setHardness(0.0F).setSoundType(SoundTypes::PLANT).setUnlocalizedName("tnt"));
    g_BlockRegistry.addElement(47, "bookshelf", ( BlockBookshelf()).setHardness(1.5F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("bookshelf"));
    g_BlockRegistry.addElement(48, "mossy_cobblestone", ( Block(Materials::ROCK)).setHardness(2.0F).setResistance(10.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("stoneMoss").setCreativeTab(CreativeTabs::BUILDING_BLOCKS));
    g_BlockRegistry.addElement(49, "obsidian", ( BlockObsidian()).setHardness(50.0F).setResistance(2000.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("obsidian"));
    g_BlockRegistry.addElement(50, "torch", ( BlockTorch()).setHardness(0.0F).setLightLevel(0.9375F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("torch"));
    g_BlockRegistry.addElement(51, "fire", ( BlockFire()).setHardness(0.0F).setLightLevel(1.0F).setSoundType(SoundTypes::CLOTH).setUnlocalizedName("fire").disableStats());
    g_BlockRegistry.addElement(52, "mob_spawner", ( BlockMobSpawner()).setHardness(5.0F).setSoundType(SoundTypes::METAL).setUnlocalizedName("mobSpawner").disableStats());
   // g_BlockRegistry.addElement(53, "oak_stairs", ( BlockStairs(BlockPlanks()).setHardness(2.0F).setResistance(5.0F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("wood").getDefaultState().withProperty(BlockPlanks.VARIANT, BlockPlanks.EnumType.OAK))).setUnlocalizedName("stairsWood"));
   // g_BlockRegistry.addElement(54, "chest", ( BlockChest(BlockChest.Type.BASIC)).setHardness(2.5F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("chest"));
    g_BlockRegistry.addElement(55, "redstone_wire", ( BlockRedstoneWire()).setHardness(0.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("redstoneDust").disableStats());
    g_BlockRegistry.addElement(56, "diamond_ore", ( BlockOre()).setHardness(3.0F).setResistance(5.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("oreDiamond"));
    g_BlockRegistry.addElement(57, "diamond_block", ( Block(Materials::IRON)).setHardness(5.0F).setResistance(10.0F).setSoundType(SoundTypes::METAL).setUnlocalizedName("blockDiamond").setCreativeTab(CreativeTabs::BUILDING_BLOCKS));
    g_BlockRegistry.addElement(58, "crafting_table", ( BlockWorkbench()).setHardness(2.5F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("workbench"));
    g_BlockRegistry.addElement(59, "wheat", ( BlockCrops()).setUnlocalizedName("crops"));
    g_BlockRegistry.addElement(60, "farmland", ( BlockFarmland()).setHardness(0.6F).setSoundType(SoundTypes::GROUND).setUnlocalizedName("farmland"));
    g_BlockRegistry.addElement(61, "furnace", ( BlockFurnace(false)).setHardness(3.5F).setSoundType(SoundTypes::STONE).setUnlocalizedName("furnace").setCreativeTab(CreativeTabs::DECORATIONS));
    g_BlockRegistry.addElement(62, "lit_furnace", ( BlockFurnace(true)).setHardness(3.5F).setSoundType(SoundTypes::STONE).setLightLevel(0.875F).setUnlocalizedName("furnace"));
    g_BlockRegistry.addElement(63, "standing_sign", ( BlockStandingSign()).setHardness(1.0F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("sign").disableStats());
    g_BlockRegistry.addElement(64, "wooden_door", ( BlockDoor(Materials::WOOD)).setHardness(3.0F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("doorOak").disableStats());
    g_BlockRegistry.addElement(65, "ladder", ( BlockLadder()).setHardness(0.4F).setSoundType(SoundTypes::LADDER).setUnlocalizedName("ladder"));
    g_BlockRegistry.addElement(66, "rail", ( BlockRail()).setHardness(0.7F).setSoundType(SoundTypes::METAL).setUnlocalizedName("rail"));
    //g_BlockRegistry.addElement(67, "stone_stairs", ( BlockStairs(BlockStone()).setHardness(1.5F).setResistance(10.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("stone").setUnlocalizedName("stairsStone"));
    g_BlockRegistry.addElement(68, "wall_sign", ( BlockWallSign()).setHardness(1.0F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("sign").disableStats());
    g_BlockRegistry.addElement(69, "lever", ( BlockLever()).setHardness(0.5F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("lever"));
    //g_BlockRegistry.addElement(70, "stone_pressure_plate", ( BlockPressurePlate(Materials::ROCK, BlockPressurePlate.Sensitivity.MOBS)).setHardness(0.5F).setSoundType(SoundTypes::STONE).setUnlocalizedName("pressurePlateStone"));
    g_BlockRegistry.addElement(71, "iron_door", ( BlockDoor(Materials::IRON)).setHardness(5.0F).setSoundType(SoundTypes::METAL).setUnlocalizedName("doorIron").disableStats());
    //g_BlockRegistry.addElement(72, "wooden_pressure_plate", ( BlockPressurePlate(Materials::WOOD, BlockPressurePlate.Sensitivity.EVERYTHING)).setHardness(0.5F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("pressurePlateWood"));
    g_BlockRegistry.addElement(73, "redstone_ore", ( BlockRedstoneOre(false)).setHardness(3.0F).setResistance(5.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("oreRedstone").setCreativeTab(CreativeTabs::BUILDING_BLOCKS));
    g_BlockRegistry.addElement(74, "lit_redstone_ore", ( BlockRedstoneOre(true)).setLightLevel(0.625F).setHardness(3.0F).setResistance(5.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("oreRedstone"));
    g_BlockRegistry.addElement(75, "unlit_redstone_torch", ( BlockRedstoneTorch(false)).setHardness(0.0F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("notGate"));
    g_BlockRegistry.addElement(76, "redstone_torch", ( BlockRedstoneTorch(true)).setHardness(0.0F).setLightLevel(0.5F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("notGate").setCreativeTab(CreativeTabs::REDSTONE));
    g_BlockRegistry.addElement(77, "stone_button", ( BlockButtonStone()).setHardness(0.5F).setSoundType(SoundTypes::STONE).setUnlocalizedName("button"));
    g_BlockRegistry.addElement(78, "snow_layer", ( BlockSnow()).setHardness(0.1F).setSoundType(SoundTypes::SNOW).setUnlocalizedName("snow").setLightOpacity(0));
    g_BlockRegistry.addElement(79, "ice", ( BlockIce()).setHardness(0.5F).setLightOpacity(3).setSoundType(SoundTypes::GLASS).setUnlocalizedName("ice"));
    g_BlockRegistry.addElement(80, "snow", ( BlockSnowBlock()).setHardness(0.2F).setSoundType(SoundTypes::SNOW).setUnlocalizedName("snow"));
    g_BlockRegistry.addElement(81, "cactus", ( BlockCactus()).setHardness(0.4F).setSoundType(SoundTypes::CLOTH).setUnlocalizedName("cactus"));
    g_BlockRegistry.addElement(82, "clay", ( BlockClay()).setHardness(0.6F).setSoundType(SoundTypes::GROUND).setUnlocalizedName("clay"));
    g_BlockRegistry.addElement(83, "reeds", ( BlockReed()).setHardness(0.0F).setSoundType(SoundTypes::PLANT).setUnlocalizedName("reeds").disableStats());
    g_BlockRegistry.addElement(84, "jukebox", ( BlockJukebox()).setHardness(2.0F).setResistance(10.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("jukebox"));
    //g_BlockRegistry.addElement(85, "fence", ( BlockFence(Materials::WOOD, BlockPlanks.EnumType.OAK.getMapColor())).setHardness(2.0F).setResistance(5.0F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("fence"));
    g_BlockRegistry.addElement(86, "pumpkin", ( BlockPumpkin()).setHardness(1.0F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("pumpkin"));
    g_BlockRegistry.addElement(87, "netherrack", ( BlockNetherrack()).setHardness(0.4F).setSoundType(SoundTypes::STONE).setUnlocalizedName("hellrock"));
    g_BlockRegistry.addElement(88, "soul_sand", ( BlockSoulSand()).setHardness(0.5F).setSoundType(SoundTypes::SAND).setUnlocalizedName("hellsand"));
    g_BlockRegistry.addElement(89, "glowstone", ( BlockGlowstone(Materials::GLASS)).setHardness(0.3F).setSoundType(SoundTypes::GLASS).setLightLevel(1.0F).setUnlocalizedName("lightgem"));
    g_BlockRegistry.addElement(90, "portal", ( BlockPortal()).setHardness(-1.0F).setSoundType(SoundTypes::GLASS).setLightLevel(0.75F).setUnlocalizedName("portal"));
    g_BlockRegistry.addElement(91, "lit_pumpkin", ( BlockPumpkin()).setHardness(1.0F).setSoundType(SoundTypes::WOOD).setLightLevel(1.0F).setUnlocalizedName("litpumpkin"));
    g_BlockRegistry.addElement(92, "cake", ( BlockCake()).setHardness(0.5F).setSoundType(SoundTypes::CLOTH).setUnlocalizedName("cake").disableStats());
    g_BlockRegistry.addElement(93, "unpowered_repeater", ( BlockRedstoneRepeater(false)).setHardness(0.0F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("diode").disableStats());
    g_BlockRegistry.addElement(94, "powered_repeater", ( BlockRedstoneRepeater(true)).setHardness(0.0F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("diode").disableStats());
    g_BlockRegistry.addElement(95, "stained_glass", ( BlockStainedGlass(Materials::GLASS)).setHardness(0.3F).setSoundType(SoundTypes::GLASS).setUnlocalizedName("stainedGlass"));
    g_BlockRegistry.addElement(96, "trapdoor", ( BlockTrapDoor(Materials::WOOD)).setHardness(3.0F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("trapdoor").disableStats());
    g_BlockRegistry.addElement(97, "monster_egg", ( BlockSilverfish()).setHardness(0.75F).setUnlocalizedName("monsterStoneEgg"));
    g_BlockRegistry.addElement(98, "stonebrick", ( BlockStoneBrick()).setHardness(1.5F).setResistance(10.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("stonebricksmooth"));
    //g_BlockRegistry.addElement(99, "brown_mushroom_block", ( BlockHugeMushroom(Materials::WOOD, MapColor.DIRT, block3)).setHardness(0.2F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("mushroom"));
    //g_BlockRegistry.addElement(100, "red_mushroom_block", ( BlockHugeMushroom(Materials::WOOD, MapColor.RED, block4)).setHardness(0.2F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("mushroom"));
    //g_BlockRegistry.addElement(101, "iron_bars", ( BlockPane(Materials::IRON, true)).setHardness(5.0F).setResistance(10.0F).setSoundType(SoundTypes::METAL).setUnlocalizedName("fenceIron"));
    //g_BlockRegistry.addElement(102, "glass_pane", ( BlockPane(Materials::GLASS, false)).setHardness(0.3F).setSoundType(SoundTypes::GLASS).setUnlocalizedName("thinGlass"));
    g_BlockRegistry.addElement(103, "melon_block", ( BlockMelon()).setHardness(1.0F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("melon"));
    //g_BlockRegistry.addElement(104, "pumpkin_stem", ( BlockStem(block7)).setHardness(0.0F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("pumpkinStem"));
    //g_BlockRegistry.addElement(105, "melon_stem", ( BlockStem(block9)).setHardness(0.0F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("pumpkinStem"));
    g_BlockRegistry.addElement(106, "vine", ( BlockVine()).setHardness(0.2F).setSoundType(SoundTypes::PLANT).setUnlocalizedName("vine"));
    //g_BlockRegistry.addElement(107, "fence_gate", ( BlockFenceGate(BlockPlanks.EnumType.OAK)).setHardness(2.0F).setResistance(5.0F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("fenceGate"));
    //g_BlockRegistry.addElement(108, "brick_stairs", ( BlockStairs(block5.getDefaultState())).setUnlocalizedName("stairsBrick"));
    //g_BlockRegistry.addElement(109, "stone_brick_stairs", ( BlockStairs(block8.getDefaultState().withProperty(BlockStoneBrick.VARIANT, BlockStoneBrick.EnumType.DEFAULT))).setUnlocalizedName("stairsStoneBrickSmooth"));
    g_BlockRegistry.addElement(110, "mycelium", ( BlockMycelium()).setHardness(0.6F).setSoundType(SoundTypes::PLANT).setUnlocalizedName("mycel"));
    g_BlockRegistry.addElement(111, "waterlily", ( BlockLilyPad()).setHardness(0.0F).setSoundType(SoundTypes::PLANT).setUnlocalizedName("waterlily"));
    g_BlockRegistry.addElement(112, "nether_brick", ( BlockNetherBrick()).setHardness(2.0F).setResistance(10.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("netherBrick").setCreativeTab(CreativeTabs::BUILDING_BLOCKS));
    //g_BlockRegistry.addElement(113, "nether_brick_fence", ( BlockFence(Materials::ROCK, MapColor.NETHERRACK)).setHardness(2.0F).setResistance(10.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("netherFence"));
    //g_BlockRegistry.addElement(114, "nether_brick_stairs", ( BlockStairs(block10.getDefaultState())).setUnlocalizedName("stairsNetherBrick"));
    g_BlockRegistry.addElement(115, "nether_wart", ( BlockNetherWart()).setUnlocalizedName("netherStalk"));
    g_BlockRegistry.addElement(116, "enchanting_table", ( BlockEnchantmentTable()).setHardness(5.0F).setResistance(2000.0F).setUnlocalizedName("enchantmentTable"));
    g_BlockRegistry.addElement(117, "brewing_stand", ( BlockBrewingStand()).setHardness(0.5F).setLightLevel(0.125F).setUnlocalizedName("brewingStand"));
    g_BlockRegistry.addElement(118, "cauldron", ( BlockCauldron()).setHardness(2.0F).setUnlocalizedName("cauldron"));
    //g_BlockRegistry.addElement(119, "end_portal", ( BlockEndPortal(Materials::PORTAL)).setHardness(-1.0F).setResistance(6000000.0F));
    g_BlockRegistry.addElement(120, "end_portal_frame", ( BlockEndPortalFrame()).setSoundType(SoundTypes::GLASS).setLightLevel(0.125F).setHardness(-1.0F).setUnlocalizedName("endPortalFrame").setResistance(6000000.0F).setCreativeTab(CreativeTabs::DECORATIONS));
    g_BlockRegistry.addElement(121, "end_stone", ( Block(Materials::ROCK)).setHardness(3.0F).setResistance(15.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("whiteStone").setCreativeTab(CreativeTabs::BUILDING_BLOCKS));
    g_BlockRegistry.addElement(122, "dragon_egg", ( BlockDragonEgg()).setHardness(3.0F).setResistance(15.0F).setSoundType(SoundTypes::STONE).setLightLevel(0.125F).setUnlocalizedName("dragonEgg"));
    g_BlockRegistry.addElement(123, "redstone_lamp", ( BlockRedstoneLight(false)).setHardness(0.3F).setSoundType(SoundTypes::GLASS).setUnlocalizedName("redstoneLight").setCreativeTab(CreativeTabs::REDSTONE));
    g_BlockRegistry.addElement(124, "lit_redstone_lamp", ( BlockRedstoneLight(true)).setHardness(0.3F).setSoundType(SoundTypes::GLASS).setUnlocalizedName("redstoneLight"));
    g_BlockRegistry.addElement(125, "double_wooden_slab", ( BlockDoubleWoodSlab()).setHardness(2.0F).setResistance(5.0F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("woodSlab"));
    g_BlockRegistry.addElement(126, "wooden_slab", ( BlockHalfWoodSlab()).setHardness(2.0F).setResistance(5.0F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("woodSlab"));
    g_BlockRegistry.addElement(127, "cocoa", ( BlockCocoa()).setHardness(0.2F).setResistance(5.0F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("cocoa"));
    //g_BlockRegistry.addElement(128, "sandstone_stairs", ( BlockStairs(block2.getDefaultState().withProperty(BlockSandStone.TYPE, BlockSandStone.EnumType.SMOOTH))).setUnlocalizedName("stairsSandStone"));
    g_BlockRegistry.addElement(129, "emerald_ore", ( BlockOre()).setHardness(3.0F).setResistance(5.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("oreEmerald"));
    g_BlockRegistry.addElement(130, "ender_chest", ( BlockEnderChest()).setHardness(22.5F).setResistance(1000.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("enderChest").setLightLevel(0.5F));
    g_BlockRegistry.addElement(131, "tripwire_hook", ( BlockTripWireHook()).setUnlocalizedName("tripWireSource"));
    g_BlockRegistry.addElement(132, "tripwire", ( BlockTripWire()).setUnlocalizedName("tripWire"));
    g_BlockRegistry.addElement(133, "emerald_block", ( Block(Materials::IRON)).setHardness(5.0F).setResistance(10.0F).setSoundType(SoundTypes::METAL).setUnlocalizedName("blockEmerald").setCreativeTab(CreativeTabs::BUILDING_BLOCKS));
    //g_BlockRegistry.addElement(134, "spruce_stairs", ( BlockStairs(block1.getDefaultState().withProperty(BlockPlanks.VARIANT, BlockPlanks.EnumType.SPRUCE))).setUnlocalizedName("stairsWoodSpruce"));
    //g_BlockRegistry.addElement(135, "birch_stairs", ( BlockStairs(block1.getDefaultState().withProperty(BlockPlanks.VARIANT, BlockPlanks.EnumType.BIRCH))).setUnlocalizedName("stairsWoodBirch"));
    //g_BlockRegistry.addElement(136, "jungle_stairs", ( BlockStairs(block1.getDefaultState().withProperty(BlockPlanks.VARIANT, BlockPlanks.EnumType.JUNGLE))).setUnlocalizedName("stairsWoodJungle"));
    g_BlockRegistry.addElement(137, "command_block", ( BlockCommandBlock()).setUnbreakable().setResistance(6000000.0F).setUnlocalizedName("commandBlock"));
    g_BlockRegistry.addElement(138, "beacon", ( BlockBeacon()).setUnlocalizedName("beacon").setLightLevel(1.0F));
    //g_BlockRegistry.addElement(139, "cobblestone_wall", ( BlockWall(block)).setUnlocalizedName("cobbleWall"));
    g_BlockRegistry.addElement(140, "flower_pot", ( BlockFlowerPot()).setHardness(0.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("flowerPot"));
    g_BlockRegistry.addElement(141, "carrots", ( BlockCarrot()).setUnlocalizedName("carrots"));
    g_BlockRegistry.addElement(142, "potatoes", ( BlockPotato()).setUnlocalizedName("potatoes"));
    g_BlockRegistry.addElement(143, "wooden_button", ( BlockButtonWood()).setHardness(0.5F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("button"));
    g_BlockRegistry.addElement(144, "skull", ( BlockSkull()).setHardness(1.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("skull"));
    g_BlockRegistry.addElement(145, "anvil", ( BlockAnvil()).setHardness(5.0F).setSoundType(SoundTypes::ANVIL).setResistance(2000.0F).setUnlocalizedName("anvil"));
    //g_BlockRegistry.addElement(146, "trapped_chest", ( BlockChest(BlockChest.Type.TRAP)).setHardness(2.5F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("chestTrap"));
    //g_BlockRegistry.addElement(147, "light_weighted_pressure_plate", ( BlockPressurePlateWeighted(Materials::IRON, 15, MapColor.GOLD)).setHardness(0.5F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("weightedPlate_light"));
    //g_BlockRegistry.addElement(148, "heavy_weighted_pressure_plate", ( BlockPressurePlateWeighted(Materials::IRON, 150)).setHardness(0.5F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("weightedPlate_heavy"));
    g_BlockRegistry.addElement(149, "unpowered_comparator", ( BlockRedstoneComparator(false)).setHardness(0.0F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("comparator").disableStats());
    g_BlockRegistry.addElement(150, "powered_comparator", ( BlockRedstoneComparator(true)).setHardness(0.0F).setLightLevel(0.625F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("comparator").disableStats());
    g_BlockRegistry.addElement(151, "daylight_detector",  BlockDaylightDetector(false));
    //g_BlockRegistry.addElement(152, "redstone_block", ( BlockCompressedPowered(Materials::IRON, MapColor.TNT)).setHardness(5.0F).setResistance(10.0F).setSoundType(SoundTypes::METAL).setUnlocalizedName("blockRedstone").setCreativeTab(CreativeTabs::REDSTONE));
    g_BlockRegistry.addElement(153, "quartz_ore", ( BlockOre()).setHardness(3.0F).setResistance(5.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("netherquartz"));
    g_BlockRegistry.addElement(154, "hopper", ( BlockHopper()).setHardness(3.0F).setResistance(8.0F).setSoundType(SoundTypes::METAL).setUnlocalizedName("hopper"));
    g_BlockRegistry.addElement(155, "quartz_block", ( BlockQuartz()).setSoundType(SoundTypes::STONE).setHardness(0.8F).setUnlocalizedName("quartzBlock"));
    //g_BlockRegistry.addElement(156, "quartz_stairs", ( BlockStairs(block11.getDefaultState().withProperty(BlockQuartz.VARIANT, BlockQuartz.EnumType.DEFAULT))).setUnlocalizedName("stairsQuartz"));
    g_BlockRegistry.addElement(157, "activator_rail", ( BlockRailPowered()).setHardness(0.7F).setSoundType(SoundTypes::METAL).setUnlocalizedName("activatorRail"));
    g_BlockRegistry.addElement(158, "dropper", ( BlockDropper()).setHardness(3.5F).setSoundType(SoundTypes::STONE).setUnlocalizedName("dropper"));
    g_BlockRegistry.addElement(159, "stained_hardened_clay", ( BlockStainedHardenedClay()).setHardness(1.25F).setResistance(7.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("clayHardenedStained"));
    g_BlockRegistry.addElement(160, "stained_glass_pane", ( BlockStainedGlassPane()).setHardness(0.3F).setSoundType(SoundTypes::GLASS).setUnlocalizedName("thinStainedGlass"));
    g_BlockRegistry.addElement(161, "leaves2", ( BlockNewLeaf()).setUnlocalizedName("leaves"));
    g_BlockRegistry.addElement(162, "log2", ( BlockNewLog()).setUnlocalizedName("log"));
    //g_BlockRegistry.addElement(163, "acacia_stairs", ( BlockStairs(block1.getDefaultState().withProperty(BlockPlanks.VARIANT, BlockPlanks.EnumType.ACACIA))).setUnlocalizedName("stairsWoodAcacia"));
    //g_BlockRegistry.addElement(164, "dark_oak_stairs", ( BlockStairs(block1.getDefaultState().withProperty(BlockPlanks.VARIANT, BlockPlanks.EnumType.DARK_OAK))).setUnlocalizedName("stairsWoodDarkOak"));
    g_BlockRegistry.addElement(165, "slime", ( BlockSlime()).setUnlocalizedName("slime").setSoundType(SoundTypes::SLIME));
    g_BlockRegistry.addElement(166, "barrier", ( BlockBarrier()).setUnlocalizedName("barrier"));
    g_BlockRegistry.addElement(167, "iron_trapdoor", ( BlockTrapDoor(Materials::IRON)).setHardness(5.0F).setSoundType(SoundTypes::METAL).setUnlocalizedName("ironTrapdoor").disableStats());
    g_BlockRegistry.addElement(168, "prismarine", ( BlockPrismarine()).setHardness(1.5F).setResistance(10.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("prismarine"));
    g_BlockRegistry.addElement(169, "sea_lantern", ( BlockSeaLantern(Materials::GLASS)).setHardness(0.3F).setSoundType(SoundTypes::GLASS).setLightLevel(1.0F).setUnlocalizedName("seaLantern"));
    g_BlockRegistry.addElement(170, "hay_block", ( BlockHay()).setHardness(0.5F).setSoundType(SoundTypes::PLANT).setUnlocalizedName("hayBlock").setCreativeTab(CreativeTabs::BUILDING_BLOCKS));
    g_BlockRegistry.addElement(171, "carpet", ( BlockCarpet()).setHardness(0.1F).setSoundType(SoundTypes::CLOTH).setUnlocalizedName("woolCarpet").setLightOpacity(0));
    g_BlockRegistry.addElement(172, "hardened_clay", ( BlockHardenedClay()).setHardness(1.25F).setResistance(7.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("clayHardened"));
    g_BlockRegistry.addElement(173, "coal_block", ( Block(Materials::ROCK)).setHardness(5.0F).setResistance(10.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("blockCoal").setCreativeTab(CreativeTabs::BUILDING_BLOCKS));
    g_BlockRegistry.addElement(174, "packed_ice", ( BlockPackedIce()).setHardness(0.5F).setSoundType(SoundTypes::GLASS).setUnlocalizedName("icePacked"));
    g_BlockRegistry.addElement(175, "double_plant",  BlockDoublePlant());
    //g_BlockRegistry.addElement(176, "standing_banner", ( BlockBanner.BlockBannerStanding()).setHardness(1.0F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("banner").disableStats());
    //g_BlockRegistry.addElement(177, "wall_banner", ( BlockBanner.BlockBannerHanging()).setHardness(1.0F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("banner").disableStats());
    g_BlockRegistry.addElement(178, "daylight_detector_inverted",  BlockDaylightDetector(true));
    g_BlockRegistry.addElement(179, "red_sandstone", ( BlockRedSandstone()).setSoundType(SoundTypes::STONE).setHardness(0.8F).setUnlocalizedName("redSandStone"));
    //g_BlockRegistry.addElement(180, "red_sandstone_stairs", ( BlockStairs(block12.getDefaultState().withProperty(BlockRedSandstone.TYPE, BlockRedSandstone.EnumType.SMOOTH))).setUnlocalizedName("stairsRedSandStone"));
    g_BlockRegistry.addElement(181, "double_stone_slab2", ( BlockDoubleStoneSlabNew()).setHardness(2.0F).setResistance(10.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("stoneSlab2"));
    g_BlockRegistry.addElement(182, "stone_slab2", ( BlockHalfStoneSlabNew()).setHardness(2.0F).setResistance(10.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("stoneSlab2"));
    //g_BlockRegistry.addElement(183, "spruce_fence_gate", ( BlockFenceGate(BlockPlanks.EnumType.SPRUCE)).setHardness(2.0F).setResistance(5.0F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("spruceFenceGate"));
    //g_BlockRegistry.addElement(184, "birch_fence_gate", ( BlockFenceGate(BlockPlanks.EnumType.BIRCH)).setHardness(2.0F).setResistance(5.0F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("birchFenceGate"));
    //g_BlockRegistry.addElement(185, "jungle_fence_gate", ( BlockFenceGate(BlockPlanks.EnumType.JUNGLE)).setHardness(2.0F).setResistance(5.0F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("jungleFenceGate"));
    //g_BlockRegistry.addElement(186, "dark_oak_fence_gate", ( BlockFenceGate(BlockPlanks.EnumType.DARK_OAK)).setHardness(2.0F).setResistance(5.0F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("darkOakFenceGate"));
    //g_BlockRegistry.addElement(187, "acacia_fence_gate", ( BlockFenceGate(BlockPlanks.EnumType.ACACIA)).setHardness(2.0F).setResistance(5.0F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("acaciaFenceGate"));
    //g_BlockRegistry.addElement(188, "spruce_fence", ( BlockFence(Materials::WOOD, BlockPlanks.EnumType.SPRUCE.getMapColor())).setHardness(2.0F).setResistance(5.0F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("spruceFence"));
    //g_BlockRegistry.addElement(189, "birch_fence", ( BlockFence(Materials::WOOD, BlockPlanks.EnumType.BIRCH.getMapColor())).setHardness(2.0F).setResistance(5.0F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("birchFence"));
    //g_BlockRegistry.addElement(190, "jungle_fence", ( BlockFence(Materials::WOOD, BlockPlanks.EnumType.JUNGLE.getMapColor())).setHardness(2.0F).setResistance(5.0F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("jungleFence"));
    //g_BlockRegistry.addElement(191, "dark_oak_fence", ( BlockFence(Materials::WOOD, BlockPlanks.EnumType.DARK_OAK.getMapColor())).setHardness(2.0F).setResistance(5.0F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("darkOakFence"));
    //g_BlockRegistry.addElement(192, "acacia_fence", ( BlockFence(Materials::WOOD, BlockPlanks.EnumType.ACACIA.getMapColor())).setHardness(2.0F).setResistance(5.0F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("acaciaFence"));
    g_BlockRegistry.addElement(193, "spruce_door", ( BlockDoor(Materials::WOOD)).setHardness(3.0F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("doorSpruce").disableStats());
    g_BlockRegistry.addElement(194, "birch_door", ( BlockDoor(Materials::WOOD)).setHardness(3.0F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("doorBirch").disableStats());
    g_BlockRegistry.addElement(195, "jungle_door", ( BlockDoor(Materials::WOOD)).setHardness(3.0F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("doorJungle").disableStats());
    g_BlockRegistry.addElement(196, "acacia_door", ( BlockDoor(Materials::WOOD)).setHardness(3.0F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("doorAcacia").disableStats());
    g_BlockRegistry.addElement(197, "dark_oak_door", ( BlockDoor(Materials::WOOD)).setHardness(3.0F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("doorDarkOak").disableStats());
    g_BlockRegistry.addElement(198, "end_rod", ( BlockEndRod()).setHardness(0.0F).setLightLevel(0.9375F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("endRod"));
    g_BlockRegistry.addElement(199, "chorus_plant", ( BlockChorusPlant()).setHardness(0.4F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("chorusPlant"));
    g_BlockRegistry.addElement(200, "chorus_flower", ( BlockChorusFlower()).setHardness(0.4F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("chorusFlower"));
    g_BlockRegistry.addElement(201, "purpur_block", ( Block(Materials::ROCK)).setHardness(1.5F).setResistance(10.0F).setSoundType(SoundTypes::STONE).setCreativeTab(CreativeTabs::BUILDING_BLOCKS).setUnlocalizedName("purpurBlock"));
    g_BlockRegistry.addElement(202, "purpur_pillar", ( BlockRotatedPillar(Materials::ROCK)).setHardness(1.5F).setResistance(10.0F).setSoundType(SoundTypes::STONE).setCreativeTab(CreativeTabs::BUILDING_BLOCKS).setUnlocalizedName("purpurPillar"));
    //g_BlockRegistry.addElement(203, "purpur_stairs", ( BlockStairs(block13.getDefaultState())).setUnlocalizedName("stairsPurpur"));
    //g_BlockRegistry.addElement(204, "purpur_double_slab", ( BlockPurpurSlab.Double()).setHardness(2.0F).setResistance(10.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("purpurSlab"));
    //g_BlockRegistry.addElement(205, "purpur_slab", ( BlockPurpurSlab.Half()).setHardness(2.0F).setResistance(10.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("purpurSlab"));
    g_BlockRegistry.addElement(206, "end_bricks", ( Block(Materials::ROCK)).setSoundType(SoundTypes::STONE).setHardness(0.8F).setCreativeTab(CreativeTabs::BUILDING_BLOCKS).setUnlocalizedName("endBricks"));
    g_BlockRegistry.addElement(207, "beetroots", ( BlockBeetroot()).setUnlocalizedName("beetroots"));
    g_BlockRegistry.addElement(208, "grass_path", ( BlockGrassPath()).setHardness(0.65F).setSoundType(SoundTypes::PLANT).setUnlocalizedName("grassPath").disableStats());
    g_BlockRegistry.addElement(209, "end_gateway", ( BlockEndGateway(Materials::PORTAL)).setHardness(-1.0F).setResistance(6000000.0F));
    g_BlockRegistry.addElement(210, "repeating_command_block", ( BlockCommandBlock()).setUnbreakable().setResistance(6000000.0F).setUnlocalizedName("repeatingCommandBlock"));
    g_BlockRegistry.addElement(211, "chain_command_block", ( BlockCommandBlock()).setUnbreakable().setResistance(6000000.0F).setUnlocalizedName("chainCommandBlock"));
    g_BlockRegistry.addElement(212, "frosted_ice", ( BlockFrostedIce()).setHardness(0.5F).setLightOpacity(3).setSoundType(SoundTypes::GLASS).setUnlocalizedName("frostedIce"));
    g_BlockRegistry.addElement(213, "magma", ( BlockMagma()).setHardness(0.5F).setSoundType(SoundTypes::STONE).setUnlocalizedName("magma"));
    g_BlockRegistry.addElement(214, "nether_wart_block", ( Block(Materials::GRASS)).setCreativeTab(CreativeTabs::BUILDING_BLOCKS).setHardness(1.0F).setSoundType(SoundTypes::WOOD).setUnlocalizedName("netherWartBlock"));
    g_BlockRegistry.addElement(215, "red_nether_brick", ( BlockNetherBrick()).setHardness(2.0F).setResistance(10.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("redNetherBrick").setCreativeTab(CreativeTabs::BUILDING_BLOCKS));
    g_BlockRegistry.addElement(216, "bone_block", ( BlockBone()).setUnlocalizedName("boneBlock"));
    g_BlockRegistry.addElement(217, "structure_void", ( BlockStructureVoid()).setUnlocalizedName("structureVoid"));
    g_BlockRegistry.addElement(218, "observer", ( BlockObserver()).setHardness(3.0F).setUnlocalizedName("observer"));
    g_BlockRegistry.addElement(219, "white_shulker_box", ( BlockShulkerBox(ENUM_DYE_COLOR_WHITE)).setHardness(2.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("shulkerBoxWhite"));
    g_BlockRegistry.addElement(220, "orange_shulker_box", ( BlockShulkerBox(ENUM_DYE_COLOR_ORANGE)).setHardness(2.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("shulkerBoxOrange"));
    g_BlockRegistry.addElement(221, "magenta_shulker_box", ( BlockShulkerBox(ENUM_DYE_COLOR_MAGENTA)).setHardness(2.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("shulkerBoxMagenta"));
    g_BlockRegistry.addElement(222, "light_blue_shulker_box", ( BlockShulkerBox(ENUM_DYE_COLOR_LIGHT_BLUE)).setHardness(2.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("shulkerBoxLightBlue"));
    g_BlockRegistry.addElement(223, "yellow_shulker_box", ( BlockShulkerBox(ENUM_DYE_COLOR_YELLOW)).setHardness(2.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("shulkerBoxYellow"));
    g_BlockRegistry.addElement(224, "lime_shulker_box", ( BlockShulkerBox(ENUM_DYE_COLOR_LIME)).setHardness(2.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("shulkerBoxLime"));
    g_BlockRegistry.addElement(225, "pink_shulker_box", ( BlockShulkerBox(ENUM_DYE_COLOR_PINK)).setHardness(2.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("shulkerBoxPink"));
    g_BlockRegistry.addElement(226, "gray_shulker_box", ( BlockShulkerBox(ENUM_DYE_COLOR_GRAY)).setHardness(2.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("shulkerBoxGray"));
    g_BlockRegistry.addElement(227, "silver_shulker_box", ( BlockShulkerBox(ENUM_DYE_COLOR_SILVER)).setHardness(2.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("shulkerBoxSilver"));
    g_BlockRegistry.addElement(228, "cyan_shulker_box", ( BlockShulkerBox(ENUM_DYE_COLOR_CYAN)).setHardness(2.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("shulkerBoxCyan"));
    g_BlockRegistry.addElement(229, "purple_shulker_box", ( BlockShulkerBox(ENUM_DYE_COLOR_PURPLE)).setHardness(2.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("shulkerBoxPurple"));
    g_BlockRegistry.addElement(230, "blue_shulker_box", ( BlockShulkerBox(ENUM_DYE_COLOR_BLUE)).setHardness(2.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("shulkerBoxBlue"));
    g_BlockRegistry.addElement(231, "brown_shulker_box", ( BlockShulkerBox(ENUM_DYE_COLOR_BROWN)).setHardness(2.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("shulkerBoxBrown"));
    g_BlockRegistry.addElement(232, "green_shulker_box", ( BlockShulkerBox(ENUM_DYE_COLOR_GREEN)).setHardness(2.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("shulkerBoxGreen"));
    g_BlockRegistry.addElement(233, "red_shulker_box", ( BlockShulkerBox(ENUM_DYE_COLOR_RED)).setHardness(2.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("shulkerBoxRed"));
    g_BlockRegistry.addElement(234, "black_shulker_box", ( BlockShulkerBox(ENUM_DYE_COLOR_BLACK)).setHardness(2.0F).setSoundType(SoundTypes::STONE).setUnlocalizedName("shulkerBoxBlack"));
    g_BlockRegistry.addElement(235, "white_glazed_terracotta",  BlockGlazedTerracotta(ENUM_DYE_COLOR_WHITE));
    g_BlockRegistry.addElement(236, "orange_glazed_terracotta",  BlockGlazedTerracotta(ENUM_DYE_COLOR_ORANGE));
    g_BlockRegistry.addElement(237, "magenta_glazed_terracotta",  BlockGlazedTerracotta(ENUM_DYE_COLOR_MAGENTA));
    g_BlockRegistry.addElement(238, "light_blue_glazed_terracotta",  BlockGlazedTerracotta(ENUM_DYE_COLOR_LIGHT_BLUE));
    g_BlockRegistry.addElement(239, "yellow_glazed_terracotta",  BlockGlazedTerracotta(ENUM_DYE_COLOR_YELLOW));
    g_BlockRegistry.addElement(240, "lime_glazed_terracotta",  BlockGlazedTerracotta(ENUM_DYE_COLOR_LIME));
    g_BlockRegistry.addElement(241, "pink_glazed_terracotta",  BlockGlazedTerracotta(ENUM_DYE_COLOR_PINK));
    g_BlockRegistry.addElement(242, "gray_glazed_terracotta",  BlockGlazedTerracotta(ENUM_DYE_COLOR_GRAY));
    g_BlockRegistry.addElement(243, "silver_glazed_terracotta",  BlockGlazedTerracotta(ENUM_DYE_COLOR_SILVER));
    g_BlockRegistry.addElement(244, "cyan_glazed_terracotta",  BlockGlazedTerracotta(ENUM_DYE_COLOR_CYAN));
    g_BlockRegistry.addElement(245, "purple_glazed_terracotta",  BlockGlazedTerracotta(ENUM_DYE_COLOR_PURPLE));
    g_BlockRegistry.addElement(246, "blue_glazed_terracotta",  BlockGlazedTerracotta(ENUM_DYE_COLOR_BLUE));
    g_BlockRegistry.addElement(247, "brown_glazed_terracotta",  BlockGlazedTerracotta(ENUM_DYE_COLOR_BROWN));
    g_BlockRegistry.addElement(248, "green_glazed_terracotta",  BlockGlazedTerracotta(ENUM_DYE_COLOR_GREEN));
    g_BlockRegistry.addElement(249, "red_glazed_terracotta",  BlockGlazedTerracotta(ENUM_DYE_COLOR_RED));
    g_BlockRegistry.addElement(250, "black_glazed_terracotta",  BlockGlazedTerracotta(ENUM_DYE_COLOR_BLACK));
    g_BlockRegistry.addElement(251, "concrete", ( BlockColored(Materials::ROCK)).setHardness(1.8F).setSoundType(SoundTypes::STONE).setUnlocalizedName("concrete"));
    g_BlockRegistry.addElement(252, "concrete_powder", ( BlockConcretePowder()).setHardness(0.5F).setSoundType(SoundTypes::SAND).setUnlocalizedName("concretePowder"));
    g_BlockRegistry.addElement(255, "structure_block", ( BlockStructure()).setUnbreakable().setResistance(6000000.0F).setUnlocalizedName("structureBlock"));
    }
};