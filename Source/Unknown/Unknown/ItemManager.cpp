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

optional<shared_ptr<ITEM_INFO>> ItemManager::GetItemInfo(const size_t uniqueID) const
{
	auto iter = itemInfo.find(uniqueID);

	if (iter != itemInfo.end())
	{
		return iter->second;
	}

	return nullopt;
}

optional<shared_ptr<ITEM_BASIC_ADD_STAT>> ItemManager::GetItemBasicAddStatInfo(const size_t uniqueID) const
{
	auto info = GetItemInfo(uniqueID);

	if (info.has_value())
	{
		if (NO_DATA != (*info)->basicAddStatIndex)
		{
			auto iter = itemBasicAddStat.find((*info)->basicAddStatIndex);

			if (iter != itemBasicAddStat.end())
			{
				return iter->second;
			}
		}

		return nullopt;
	}

	LOG.Log(LOG.MakeLog(LogType::LOG_ERROR, uniqueIDError + to_string(uniqueID) + " \t", __FILE__, __FUNCTION__, __LINE__));

	return nullopt;
}

optional<shared_ptr<ITEM_BASIC_MUL_STAT>> ItemManager::GetItemBasicMulStatInfo(const size_t uniqueID) const
{
	auto info = GetItemInfo(uniqueID);

	if (info.has_value())
	{
		if (NO_DATA != (*info)->basicMulStatIndex)
		{
			auto iter = itemBasicMulStat.find((*info)->basicMulStatIndex);

			if (iter != itemBasicMulStat.end())
			{
				return iter->second;
			}
		}

		return nullopt;
	}

	LOG.Log(LOG.MakeLog(LogType::LOG_ERROR, uniqueIDError + to_string(uniqueID) + " \t", __FILE__, __FUNCTION__, __LINE__));

	return nullopt;
}

optional<unique_ptr<Item>> ItemManager::CreateItem(const CREATURE_INFO& owner, const size_t uniqueID, const size_t count) const
{
	auto info = GetItemInfo(uniqueID);

	if (info.has_value())
	{
		auto iter = createItemMap.find((*info)->type);

		if (iter != createItemMap.end())
		{
			return (this->*((*iter).second))(owner, uniqueID, count, TIME_MANAGER.GetEndSeconds((*info)->limitTime));
		}
	}

	LOG.Log(LOG.MakeLog(LogType::LOG_ERROR, uniqueIDError + to_string(uniqueID) + " \t", __FILE__, __FUNCTION__, __LINE__));

	return nullopt;
}