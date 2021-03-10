#pragma once

#include "ItemInfo.h"

#define ITEM_MANAGER GET_INSTANCE(ItemManager)

class ItemManager
{
	DECLARE_SINGLETON(ItemManager)

public:
	void Load(void);

public:
	
private:
	unordered_map<size_t, unique_ptr<ITEM_INFO>> itemInfo;
	unordered_map<size_t, unique_ptr<ITEM_BASIC_STAT>> itemBasicAddStat, itemBasicMulStat;

};