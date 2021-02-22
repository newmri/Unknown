#pragma once

template <typename T>
class Loader : public Obj
{
	ABSTRACT_OBJ(Loader<T>)

public:
	virtual void Load(T& loadData) = 0;
};