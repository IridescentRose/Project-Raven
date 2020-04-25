#pragma once
#include "Block.h"

class BlockAir : public Block {
};

class BlockStone : public Block {
};

class BlockGrass : public Block {
};

class BlockDirt : public Block {
};

class BlockPlanks : public Block {
};

class BlockSapling : public Block {
};

class BlockEmptyDrops : public Block {
public:
    BlockEmptyDrops(Material mat) : Block(mat) {

    }
};

class BlockDynamicLiquid : public Block {
public:
    BlockDynamicLiquid(Material mat) : Block(mat) {

    }
};

class BlockStaticLiquid : public Block {
public:
    BlockStaticLiquid(Material mat) : Block(mat) {

    }
};
class BlockSand : public Block {
};
class BlockGravel : public Block {
};
class BlockOre : public Block {
};
class BlockOldLog : public Block {
};
class BlockOldLeaf : public Block {
};
class BlockSponge : public Block {
};
class BlockGlass : public Block {
public:
    BlockGlass(Material mat) : Block(mat) {

    }
};
class BlockDispenser : public Block {
};
class BlockSandStone : public Block {
};
class BlockNote : public Block {
};
class BlockBed : public Block {
};
class BlockRailPowered : public Block {
};
class BlockRailDetector : public Block {
};
class BlockPistonBase : public Block {
};
class BlockWeb : public Block {
};
class BlockTallGrass : public Block {
};
class BlockDeadBush : public Block {
};
class BlockPistonExtension : public Block {
};

class BlockColored : public Block {
public:
    BlockColored(Material mat) : Block(mat) {

    }
};
class BlockPistonMoving : public Block {
};
class BlockYellowFlower : public Block {
};
class BlockRedFlower : public Block {
};
class BlockMushroom : public Block {
};
class BlockDoubleStoneSlab : public Block {
};
class BlockHalfStoneSlab : public Block {
};
class BlockTNT : public Block {
};
class BlockBookshelf : public Block {
};
class BlockObsidian : public Block {
};
class BlockTorch : public Block {
};
class BlockFire : public Block {
};
class BlockMobSpawner : public Block {
};
class BlockStairs : public Block {
};
class BlockChest : public Block {
};
class BlockRedstoneWire : public Block {
};
class BlockWorkbench : public Block {
};
class BlockCrops : public Block {
};
class BlockFarmland : public Block {
};
class BlockFurnace : public Block {
public:
    BlockFurnace(bool lit) {

    }
};
class BlockStandingSign : public Block {
};
class BlockDoor : public Block {
public:
    BlockDoor(Material mat) : Block(mat) {

    }
};
class BlockLadder : public Block {
};
class BlockRail : public Block {
};
class BlockWallSign : public Block {
};
class BlockLever : public Block {
};
class BlockRedstoneOre : public Block {
public:
    BlockRedstoneOre(bool lit) {

    }
};
class BlockRedstoneTorch : public Block {
public:
    BlockRedstoneTorch(bool lit) {

    }
};
/*
class BlockPressurePlate : public Block {
};
*/
class BlockButtonStone : public Block {
};
class BlockSnow : public Block {
};
class BlockIce : public Block {
};
class BlockSnowBlock : public Block {
};
class BlockCactus : public Block {
};
class BlockClay : public Block {
};
class BlockReed : public Block {
};
class BlockJukebox : public Block {
};
/*class BlockFence : public Block {
};*/
class BlockPumpkin : public Block {
};
class BlockNetherrack : public Block {
};
class BlockSoulSand : public Block {
};
class BlockGlowstone : public Block {
public:
    BlockGlowstone(Material mat) : Block(mat) {

    }
};
class BlockPortal : public Block {
};
class BlockCake : public Block {
};
class BlockRedstoneRepeater : public Block {
public:
    BlockRedstoneRepeater(bool lit) {

    }
};
class BlockStainedGlass : public Block {
public:
    BlockStainedGlass(Material mat) : Block(mat) {

    }
};
class BlockTrapDoor : public Block {
public:
    BlockTrapDoor(Material mat) : Block(mat) {

    }
};
class BlockSilverfish : public Block {
};
class BlockStoneBrick : public Block {
};
class BlockMelon : public Block {
};
class BlockVine : public Block {
};
class BlockMycelium : public Block {
};
class BlockLilyPad : public Block {
};
class BlockNetherBrick : public Block {
};
class BlockNetherWart : public Block {
};
class BlockEnchantmentTable : public Block {
};
class BlockBrewingStand : public Block {
};
class BlockCauldron : public Block {
};
class BlockEndPortal : public Block {
};
class BlockEndPortalFrame : public Block {
};
class BlockDragonEgg : public Block {
};
class BlockRedstoneLight : public Block {
public:
    BlockRedstoneLight(bool lit) {

    }
};
class BlockDoubleWoodSlab : public Block {
};
class BlockHalfWoodSlab : public Block {
};
class BlockCocoa : public Block {
};
class BlockEnderChest : public Block {
};
class BlockTripWireHook : public Block {
};
class BlockTripWire : public Block {
};
class BlockCommandBlock : public Block {
};
class BlockBeacon : public Block {
};
class BlockWall : public Block {
};
class BlockFlowerPot : public Block {
};
class BlockCarrot : public Block {
};
class BlockPotato : public Block {
};
class BlockSkull : public Block {
};
class BlockAnvil : public Block {
};
class BlockButtonWood : public Block {
};
class BlockRedstoneComparator : public Block {
public:
    BlockRedstoneComparator(bool lit) {

    }
};
class BlockDaylightDetector : public Block {
public:
    BlockDaylightDetector(bool lit) {

    }
};
class BlockHopper : public Block {
};
class BlockQuartz : public Block {
};
class BlockDropper : public Block {
};
class BlockStainedHardenedClay : public Block {
};
class BlockStainedGlassPane : public Block {
};
class BlockNewLeaf : public Block {
};
class BlockNewLog : public Block {
};
class BlockSlime : public Block {
};
class BlockBarrier : public Block {
};
class BlockPrismarine : public Block {
};
class BlockSeaLantern : public Block {
public:
    BlockSeaLantern(Material mat) : Block(mat) {

    }
};
class BlockDoublePlant : public Block {
};
class BlockCarpet : public Block {
};
class BlockHardenedClay : public Block {
};
class BlockHay : public Block {
};
class BlockRedSandstone : public Block {
};
class BlockPackedIce : public Block {
};
class BlockDoubleStoneSlabNew : public Block {
};
class BlockHalfStoneSlabNew : public Block {
};
class BlockEndRod : public Block {
};
class BlockChorusPlant : public Block {
};
class BlockChorusFlower : public Block {
};
class BlockRotatedPillar : public Block {
public:
    BlockRotatedPillar(Material mat) : Block(mat) {

    }
};
class BlockBeetroot : public Block {
};
class BlockGrassPath : public Block {
};
class BlockEndGateway : public Block {
public:
    BlockEndGateway(Material mat) : Block(mat) {

    }
};
class BlockFrostedIce : public Block {
};
class BlockMagma : public Block {
};
class BlockBone : public Block {
};
class BlockStructureVoid : public Block {
};
class BlockObserver : public Block {
};
class BlockConcretePowder : public Block {
};
class BlockStructure : public Block {
};
class BlockShulkerBox : public Block {
public:
    BlockShulkerBox(char c){

    }
};
class BlockGlazedTerracotta : public Block {
public:
    BlockGlazedTerracotta(char c) {

    }
};