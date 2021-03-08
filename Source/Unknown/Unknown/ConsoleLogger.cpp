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
	cout << TIME_MANAGER.GetDateTime() << this->delimiter << logMessage << endl;
}

void ConsoleLogger::Log(const LogType logType, string_view logMessage)
{
	MakeLog(logType, logMessage);

	cout << TIME_MANAGER.GetDateTime() << this->delimiter << this->log << endl;
}