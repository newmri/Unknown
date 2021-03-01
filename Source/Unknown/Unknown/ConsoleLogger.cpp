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
	cout << GET_INSTANCE(TimeManager).GetTime() << logMessage << endl;
}

void ConsoleLogger::Log(const LogType logType, string_view logMessage)
{
	MakeLog(logType, logMessage);

	cout << GET_INSTANCE(TimeManager).GetTime() << this->log << endl;
}