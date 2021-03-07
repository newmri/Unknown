#include "Global.h"

int main(void)
{
#if _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif // _DEBUG

	TIME_MANAGER.Start();

	CONSOLE_LOG.Log(LogType::LOG_INFO, "main is running");

	try
	{
		GET_INSTANCE(ItemManager).Load();
	}

	catch (exception e)
	{
		CONSOLE_LOG.Log(e.what());
	}

	TIME_MANAGER.End();

	return 0;
}