#include "Global.h"

CSVLoader::CSVLoader()
{
	Init();
}

CSVLoader::~CSVLoader()
{

}

void CSVLoader::Init()
{
	this->delimiter = ",";
}

void CSVLoader::Load(void)
{
	this->loadStringStream.str(GET_INSTANCE(DummyManager).GetDummyString().data());

	string str(GET_INSTANCE(DummyManager).GetDummyString().data());
	string log(GET_INSTANCE(DummyManager).GetDummyString().data());

	size_t newLinePos = 0;
	size_t spacePos = 0;

	this->rowNum = 0;

	//this->stringStream << this->fileStream.rdbuf();

	while (!this->fileStream.eof())
	{
		getline(fileStream, str, this->delimiter.front());

		str.append(this->delimiter);

		newLinePos = str.find('\n');

		if (string::npos != newLinePos)
		{
			log.append(str, 0, newLinePos);

			this->loadStringStream << log;
			this->loadStringStream << "\n,";

			GET_INSTANCE(LogManager<ConsoleLogger>).Log(LogType::LOG_INFO, log);

			log = "";
			log.append(str, newLinePos + 1);

			++this->rowNum;
		}

		else log += str;
	}

	this->fileStream.close();
}

void CSVLoader::Load(string_view filePath)
{
	this->fileStream.open(string(filePath).c_str(), ios::in);

	if (!this->fileStream.is_open())
	{
		throw invalid_argument(GET_INSTANCE(LogManager<ConsoleLogger>).MakeLog(LogType::LOG_ERROR, filePath, __FILE__, __FUNCTION__, __LINE__));
	}

	LogLoadingStart(filePath);

	Load();

	Parse();

	LogLoadingEnd(filePath);

}
