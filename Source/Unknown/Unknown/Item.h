#pragma once

class Item : Obj
{
	OVERRIDE_OBJ_DELETE_DEFAULT_CONSTRUCTOR(Item)

public:
	Item(const size_t uniqueID, const size_t count = 1);

private:
	size_t uniqueID, count;
};