#pragma once

enum class LogType : size_t
{
	LOG_INFO,
	LOG_ERROR,
	LOG_TYPE_NUM
};

static constexpr size_t DEFAULT_LOG_SIZE = 1024;

class Logger : public Obj
{
	OVERRIDE_OBJ(Logger)

private:
	void MakeLog(const LogType logType);

protected:
	void MakeLog(const LogType logType, string_view logMessage);

public:
	string MakeLog(const LogType logType, string_view logMessage, string_view file, const char* function, const size_t line);

public:
	virtual void Log(string_view logMessage) = 0;
	virtual void Log(const LogType logType, string_view logMessage) = 0;

protected:
	string delimiter = "\t";
	string log;

private:
	string logHeader[static_cast<size_t>(LogType::LOG_TYPE_NUM)] = { "[LOG_INFO]", "[LOG_ERROR]" };

	ostringstream output;
};