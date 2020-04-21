#pragma once
#include <string>

template <class T>

class BlockProperty {
public:

	BlockProperty(T val) {
		value = val;
	}

	inline std::string getName() {
		return "default";
	}

	inline T getValue() { return value; }

	inline void setValue(T val) { value = val; }

private:
	T value;
};