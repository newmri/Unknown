#include "Global.h"

IMPLEMENT_SINGLETON(ScriptLoadManager)

void ScriptLoadManager::Init(void)
{
	loader = make_unique<ScriptLoader>();
}

void ScriptLoadManager::Load(string_view filePath)
{
	loader->Load(filePath);
}