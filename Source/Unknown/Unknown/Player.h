#pragma once

class Player : public Creature
{
	OVERRIDE_OBJ_DELETE_DEFAULT_CONSTRUCTOR(Player)

public:
	Player(const CREATURE_INFO info);
};