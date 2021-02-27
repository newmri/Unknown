#pragma once

#include "Global.h"

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
		string errorString = __FILE__;

		throw invalid_argument(errorString);
	}


	while (!fileStream.eof())
	{
		getline(fileStream, str, ',');
		cout << str << endl;
	}

	fileStream.close();


}