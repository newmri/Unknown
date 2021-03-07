#pragma once

#define DATA_TYPE_MANAGER GET_INSTANCE(DataTypeManager)

#define GET_INT_NAME "int"
#define GET_SIZE_T_NAME "size_t"
#define GET_FLOAT_NAME "float"
#define GET_DOUBLE_NAME "double"
#define GET_STRING_NAME "string"

#define SIZE_OF_INT sizeof(int)
#define SIZE_OF_SIZE_T sizeof(size_t)
#define SIZE_OF_FLOAT sizeof(float)
#define SIZE_OF_DOUBLE sizeof(double)
#define SIZE_OF_STRING sizeof(string)

#define CHAR_TO_INT_REF *(int*)
#define CHAR_TO_SIZE_T_REF *(size_t*)
#define CHAR_TO_FLOAT_REF *(float*)
#define CHAR_TO_DOUBLE_REF *(double*)
#define CHAR_TO_STRING_REF *(string*)

class DataTypeManager
{
	DECLARE_SINGLETON(DataTypeManager)

private:
	size_t GetSizeOfInt(void) const;
	size_t GetSizeOfSize_T(void) const;
	size_t GetSizeOfFloat(void) const;
	size_t GetSizeOfDouble(void) const;
	size_t GetSizeOfString(void) const;

public:
	size_t GetSizeOfType(string_view dataType) const;

private:
	typedef size_t(DataTypeManager::* FUNC)() const;
	typedef map<string, FUNC> ProcessingMap;
	ProcessingMap getSizeOfTypeMap;
};