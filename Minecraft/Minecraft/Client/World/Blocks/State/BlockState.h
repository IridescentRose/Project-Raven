#pragma once
#include "../Properties/BlockProperty.h"
#include <string>
#include <map>

template <class T>
class BlockStateBase {
public:
	BlockStateBase() {
		propertyList.clear();
	}

	inline BlockProperty getPropertyByName(std::string s) {
		if (propertyList.find(s) != propertyList.end()) {
			return propertyList[s];
		}
		else {
			return nullptr;
		}
	}

	inline void addProperty(BlockProperty prop, std::string name) {
		propertyList.emplace(name, prop);
	}

private:
	std::map <std::string, BlockProperty> propertyList;
};