#pragma once

class ScriptLoadManager
{
	DECLARE_SINGLETON(ScriptLoadManager)

public:
	void Load(string_view filePath);

private:
	unique_ptr<Loader> loader;
};