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

}

void CSVLoader::Load(void)
{
	this->stringStream.str(GET_INSTANCE(DummyManager).GetDummyString().data());

	string str(GET_INSTANCE(DummyManager).GetDummyString().data());
	string log(GET_INSTANCE(DummyManager).GetDummyString().data());

	size_t newLinePos = 0;

	this->rowNum = 0;

	while (!this->fileStream.eof())
	{
		getline(fileStream, str, ',');

		str.append(",");

		this->stringStream << str;

		newLinePos = str.find('\n');

		if (string::npos != newLinePos)
		{
			log.append(str, 0, newLinePos);

			GET_INSTANCE(LogManager<ConsoleLogger>).Log(LogType::LOG_INFO, log);

			log = "";
			log.append(str, newLinePos + 1);

			++this->rowNum;
		}

		else log += str;
	}

	this->fileStream.close();
}

LOAD_DATA CSVLoader::Load(string_view filePath)
{
	this->fileStream.open(string(filePath).c_str(), ios::in);

	if (!this->fileStream.is_open())
	{
		throw invalid_argument(GET_INSTANCE(LogManager<ConsoleLogger>).MakeLog(LogType::LOG_ERROR, filePath, __FILE__, __FUNCTION__, __LINE__));
	}

	LogLoadingStart(filePath);

	Load();

	LogLoadingEnd(filePath);

	return make_pair(this->rowNum, this->stringStream.str());
}
