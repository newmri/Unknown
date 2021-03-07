#include "Global.h"

IMPLEMENT_SINGLETON(ItemManager)

void ItemManager::Init(void)
{
}

void ItemManager::Load(void)
{
	char* table = nullptr;

	size_t rows = GET_INSTANCE(ScriptLoadManager<CSVLoader>).Load(".\\Scripts\\Item\\Item_ItemInfo.csv", table);
	
	ITEM_INFO* pData = reinterpret_cast<ITEM_INFO*>(table);

	for (size_t i = 0; i < rows; ++i)
	{
		cout << pData[i].name << endl;
	}

	SAFE_DELETE(rows, table);
}