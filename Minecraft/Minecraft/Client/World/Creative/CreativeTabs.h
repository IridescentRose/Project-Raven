#pragma once
#include <string>

class CreativeTab {
public:
	CreativeTab() {

	}
	CreativeTab(char idx, std::string lbl) {
		index = idx;
		label = lbl;
		textureName = "items.png";
		needsScroll = true;
		drawTitle = true;
	}

	inline CreativeTab setBackgroundImageName(std::string str) {
		textureName = str;
		return *this;
	}

	inline CreativeTab setNoTitle() {
		drawTitle = false;
		return *this;
	}

	inline CreativeTab setNoScrollbar() {
		needsScroll = false;
		return *this;
	}

private:
	char index;
	std::string label;
	std::string textureName;
	bool needsScroll;
	bool drawTitle;
};

class CreativeTabs {
public:
    static CreativeTab BUILDING_BLOCKS;
    static CreativeTab DECORATIONS;
    static CreativeTab REDSTONE;
    static CreativeTab TRANSPORTATION;
	static CreativeTab MISC;
    static CreativeTab SEARCH;
	static CreativeTab FOOD;
	static CreativeTab TOOLS;
	static CreativeTab COMBAT;
    static CreativeTab BREWING;
    static CreativeTab MATERIALS;
	static CreativeTab HOTBAR;
    static CreativeTab INVENTORY;
};