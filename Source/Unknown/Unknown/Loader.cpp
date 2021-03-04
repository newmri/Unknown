#include "Global.h"

Loader::Loader()
{
	Init();
}

Loader::~Loader()
{

}

void Loader::Init()
{
	this->logStart = GET_INSTANCE(DummyManager).GetDummyString();
	this->logEnd = GET_INSTANCE(DummyManager).GetDummyString();
}

void Loader::LogLoadingStart(string_view filePath)
{
	this->logStart = "[";
	this->logStart.append(filePath);
	this->logStart.append(" is loading...]");

	GET_INSTANCE(LogManager<ConsoleLogger>).Log(LogType::LOG_INFO, this->logStart);
}

void Loader::LogLoadingEnd(string_view filePath)
{
	this->logEnd = "[";

	this->logEnd.append(filePath);
	this->logEnd.append(" is loaded...]");

	GET_INSTANCE(LogManager<ConsoleLogger>).Log(LogType::LOG_INFO, this->logEnd);
}

void Loader::Parse(string& in, unique_ptr<string[]>& dataTypes, char* out, const size_t& columns)
{
	for (size_t i = 0; i < columns; ++i)
	{
		Parse(in, dataTypes[i], out);
		out += GET_INSTANCE(DataTypeManager).GetSizeOfType(dataTypes[i]);
	}
}

void Loader::Parse(string& in, string_view dataType, char* out)
{
	if (dataType == GET_INT_NAME)
	{
		Parse(in, CHAR_P_TO_INT_REF out);
	}

	else if (dataType == GET_SIZE_T_NAME)
	{
		Parse(in, CHAR_P_TO_SIZE_T_REF out);
	}

	else if (dataType == GET_STRING_NAME)
	{
		Parse(in, CHAR_P_TO_STRING_REF out);
	}
}

string Loader::Parse(string& in)
{
	string str(GET_INSTANCE(DummyManager).GetDummyString().data());
	string::size_type findPos = 0;

	findPos = in.find(this->delimiter);

	for (string::size_type pos = 0; pos < findPos; ++pos)
	{
		str.push_back(in[pos]);
	}

	in.erase(0, findPos + 1);

	return str;
}

void Loader::Parse(string& in, int& out)
{
	out = stoi(Parse(in));
}

void Loader::Parse(string& in, long& out)
{
	out = stol(Parse(in));
}

void Loader::Parse(string& in, long long& out)
{
	out = stoll(Parse(in));
}

void Loader::Parse(string& in, unsigned long& out)
{
	out = stoul(Parse(in));
}

void Loader::Parse(string& in, unsigned long long& out)
{
	out = stoull(Parse(in));
}

void Loader::Parse(string& in, float& out)
{
	out = stof(Parse(in));
}

void Loader::Parse(string& in, double& out)
{
	out = stod(Parse(in));
}

void Loader::Parse(string& in, long double& out)
{
	out = stold(Parse(in));
}

void Loader::Parse(unique_ptr<string[]>& dataTypes, string& strForParse, const size_t& columns)
{
	dataTypes = make_unique<string[]>(columns);

	for (size_t i = 0; i < columns; ++i)
	{
		Parse(strForParse, dataTypes[i]);
	}

	dataTypes[columns - 1] = GET_INSTANCE(StringManager).ReplaceAll(dataTypes[columns - 1], "\n", "");
}

void Loader::Parse(string& in, string& out)
{
	out = Parse(in);
}

