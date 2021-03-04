#pragma once

class DataTypeManager
{
	DECLARE_SINGLETON(DataTypeManager)

private:
	size_t GetSizeOfInt(void);
	size_t GetSizeOfSize_T(void);
	size_t GetSizeOfString(void);

public:
	size_t GetSizeOfType(string_view dataType);

private:
	typedef size_t(DataTypeManager::* FUNC)();
	typedef map<string, FUNC> ProcessingMap;
	ProcessingMap getSizeOfTypeMap;
};