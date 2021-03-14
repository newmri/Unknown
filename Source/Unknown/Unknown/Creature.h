#pragma once

enum class CreatureType : size_t
{
	NONE,
	PLAYER,
	MONSTER,
	CREATURE_TYPE_NUM
};

#pragma pack(push, 1)

typedef struct _CREATURE_INFO_
{
	_CREATURE_INFO_() = delete;
	_CREATURE_INFO_(const CreatureType type, const size_t uniqueID) : type(type), uniqueID(uniqueID) {}

	CreatureType type;
	size_t uniqueID;
} CREATURE_INFO;

#pragma pack(pop)

class Creature : public Obj
{
	OVERRIDE_OBJ_DELETE_DEFAULT_CONSTRUCTOR(Creature)

public:
	Creature(const CREATURE_INFO info);

protected:
	CREATURE_INFO info;
};