#pragma once

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
	TIME_VALUE limitTime;
	size_t basicAddStatIndex;
	int basicMulStatIndex;
	int isCashItem;
	size_t buyPrice, sellPrice;
	size_t maxStackNum;
	size_t storage;
} ITEM_INFO;

typedef struct
{
	size_t index;
	float gradeUpMulValue;
	BASIC_ADD_STAT stat;
} ITEM_BASIC_ADD_STAT;

typedef struct
{
	size_t index;
	float gradeUpMulValue;
	BASIC_MUL_STAT stat;
} ITEM_BASIC_MUL_STAT;

#pragma pack(pop)