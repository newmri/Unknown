#pragma once

class IUse
{
public:
	virtual void Use(const CREATURE_INFO& target) = 0;
};