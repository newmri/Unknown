#pragma once

#define CSV_LOAD GET_INSTANCE(ScriptLoadManager<CSVLoader>)

template<typename T>
class ScriptLoadManager
{
	DECLARE_SINGLETON(ScriptLoadManager<T>)

public:
	size_t Load(string_view filePath, char*& out);

private:
	unique_ptr<Loader> loader;
};

template<typename T>
unique_ptr<ScriptLoadManager<T>> ScriptLoadManager<T>::instance;

template<typename T>
once_flag ScriptLoadManager<T>::onceFlag;

template<typename T>
ScriptLoadManager<T>& ScriptLoadManager<T>::GetInstance(void)
{
	call_once(ScriptLoadManager<T>::onceFlag, []()
	{
		instance.reset(new ScriptLoadManager<T>);
		(*(instance.get())).Init();
	});

	return *(instance.get());
}

template<typename T>
void ScriptLoadManager<T>::Init(void)
{
	loader = make_unique<T>();
}

template<typename T>
size_t ScriptLoadManager<T>::Load(string_view filePath, char*& out)
{
	return loader->Load(filePath, out);
}