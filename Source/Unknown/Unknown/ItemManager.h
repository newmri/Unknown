#pragma once

#pragma pack(push, 1)
typedef struct
{
	size_t uniqueID;
	string name;
	string type;
	string euipParts;
	size_t usableMinLevel, usableMaxLevel;
	string job;
	string grade;
	size_t basicAddStatIndex;
	int basicMulStatIndex;
	int isCashItem;
	size_t buyPrice, sellPrice;
	size_t maxStackNum;
	size_t storage;
} ITEM_INFO;
#pragma pack(pop)

class ItemManager
{
	DECLARE_SINGLETON(ItemManager)

public:
	void Load(void);

private:
	unordered_map<size_t, unique_ptr<ITEM_INFO>> itemInfo;
};