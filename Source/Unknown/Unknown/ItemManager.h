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

private:
	optional<unique_ptr<Item>> CreateUsableItem(const CREATURE_INFO& owner, const size_t uniqueID, const size_t count, const TIME_VALUE limitTime) const;

public:
	optional<unique_ptr<Item>> CreateItem(const CREATURE_INFO& owner, const size_t uniqueID, const size_t count = 1) const;

private:
	unordered_map<size_t, unique_ptr<ITEM_INFO>> itemInfo;
	unordered_map<size_t, unique_ptr<ITEM_BASIC_ADD_STAT>> itemBasicAddStat;
	unordered_map<size_t, unique_ptr<ITEM_BASIC_MUL_STAT>> itemBasicMulStat;

private:
	typedef optional<unique_ptr<Item>>(ItemManager::* FUNC)(const CREATURE_INFO& owner, const size_t uniqueID, const size_t count, const TIME_VALUE timeLimit) const;
	typedef map<string_view, FUNC> CreateItemMap;
	CreateItemMap createItemMap;

	string uniqueIDError = "uniqueID ";
};