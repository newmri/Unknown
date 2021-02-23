#pragma once

class Loader : public Obj
{
	ABSTRACT_OBJ(Loader)

public:
	virtual void Load(string_view filePath) = 0;
};