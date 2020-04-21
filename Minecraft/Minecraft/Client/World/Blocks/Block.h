#pragma once
#include "Sounds/SoundType.h"
#include "../Items/Item.h"
#include "Materials/Material.h"
#include "State/BlockState.h"
#include "../AABB/AABB.h"
#include "Physics/BlockAABB.h"

struct BlockMetaData{
    unsigned short id;
    unsigned char meta;
};

class Block{
public:
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

    inline bool getRandomTick() {
        return randomTicking;
    }

    inline bool hasTileEntity() {
        return isBlockContainer;
    }

    inline AABB getBoundingBox() {
        return BlockFullAABB;
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
    
    inline void setUnlocalizedName(std::string n) {
        name = n;
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

protected:
    BlockMetaData id;

    bool fullBlock;
    //How much blocks
    unsigned char lightingOpacity;

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