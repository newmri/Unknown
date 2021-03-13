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
	size_t limitTime;
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
	int hp;
	int mp;
	int attackDamage;
	int magicDamage;
	int strength;
	int dexterity;
	int intelligence;
	int luck;
	int critical;
} ITEM_BASIC_STAT;

#pragma pack(pop)