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
	this->log = DUMMY_MANAGER.GetDummyString();
}

void Logger::MakeLog(const LogType logType)
{
	if (LogType::LOG_INFO == logType)
		this->log = "[LOG_INFO]" + this->delimiter;

	else if (LogType::LOG_ERROR == logType)
		this->log = "[ERROR]" + this->delimiter;
}

void Logger::MakeLog(const LogType logType, string_view logMessage)
{
	MakeLog(logType);

	this->log.append(logMessage);
}

string Logger::MakeLog(const LogType logType, string_view logMessage, string_view file, const char* function, const size_t line)
{
	MakeLog(logType, logMessage);

	this->stringStream.str(DUMMY_MANAGER.GetDummyString().data());

	this->stringStream << this->log;
	this->stringStream << logMessage << this->delimiter;
	this->stringStream << file << this->delimiter;
	this->stringStream << function << this->delimiter;
	this->stringStream << line << this->delimiter;

	return this->stringStream.str();
}