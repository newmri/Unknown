#pragma once

class UsableItem : Item
{
	OVERRIDE_OBJ_DELETE_DEFAULT_CONSTRUCTOR(UsableItem)

public:
	UsableItem(const size_t uniqueID, const size_t count, const size_t limitTime);
};