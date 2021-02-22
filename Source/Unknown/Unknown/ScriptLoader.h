#pragma once

template <typename T>
class ScriptLoader : public Loader<string> 
{
	OVERRIDE_OBJ(ScriptLoader<T>)

public:
	void Load(T& loadData) override;
};