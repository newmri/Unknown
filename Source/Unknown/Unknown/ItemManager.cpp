#include "Global.h"

IMPLEMENT_SINGLETON(ItemManager)

void ItemManager::Init(void)
{
	createItemMap.insert(CreateItemMap::value_type(ItemTypeStr[static_cast<size_t>(ItemType::USE)], &ItemManager::CreateUsableItem));
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
	CSV_LOAD_AND_TO_HAS_MAP(".\\Scripts\\Item\\Item_BasicAddStat.csv", ITEM_BASIC_ADD_STAT, itemBasicAddStat, index);
	CSV_LOAD_AND_TO_HAS_MAP(".\\Scripts\\Item\\Item_BasicMulStat.csv", ITEM_BASIC_MUL_STAT, itemBasicMulStat, index);
}

optional<unique_ptr<Item>> ItemManager::CreateUsableItem(const CREATURE_INFO& owner, const size_t uniqueID, const size_t count, const TIME_VALUE limitTime) const
{
	return make_unique<UsableItem>(owner, uniqueID, count, limitTime);
}

optional<unique_ptr<Item>> ItemManager::CreateItem(const CREATURE_INFO& owner, const size_t uniqueID, const size_t count) const
{
	auto itemInfoIter = itemInfo.find(uniqueID);

	if (itemInfoIter != itemInfo.end())
	{
		auto createItemiter = createItemMap.find(itemInfoIter->second->type);

		if (createItemiter != createItemMap.end())
		{
			return (this->*((*createItemiter).second))(owner, uniqueID, count, TIME_MANAGER.GetEndSeconds(itemInfoIter->second->limitTime));
		}
	}

	LOG.Log(LOG.MakeLog(LogType::LOG_ERROR, uniqueIDError + to_string(uniqueID) + " \t", __FILE__, __FUNCTION__, __LINE__));

	return nullopt;
}