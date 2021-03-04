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
	string str(GET_INSTANCE(DummyManager).GetDummyString().data());
	string log(GET_INSTANCE(DummyManager).GetDummyString().data());
	string strForParse(GET_INSTANCE(DummyManager).GetDummyString().data());

	string::size_type newLinePos = 0;

	size_t rows = 0, columns = 0;

	ITEM_INFO itemInfo;

	unique_ptr<string[]> dataTypes;

	while (!this->fileStream.eof())
	{
		getline(fileStream, str, this->delimiter.front());

		str.append(this->delimiter);

		newLinePos = str.find('\n');

		if (0 == rows)
			++columns;

		if (string::npos != newLinePos)
		{
			char* p = (char*)&itemInfo;

			log.append(str, 0, newLinePos);

			strForParse = log;

			strForParse.append("\n,");

			// 첫번 째 row에는 데이터 타입이 있음
			if (0 == rows)
			{
				Parse(dataTypes, strForParse, columns);
			}

			else
			{
				Parse(strForParse, dataTypes, p, columns);
			}

			GET_INSTANCE(LogManager<ConsoleLogger>).Log(LogType::LOG_INFO, log);

			log = "";
			log.append(str, newLinePos + 1);

			++rows;
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

	LogLoadingEnd(filePath);

}
