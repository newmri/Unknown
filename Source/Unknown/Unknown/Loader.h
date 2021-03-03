#pragma once

class Loader : public Obj
{
	OVERRIDE_OBJ(Loader)

private:
	virtual void Load(void) = 0;

public:
	virtual void Load(string_view filePath) = 0;

protected:
	void LogLoadingStart(string_view filePath);
	void LogLoadingEnd(string_view filePath);

protected:
	void Parse(void);

private:
	string Parse(string& in);

public:
	void Parse(string& in, bool& out);
	void Parse(string& in, int& out);
	void Parse(string& in, long& out);
	void Parse(string& in, long long& out);
	void Parse(string& in, unsigned long& out);
	void Parse(string& in, unsigned long long& out);
	void Parse(string& in, float& out);
	void Parse(string& in, double& out);
	void Parse(string& in, long double& out);
	void Parse(string& in, string& out);

protected:
	size_t rowNum;
	string delimiter;
	stringstream loadStringStream;
	ostringstream parseStringStream;

private:
	string logStart, logEnd;

};