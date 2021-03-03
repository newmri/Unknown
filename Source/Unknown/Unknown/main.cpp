#include "Global.h"

int main(void)
{

	GET_INSTANCE(TimeManager).Start();

	GET_INSTANCE(LogManager<ConsoleLogger>).Log(LogType::LOG_INFO, "main is running");

	try
	{
		GET_INSTANCE(ScriptLoadManager<CSVLoader>).Load(".\\Scripts\\Item\\Item_ItemInfo.csv");
	}

	catch (exception e)
	{
		GET_INSTANCE(LogManager<ConsoleLogger>).Log(e.what());
	}

	GET_INSTANCE(TimeManager).End();

}