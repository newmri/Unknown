#include "Global.h"

int main(void)
{
#if _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif // _DEBUG

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

	return 0;
}