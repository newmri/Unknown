#include "Global.h"

int main(void)
{
	try
	{
		GET_INSTANCE(ScriptLoadManager<CSVLoader>).Load(".\\Scripts\\Item\\Item_ItemInfo.csv");
	}

	catch(exception e)
	{
		cout << e.what() << endl;
	}
}