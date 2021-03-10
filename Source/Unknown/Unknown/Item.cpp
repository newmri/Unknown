#include "Global.h"

Item::~Item()
{

}

void Item::Init(void)
{

}

Item::Item(const size_t uniqueID, const size_t count) : uniqueID(uniqueID), count(count)
{
}
