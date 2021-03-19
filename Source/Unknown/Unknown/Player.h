#pragma once

static const size_t DEFAULT_PLAYER_INVENTORY_NUM = 10;

class Player : public Creature
{
	OVERRIDE_OBJ(Player)

public:
	Player(const CREATURE_INFO info);
};