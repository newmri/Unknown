#include "Global.h"

UsableItem::~UsableItem()
{

}

void UsableItem::Init(void)
{

}

UsableItem::UsableItem(const CREATURE_INFO& owner, const size_t uniqueID, const size_t count, const TIME_VALUE limitTime) : Item(owner, uniqueID, count, limitTime)
{

}

void UsableItem::Use(const CREATURE_INFO& target)
{
}
