#pragma once

class UsableItem : public Item, public IUse
{
	OVERRIDE_OBJ_DELETE_DEFAULT_CONSTRUCTOR(UsableItem)

public:
	UsableItem(const CREATURE_INFO& owner, const size_t uniqueID, const size_t count, const TIME_VALUE limitTime);

public:
	virtual void Use(const CREATURE_INFO& target) override;
};