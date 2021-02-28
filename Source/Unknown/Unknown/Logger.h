#pragma once

enum class LogType
{
	LOG_INFO,
	LOG_ERROR
};

class Logger : public Obj
{
	ABSTRACT_OBJ(Logger)

protected:
	string MakeLog(const LogType logType);
	string MakeLog(const LogType logType, string_view logMessage);

public:
	string MakeLog(const LogType logType, string_view logMessage, string_view file, const char* function, const size_t line);

public:
	virtual void Log(string_view logMessage) = 0;
	virtual void Log(const LogType logType, string_view logMessage) = 0;
};