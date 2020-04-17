#pragma once

enum EnumPushReaction {
	PUSH_REACTION_NORMAL,
	PUSH_REACTION_DESTROY,
	PUSH_REACTION_BLOCK,
	PUSH_REACTION_IGNORE,
	PUSH_REACTION_PUSH_ONLY
};

class Material {
public:
	Material(/*Add Map Color Data*/) {
		mobility = PUSH_REACTION_NORMAL;

		flamable = false;
		replaceable = false;
		translucent = false;
		noTool = true;
		
		isAdventureModeExempt = false;
	}

	inline bool isSolid() {
		return true;
	}
	inline bool isLiquid() {
		return false;
	}
	inline bool blocksLight() {
		return true;
	}
	inline bool blocksMovement() {
		return true;
	}
	inline bool isFlamable() {
		return flamable;
	}

	inline Material setReplaceable() {
		replaceable = true;
		return *this;
	}

	inline bool isReplaceable() {
		return replaceable;
	}

	inline bool isOpaque() {
		return translucent ? false : blocksMovement();
	}

	inline bool isToolNotRequired() {
		return noTool;
	}

	inline unsigned char getMobility() {
		return mobility;
	}

	//TODO: ADD MAP GET METADATA


	inline Material setNoPushMobility() {
		mobility = PUSH_REACTION_DESTROY;
		return *this;
	}

	inline Material setImmovableMobility() {
		mobility = PUSH_REACTION_BLOCK;
		return *this;
	}
	
	inline Material setAdventureModeExempt() {
		isAdventureModeExempt = true;
		return *this;
	}

	inline Material setRequiresTool() {
		noTool = false;
		return *this;
	}

	inline Material setBurning() {
		flamable = true;
		return *this;
	}

	inline Material setTranslucent() {
		translucent = true;
		return *this;
	}


private:
	bool flamable;
	bool replaceable;
	bool translucent;
	bool noTool;
	//TODO: ADD MAP METADATA
	//MapColor color;

	unsigned char mobility;
	bool isAdventureModeExempt;
};

class MaterialLiquid : public Material {
public:
	MaterialLiquid(/*ADD MAP COLOR*/) {
		setReplaceable();
		setNoPushMobility();
	}

	inline bool isLiquid() {
		return true;
	}

	inline bool blocksMovement() {
		return false;
	}

	inline bool isSolid() {
		return false;
	}
};

class MaterialTransparent : public Material {
public:
	MaterialTransparent(/*ADD MAP COLORS*/) {
		setReplaceable();
	}

	inline bool isSolid() {
		return false;
	}

	inline bool blocksLight() {
		return false;
	}

	inline bool blocksMovement() {
		return false;
	}
};

class MaterialPortal : public Material {
public:
	MaterialPortal(/*ADD MAP COLORS*/) {
		
	}

	inline bool isSolid() {
		return false;
	}

	inline bool blocksLight() {
		return false;
	}

	inline bool blocksMovement() {
		return false;
	}
};

class MaterialLogic : public Material {
public:
	MaterialLogic(/*ADD MAP COLORS*/) {
		setAdventureModeExempt();
	}

	inline bool isSolid() {
		return false;
	}

	inline bool blocksLight() {
		return false;
	}

	inline bool blocksMovement() {
		return false;
	}
};

class Materials {
public:

	/*STATIC MAP OF MATERIALS*/
	static Material AIR;
	static Material GRASS;
	static Material GROUND;
	static Material WOOD;
	static Material ROCK;
	static Material IRON;
	static Material ANVIL;
	static Material WATER;
	static Material LAVA;
	static Material LEAVES;
	static Material PLANTS;
	static Material VINE;
	static Material SPONGE;
	static Material CLOTH;
	static Material FIRE;
	static Material SAND;
	static Material CIRCUITS;
	static Material CARPET;
	static Material GLASS;
	static Material REDSTONE_LIGHT;
	static Material TNT;
	static Material CORAL;
	static Material ICE;
	static Material PACKED_ICE;
	static Material SNOW;

	/** The material for crafted snow. */
	static Material CRAFTED_SNOW;
	static Material CACTUS;
	static Material CLAY;
	static Material GOURD;
	static Material DRAGON_EGG;
	static Material PORTAL;
	static Material CAKE;
	static Material WEB;

	/** Pistons' material. */
	static Material PISTON;
	static Material BARRIER;
	static Material STRUCTURE_VOID;
};