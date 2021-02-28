#include "Global.h"

string Logger::MakeLog(const LogType logType)
{
	string str;

	if (LogType::LOG_INFO == logType)
		str = "[LOG_INFO]\t";

	else if (LogType::LOG_ERROR == logType)
		str = "[ERROR]\t";

	return str;
}

string Logger::MakeLog(const LogType logType, string_view logMessage)
{
	string log = MakeLog(logType);

	log.append(logMessage);

	return log;
}

string Logger::MakeLog(const LogType logType, string_view logMessage, string_view file, const char* function, const size_t line)
{
	stringstream stringStream;

	stringStream << MakeLog(logType);

	stringStream << logMessage << "\t";
	stringStream << file << "\t";
	stringStream << function << "\t";
	stringStream << line << "\t";

	return stringStream.str();
}