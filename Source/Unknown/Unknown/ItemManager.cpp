#include "Global.h"

IMPLEMENT_SINGLETON(ItemManager)

void ItemManager::Init(void)
{
}

void ItemManager::Load(void)
{
	ITEM_INFO table;
	GET_INSTANCE(ScriptLoadManager<CSVLoader>).Load(".\\Scripts\\Item\\Item_ItemInfo.csv", (char*)&table);

}