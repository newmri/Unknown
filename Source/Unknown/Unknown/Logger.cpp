#include "Global.h"

Logger::Logger()
{
	Init();
}

Logger::~Logger()
{

}

void Logger::Init(void)
{
	this->log = DUMMY_MANAGER.GetDummyString();
}

void Logger::MakeLog(const LogType logType)
{
	this->log = this->logHeader[static_cast<size_t>(logType)] + this->delimiter;
}

void Logger::MakeLog(const LogType logType, string_view logMessage)
{
	MakeLog(logType);
	this->log.append(logMessage);
}

string Logger::MakeLog(const LogType logType, string_view logMessage, string_view file, const char* function, const size_t line)
{
	MakeLog(logType, logMessage);

	this->output.str(DUMMY_MANAGER.GetDummyString().data());

	this->output << this->log;
	this->output << file << this->delimiter;
	this->output << function << this->delimiter;
	this->output << line << this->delimiter;

	return this->output.str();
}