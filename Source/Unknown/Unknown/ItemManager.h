#pragma once

#include "ItemInfo.h"
#include <utility>

#define ITEM_MANAGER GET_INSTANCE(ItemManager)

class Item;

class ItemManager
{
	DECLARE_SINGLETON(ItemManager)

public:
	void Load(void);

public:
	optional<unique_ptr<Item>> CreateItem(const size_t uniqueID, const size_t count = 1);

private:
	unordered_map<size_t, unique_ptr<ITEM_INFO>> itemInfo;
	unordered_map<size_t, unique_ptr<ITEM_BASIC_STAT>> itemBasicAddStat, itemBasicMulStat;

};