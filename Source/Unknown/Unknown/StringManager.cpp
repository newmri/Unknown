#include "Global.h"

IMPLEMENT_SINGLETON(StringManager)

void StringManager::Init(void)
{
	
}

string StringManager::ReplaceAll(string_view source, string_view from, string_view to)
{
	string newString;
	newString.reserve(source.length());

	string::size_type findPos = 0, lastPos = 0;

	while (string::npos != (findPos = source.find(from, lastPos)))
	{
		newString.append(source, lastPos, findPos - lastPos);
		newString += to;
		lastPos = findPos + from.length();
	}

	newString += source.substr(lastPos);

	return newString;
}