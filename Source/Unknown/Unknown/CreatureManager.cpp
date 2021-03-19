#include "Global.h"

IMPLEMENT_SINGLETON(CreatureManager)

void CreatureManager::Init(void)
{
	
}

void CreatureManager::EnterPlayer(void)
{
	if (MAX_PLAYER_NUM == currPlayerNum)
	{
		LOG.Log(LOG.MakeLog(LogType::LOG_ERROR, "Player is Full \t", __FILE__, __FUNCTION__, __LINE__));
		return;
	}

	player[currPlayerNum] = Player(CREATURE_INFO(CreatureType::PLAYER, currPlayerNum++));
}