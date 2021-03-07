#pragma once

#define STRING_MANAGER GET_INSTANCE(StringManager)

class StringManager
{
	DECLARE_SINGLETON(StringManager)

public:
	string ReplaceAll(string_view source, string_view from, string_view to);
};