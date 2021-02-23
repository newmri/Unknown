#pragma once

class ScriptLoader : public Loader
{
	OVERRIDE_OBJ(ScriptLoader)

public:
	void Load(string_view filePath) override;
};