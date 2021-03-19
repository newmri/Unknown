#pragma once

#define CREATURE_MANAGER GET_INSTANCE(CreatureManager)

static const size_t MAX_PLAYER_NUM = 1024;

class CreatureManager
{
	DECLARE_SINGLETON(CreatureManager)

public:
	void EnterPlayer(void);

private:
	std::array<Player, MAX_PLAYER_NUM> player;
	size_t currPlayerNum = 0;
};