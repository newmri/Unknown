#pragma once

class DummyManager
{
	DECLARE_SINGLETON(DummyManager)

public:
	string_view GetDummyString(void) const;

private:
	string dummyString;
};