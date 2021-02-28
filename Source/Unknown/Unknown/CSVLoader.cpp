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

void CSVLoader::Load(string_view filePath)
{
	string str;
	fstream fileStream;

	fileStream.open(string(filePath).c_str(), ios::in);

	if (!fileStream.is_open())
	{
		throw invalid_argument(GET_INSTANCE(LogManager<ConsoleLogger>).MakeLog(LogType::LOG_ERROR, filePath, __FILE__, __FUNCTION__, __LINE__));
	}

	while (!fileStream.eof())
	{
		getline(fileStream, str, ',');
		cout << str << endl;
	}

	fileStream.close();
}