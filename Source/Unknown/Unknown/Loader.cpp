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
	this->logStart = DUMMY_MANAGER.GetDummyString();
	this->logEnd = DUMMY_MANAGER.GetDummyString();
}

void Loader::PreLoad(string_view filePath, char*& out)
{
	this->filePath = filePath;
	this->dataTypes.reset();

	Open();

	LogLoadingStart();
}

void Loader::Open()
{
	this->fileStream.open(string(this->filePath).c_str(), ios::in);

	if (!this->fileStream.is_open())
	{
		throw invalid_argument(CONSOLE_LOG.MakeLog(LogType::LOG_ERROR, filePath, __FILE__, __FUNCTION__, __LINE__));
	}
}

void Loader::Rewind(void)
{
	this->fileStream.seekg(0, std::ios::beg);
}

void Loader::Close(void)
{
	this->fileStream.close();
}

void Loader::LogLoadingStart(void)
{
	this->logStart = "[";
	this->logStart.append(this->filePath);
	this->logStart.append(" is loading...]");

	CONSOLE_LOG.Log(LogType::LOG_INFO, this->logStart);
}

void Loader::LogLoadingEnd(void)
{
	this->logEnd = "[";

	this->logEnd.append(this->filePath);
	this->logEnd.append(" is loaded...]");

	CONSOLE_LOG.Log(LogType::LOG_INFO, this->logEnd);
}

void Loader::Parse(string& in, char* out)
{
	for (size_t i = 0; i < this->columns; ++i)
	{
		Parse(in, i, out);
		out += DATA_TYPE_MANAGER.GetSizeOfType(this->dataTypes[i]);
	}
}

void Loader::Parse(string& in, const size_t dataTypeIndex, char* out)
{
#if _DEBUG
	unsigned int hashCode = HashCode(this->dataTypes[dataTypeIndex].c_str());

	if (hashCode == HashCode(GET_INT_NAME))
	{
		Parse(in, CHAR_TO_INT_REF out);
	}

	else if (hashCode == HashCode(GET_SIZE_T_NAME))
	{
		Parse(in, CHAR_TO_SIZE_T_REF out);
	}

	else if (hashCode == HashCode(GET_STRING_NAME))
	{
		Parse(in, CHAR_TO_STRING_REF out);
	}
#else

	switch (HashCode(this->dataTypes[dataTypeIndex].c_str()))
	{
	case HashCode(GET_INT_NAME):
		Parse(in, CHAR_TO_INT_REF out);
		break;
	case HashCode(GET_SIZE_T_NAME):
		Parse(in, CHAR_TO_SIZE_T_REF out);
		break;
	case HashCode(GET_STRING_NAME):
		Parse(in, CHAR_TO_STRING_REF out);
		break;
	}
#endif // _DEBUG
}

string Loader::Parse(string& in)
{
	string str(DUMMY_MANAGER.GetDummyString().data());
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

void Loader::ParseDataTypesAndCalRowSize(string& strForParse)
{
	this->dataTypes = make_unique<string[]>(this->columns);

	for (size_t i = 0; i < this->columns; ++i)
	{
		this->dataTypes[i] = Parse(strForParse);
	}

	size_t lastIndex = this->columns - 1;

	this->dataTypes[lastIndex] = GET_INSTANCE(StringManager).ReplaceAll(this->dataTypes[lastIndex], "\n", "");

	this->rowSize = 0;

	for (size_t i = 0; i < this->columns; ++i)
	{
		this->rowSize += DATA_TYPE_MANAGER.GetSizeOfType(this->dataTypes[i]);
	}
}

void Loader::Parse(string& in, string& out)
{
	out = Parse(in);
}

