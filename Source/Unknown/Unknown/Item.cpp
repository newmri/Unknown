#include "Global.h"

Item::~Item()
{

}

void Item::Init(void)
{

}

Item::Item(const CREATURE_INFO& owner, const size_t uniqueID, const size_t count, const size_t limitTime) : owner(owner), uniqueID(uniqueID), count(count), limitTime(limitTime)
{
}
