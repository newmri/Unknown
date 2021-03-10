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

void CSVLoader::PreLoad(string_view filePath, char*& out)
{
	Loader::PreLoad(filePath, out);

	string str(DUMMY_MANAGER.GetDummyString().data());
	string log(DUMMY_MANAGER.GetDummyString().data());
	string strForParse(DUMMY_MANAGER.GetDummyString().data());

	string::size_type newLinePos = 0;

	while (!this->fileStream.eof())
	{
		getline(this->fileStream, str, this->delimiter.front());

		str.append(this->delimiter);

		newLinePos = str.find('\n');

		if (0 == this->rows)
			++this->columns;

		if (string::npos != newLinePos)
		{
			log.append(str, 0, newLinePos);

			strForParse = log;

			strForParse.append("\n,");

			if (0 == rows)
			{
				ParseDataTypesAndCalRowSize(strForParse);
			}

			LOG.Log(LogType::LOG_INFO, log);

			log = "";
			log.append(str, newLinePos + 1);

			++this->rows;
		}

		else log += str;
	}

	this->rows -= 1;

	out = new char[this->rowSize * (this->rows)]{};

	Rewind();
}

void CSVLoader::Load(char*& out)
{
	string str(DUMMY_MANAGER.GetDummyString().data());
	string strForParse(DUMMY_MANAGER.GetDummyString().data());

	string::size_type newLinePos = 0;

	size_t rows = 0;

	while (!this->fileStream.eof())
	{
		getline(this->fileStream, str, this->delimiter.front());

		str.append(this->delimiter);

		newLinePos = str.find('\n');

		if (string::npos != newLinePos)
		{
			strForParse.append(str, 0, newLinePos);
			strForParse.append("\n,");

			if (0 != rows)
			{
				Parse(strForParse, out + (this->rowSize * (rows - 1)));
			}

			strForParse = "";
			strForParse.append(str, newLinePos + 1);

			++rows;
		}

		else strForParse += str;
	}

	Close();
}

size_t CSVLoader::Load(string_view filePath, char*& out)
{
	PreLoad(filePath, out);

	Load(out);

	LogLoadingEnd();

	return this->rows;
}
