#pragma once

#pragma pack(push, 1)

typedef struct
{
	long long hp;
	int mp;
	long long attackDamage;
	long long magicDamage;
	int strength;
	int dexterity;
	int intelligence;
	int luck;
	int critical;
}BASIC_ADD_STAT;

typedef struct
{
	float hp;
	float mp;
	float attackDamage;
	float magicDamage;
	float strength;
	float dexterity;
	float intelligence;
	float luck;
	float critical;
}BASIC_MUL_STAT;

#pragma pack(pop)