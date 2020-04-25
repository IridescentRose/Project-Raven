#pragma once
#include "BlockSoundEvent.h"

class SoundType {
public:
	SoundType() {

	}
	SoundType(float v, float p, BlockSoundEvent bS, BlockSoundEvent sS, BlockSoundEvent pS, BlockSoundEvent hS, BlockSoundEvent fS) {
		volume = v;
		pitch = p;
		breakSound = bS;
		stepSound = sS;
		placeSound = pS;
		hitSound = hS;
		fallSound = fS;
	}

	inline float getPitch() { return pitch; }
	inline float getVolume() { return volume; }

	inline BlockSoundEvent getStepSound() { return stepSound; }
	inline BlockSoundEvent getPlaceSound() { return placeSound; }
	inline BlockSoundEvent getFallSound() { return fallSound; }

	float pitch;
	float volume;
private:
	BlockSoundEvent breakSound;
	BlockSoundEvent placeSound;
	BlockSoundEvent stepSound;
	BlockSoundEvent hitSound;
	BlockSoundEvent fallSound;
};

class SoundTypes {
public:
	static SoundType WOOD	;
	static SoundType GROUND	;
	static SoundType PLANT	;
	static SoundType STONE	;
	static SoundType METAL	;
	static SoundType GLASS	;
	static SoundType CLOTH	;
	static SoundType SAND	;
	static SoundType SNOW	;
	static SoundType LADDER	;
	static SoundType ANVIL	;
	static SoundType SLIME	;
};