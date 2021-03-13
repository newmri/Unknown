#include "Global.h"

IMPLEMENT_SINGLETON(ItemManager)

void ItemManager::Init(void)
{
}

void ItemManager::Load(void)
{
	/*
	// 메모리 정렬
	size_t size = rows * sizeof(ITEM_INFO);

	ITEM_INFO* alignedMemory = nullptr;

	if (align(alignof(ITEM_INFO), sizeof(ITEM_INFO), (void*&)table, size))
	{
		alignedMemory = reinterpret_cast<ITEM_INFO*>(table);
	}

	ITEM_INFO* pData = new(alignedMemory) ITEM_INFO();
	*/


	CSV_LOAD_AND_TO_HAS_MAP(".\\Scripts\\Item\\Item_ItemInfo.csv", ITEM_INFO, itemInfo, uniqueID);
	CSV_LOAD_AND_TO_HAS_MAP(".\\Scripts\\Item\\Item_BasicAddStat.csv", ITEM_BASIC_STAT, itemBasicAddStat, index);
	CSV_LOAD_AND_TO_HAS_MAP(".\\Scripts\\Item\\Item_BasicMulStat.csv", ITEM_BASIC_STAT, itemBasicMulStat, index);

}

optional<unique_ptr<Item>> ItemManager::CreateItem(const size_t uniqueID, const size_t count)
{
	//auto iter = itemInfo.find(uniqueID);

	//if (iter != itemInfo.end())
	//{
	//	unique_ptr<Item> derived = make_unique<Item>(uniqueID, count, 0);

	//	return move(derived);
	//}

	return nullopt;
}
