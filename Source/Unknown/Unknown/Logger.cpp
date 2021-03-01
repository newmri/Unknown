#include "Global.h"

Logger::Logger()
{
	Init();
}

Logger::~Logger()
{

}

void Logger::Init()
{
	this->log = GET_INSTANCE(DummyManager).GetDummyString();
}

void Logger::MakeLog(const LogType logType)
{
	if (LogType::LOG_INFO == logType)
		this->log = "[LOG_INFO]\t";

	else if (LogType::LOG_ERROR == logType)
		this->log = "[ERROR]\t";
}

void Logger::MakeLog(const LogType logType, string_view logMessage)
{
	MakeLog(logType);

	this->log.append(logMessage);
}

string Logger::MakeLog(const LogType logType, string_view logMessage, string_view file, const char* function, const size_t line)
{
	MakeLog(logType, logMessage);

	this->stringStream.str(GET_INSTANCE(DummyManager).GetDummyString().data());

	this->stringStream << this->log;
	this->stringStream << logMessage << "\t";
	this->stringStream << file << "\t";
	this->stringStream << function << "\t";
	this->stringStream << line << "\t";

	return this->stringStream.str();
}