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


void Loader::Parse(void)
{
	this->parseStringStream.str(GET_INSTANCE(DummyManager).GetDummyString().data());

	string str;

	ITEM_INFO itemInfo;

	string strForParse;

	while (getline(this->loadStringStream, str, this->delimiter.front()))
	{
		this->parseStringStream << str << this->delimiter;

		if (string::npos != str.find('\n'))
		{
			strForParse = this->parseStringStream.str();

			Parse(strForParse, itemInfo.uniqueID);
			Parse(strForParse, itemInfo.name);
			Parse(strForParse, itemInfo.type);
			Parse(strForParse, itemInfo.euipParts);
			Parse(strForParse, itemInfo.usableMinLevel);
			Parse(strForParse, itemInfo.usableMaxLevel);
			Parse(strForParse, itemInfo.job);
			Parse(strForParse, itemInfo.grade);
			Parse(strForParse, itemInfo.basicAddStatIndex);
			Parse(strForParse, itemInfo.basicMulStatIndex);
			Parse(strForParse, itemInfo.isCashItem);
			Parse(strForParse, itemInfo.buyPrice);
			Parse(strForParse, itemInfo.sellPrice);
			Parse(strForParse, itemInfo.maxStackNum);
			Parse(strForParse, itemInfo.storage);

			this->parseStringStream.str(string());
		}
	}
}

string Loader::Parse(string& in)
{
	string str;
	string::size_type findPos = 0;

	findPos = in.find(this->delimiter);

	for (string::size_type pos = 0; pos < findPos; ++pos)
	{
		str.push_back(in[pos]);
	}

	in.erase(0, findPos + 1);

	return str;
}

void Loader::Parse(string& in, bool& out)
{
	out = stoi(Parse(in));
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

void Loader::Parse(string& in, string& out)
{
	out = Parse(in);
}

