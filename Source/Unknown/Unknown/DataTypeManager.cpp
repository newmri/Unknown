#include "Global.h"

IMPLEMENT_SINGLETON(DataTypeManager)

void DataTypeManager::Init(void)
{
	getSizeOfTypeMap.insert(ProcessingMap::value_type(GET_INT_NAME, &DataTypeManager::GetSizeOfInt));
	getSizeOfTypeMap.insert(ProcessingMap::value_type(GET_SIZE_T_NAME, &DataTypeManager::GetSizeOfSize_T));
	getSizeOfTypeMap.insert(ProcessingMap::value_type(GET_STRING_NAME, &DataTypeManager::GetSizeOfString));
}

size_t DataTypeManager::GetSizeOfInt(void)
{
	return SIZE_OF_INT;
}

size_t DataTypeManager::GetSizeOfSize_T(void)
{
	return SIZE_OF_SIZE_T;
}

size_t DataTypeManager::GetSizeOfString(void)
{
	return SIZE_OF_STRING;
}

size_t DataTypeManager::GetSizeOfType(string_view dataType)
{
	auto iter = getSizeOfTypeMap.find(dataType.data());

	if (iter != getSizeOfTypeMap.end())
		return (this->*((*iter).second))();

	return 0;
}
