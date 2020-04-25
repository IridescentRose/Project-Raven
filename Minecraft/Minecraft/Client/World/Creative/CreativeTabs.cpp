#include "CreativeTabs.h"

CreativeTab CreativeTabs::BUILDING_BLOCKS =  CreativeTab(0, "buildingBlocks");
CreativeTab CreativeTabs::DECORATIONS =  CreativeTab(1, "decorations");
CreativeTab CreativeTabs::REDSTONE =  CreativeTab(2, "redstone");
CreativeTab CreativeTabs::TRANSPORTATION =  CreativeTab(3, "transportation");
CreativeTab CreativeTabs::MISC =  CreativeTab(6, "misc");
CreativeTab CreativeTabs::SEARCH = ( CreativeTab(5, "search")).setBackgroundImageName("item_search.png");
CreativeTab CreativeTabs::FOOD =  CreativeTab(7, "food");
CreativeTab CreativeTabs::TOOLS = ( CreativeTab(8, "tools"));
CreativeTab CreativeTabs::COMBAT = ( CreativeTab(9, "combat"));
CreativeTab CreativeTabs::BREWING =  CreativeTab(10, "brewing");
CreativeTab CreativeTabs::MATERIALS = CreativeTabs::MISC;
CreativeTab CreativeTabs::HOTBAR =  CreativeTab(4, "hotbar");
CreativeTab CreativeTabs::INVENTORY = ( CreativeTab(11, "inventory")).setBackgroundImageName("inventory.png").setNoScrollbar().setNoTitle();