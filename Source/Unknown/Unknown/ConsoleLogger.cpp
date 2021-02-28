#include "Global.h"

ConsoleLogger::ConsoleLogger()
{
	Init();
}

ConsoleLogger::~ConsoleLogger()
{

}

void ConsoleLogger::Init()
{

}

void ConsoleLogger::Log(string_view logMessage)
{
	cout << logMessage << endl;
}

void ConsoleLogger::Log(const LogType logType, string_view logMessage)
{
	cout << MakeLog(logType, logMessage) << endl;
}