#pragma once

#define DUMMY_MANAGER GET_INSTANCE(DummyManager)

class DummyManager
{
	DECLARE_SINGLETON(DummyManager)

public:
	string_view GetDummyString(void) const;

private:
	string dummyString;
};