#pragma once

using LOAD_DATA = pair<size_t, string_view>;

class Loader : public Obj
{
	OVERRIDE_OBJ(Loader)

private:
	virtual void Load(void) = 0;

public:
	virtual LOAD_DATA Load(string_view filePath) = 0;

protected:
	void LogLoadingStart(string_view filePath);
	void LogLoadingEnd(string_view filePath);

protected:
	size_t dataNum;

private:
	string logStart, logEnd;
};