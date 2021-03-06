#include "Global.h"

IMPLEMENT_SINGLETON(DummyManager)

void DummyManager::Init(void)
{
	dummyString = string(DEFAULT_LOG_SIZE, '\0');
}

string_view DummyManager::GetDummyString(void) const
{
	return dummyString;
}