#pragma once

#include "Define.h"
#include "Macro.h"
#include "Include.h"

#pragma pack(push, 1)
typedef struct
{
	size_t uniqueID;
	string name;
	string type;
	string euipParts;
	size_t usableMinLevel, usableMaxLevel;
	string job;
	string grade;
	size_t basicAddStatIndex;
	int basicMulStatIndex;
	int isCashItem;
	size_t buyPrice, sellPrice;
	size_t maxStackNum;
	size_t storage;
} ITEM_INFO;
#pragma pack(pop)