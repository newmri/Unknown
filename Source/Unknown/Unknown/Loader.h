#pragma once

class Loader : public Obj
{
	OVERRIDE_OBJ(Loader)

protected:
	virtual void PreLoad(string_view filePath, char*& out);

private:
	virtual void Load(char*& out) = 0;

public:
	virtual size_t Load(string_view filePath, char*& out) = 0;

protected:
	void Open(void);
	void Rewind(void);
	void Close(void);
	void LogLoadingStart(void);
	void LogLoadingEnd(void);
	void Parse(string& in, char* out);
	void Parse(string& in, const size_t dataTypeIndex, char* out);

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
	void ParseDataTypesAndCalRowSize(string& strForParse);
	void Parse(string& in, string& out);

protected:
	string delimiter;
	string_view filePath;
	fstream fileStream;
	size_t rows = 0, columns = 0;
	size_t rowSize = 0;
	unique_ptr<string[]> dataTypes;
private:
	string logStart, logEnd;
};