#pragma once

class Item : Obj
{
	ABSTRACT_OBJ(Item)

public:
	Item(const size_t uniqueID, const size_t count, const size_t limitTime);

protected:
	size_t uniqueID, count, limitTime;
};