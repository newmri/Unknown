#pragma once

class Item : public Obj
{
	OVERRIDE_OBJ_DELETE_DEFAULT_CONSTRUCTOR(Item)

public:
	Item(const CREATURE_INFO& owner, const size_t uniqueID, const size_t count, const size_t limitTime);

protected:
	CREATURE_INFO owner;
	size_t uniqueID, count, limitTime;
};