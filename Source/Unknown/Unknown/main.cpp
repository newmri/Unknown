#include "Global.h"

int main(void)
{
#if _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif // _DEBUG

	TIME_MANAGER.Start();

	ALL_LOG(LogType::LOG_INFO, "main is running");

	try
	{
		ITEM_MANAGER.Load();
		CREATURE_MANAGER.EnterPlayer();
	}

	catch (exception e)
	{
		LOG.Log(e.what());
	}

	TIME_MANAGER.End();

	return 0;
}