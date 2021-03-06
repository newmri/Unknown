#include "Global.h"

int main(void)
{
	GET_INSTANCE(TimeManager).Start();

	GET_INSTANCE(LogManager<ConsoleLogger>).Log(LogType::LOG_INFO, "main is running");

	try
	{
		GET_INSTANCE(ItemManager).Load();
	}

	catch (exception e)
	{
		GET_INSTANCE(LogManager<ConsoleLogger>).Log(e.what());
	}


	GET_INSTANCE(TimeManager).End();

}