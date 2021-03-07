#include "Global.h"

IMPLEMENT_SINGLETON(ItemManager)

void ItemManager::Init(void)
{
}

void ItemManager::Load(void)
{
	char* table = nullptr;

	size_t rows = CSV_LOAD.Load(".\\Scripts\\Item\\Item_ItemInfo.csv", table);

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

	RAW_DATA_TO_HASH_MAP(rows, table, ITEM_INFO, itemInfo, uniqueID);
}