#include "Material.h"

/*STATIC MAP OF MATERIALS*/
Material Materials::AIR = MaterialTransparent();
Material Materials::GRASS = Material();
Material Materials::GROUND = Material();
Material Materials::WOOD = (Material()).setBurning();
Material Materials::ROCK = (Material()).setRequiresTool();
Material Materials::IRON = (Material()).setRequiresTool();
Material Materials::ANVIL = (Material()).setRequiresTool().setImmovableMobility();
Material Materials::WATER = (MaterialLiquid()).setNoPushMobility();
Material Materials::LAVA = (MaterialLiquid()).setNoPushMobility();
Material Materials::LEAVES = (Material()).setBurning().setTranslucent().setNoPushMobility();
Material Materials::PLANTS = (MaterialLogic()).setNoPushMobility();
Material Materials::VINE = (MaterialLogic()).setBurning().setNoPushMobility().setReplaceable();
Material Materials::SPONGE = Material();
Material Materials::CLOTH = (Material()).setBurning();
Material Materials::FIRE = (MaterialTransparent()).setNoPushMobility();
Material Materials::SAND = Material();
Material Materials::CIRCUITS = (MaterialLogic()).setNoPushMobility();
Material Materials::CARPET = (MaterialLogic()).setBurning();
Material Materials::GLASS = (Material()).setTranslucent().setAdventureModeExempt();
Material Materials::REDSTONE_LIGHT = (Material()).setAdventureModeExempt();
Material Materials::TNT = (Material()).setBurning().setTranslucent();
Material Materials::CORAL = (Material()).setNoPushMobility();
Material Materials::ICE = (Material()).setTranslucent().setAdventureModeExempt();
Material Materials::PACKED_ICE = (Material()).setAdventureModeExempt();
Material Materials::SNOW = (MaterialLogic()).setReplaceable().setTranslucent().setRequiresTool().setNoPushMobility();

/** The material for crafted snow. */
Material Materials::CRAFTED_SNOW = (Material().setRequiresTool());
Material Materials::CACTUS = (Material()).setTranslucent().setNoPushMobility();
Material Materials::CLAY = Material();
Material Materials::GOURD = (Material()).setNoPushMobility();
Material Materials::DRAGON_EGG = (Material()).setNoPushMobility();
Material Materials::PORTAL = (MaterialPortal()).setImmovableMobility();
Material Materials::CAKE = (Material()).setNoPushMobility();
Material Materials::WEB = (Material()).setRequiresTool().setNoPushMobility();
				 
/** Pistons' material. */
Material Materials::PISTON = (Material()).setImmovableMobility();
Material Materials::BARRIER = (Material()).setRequiresTool().setImmovableMobility();
Material Materials::STRUCTURE_VOID = MaterialTransparent();