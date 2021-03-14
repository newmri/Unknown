#pragma once

enum class ItemType : size_t
{
	USE,
	ITEM_TYPE_NUM
};

static string_view ItemTypeStr[] =
{ "Use", "Equip"};

class Item : public Obj
{
	OVERRIDE_OBJ_DELETE_DEFAULT_CONSTRUCTOR(Item)

public:
	Item(const CREATURE_INFO& owner, const size_t uniqueID, const size_t count, const TIME_VALUE limitTime);

protected:
	CREATURE_INFO owner;
	size_t uniqueID, count;
	TIME_VALUE limitTime;
};