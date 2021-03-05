#pragma once

#define GET_INT_NAME "int"
#define GET_SIZE_T_NAME "size_t"
#define GET_STRING_NAME "string"

#define SIZE_OF_INT sizeof(int)
#define SIZE_OF_SIZE_T sizeof(size_t)
#define SIZE_OF_STRING sizeof(string)

#define CHAR_TO_INT_REF *(int*)
#define CHAR_TO_SIZE_T_REF *(size_t*)
#define CHAR_TO_STRING_REF *(string*)

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