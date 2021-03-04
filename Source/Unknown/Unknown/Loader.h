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
	void Parse(string& in, unique_ptr<string[]>& dataTypes, char* out, const size_t& columns);
	void Parse(string& in, string_view dataType, char* out);

private:
	string Parse(string& in);
	void Parse(string& in, int& out);
	void Parse(string& in, long& out);
	void Parse(string& in, long long& out);
	void Parse(string& in, unsigned long& out);
	void Parse(string& in, unsigned long long& out);
	void Parse(string& in, float& out);
	void Parse(string& in, double& out);
	void Parse(string& in, long double& out);

protected:
	void Parse(unique_ptr<string[]>& dataTypes, string& strForParse, const size_t& columns);
	void Parse(string& in, string& out);

protected:
	string delimiter;

private:
	string logStart, logEnd;
};