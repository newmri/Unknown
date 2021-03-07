#pragma once

#define CONSOLE_LOG GET_INSTANCE(LogManager<ConsoleLogger>)

template<typename T>
class LogManager
{
	DECLARE_SINGLETON(LogManager<T>)

public:
	string MakeLog(const LogType logType, string_view logMessage, string_view file, const char* function, const size_t line);

	void Log(string_view logMessage);
	void Log(const LogType logType, string_view logMessage);

private:
	unique_ptr<Logger> logger;
};

template<typename T>
unique_ptr<LogManager<T>> LogManager<T>::instance;

template<typename T>
once_flag LogManager<T>::onceFlag;

template<typename T>
LogManager<T>& LogManager<T>::GetInstance(void)
{
	call_once(LogManager<T>::onceFlag, []()
	{
		instance.reset(new LogManager<T>);
		(*(instance.get())).Init();
	});

	return *(instance.get());
}

template<typename T>
void LogManager<T>::Init(void)
{
	logger = make_unique<T>();
}

template<typename T>
string LogManager<T>::MakeLog(const LogType logType, string_view logMessage, string_view file, const char* function, const size_t line)
{
	return logger->MakeLog(logType, logMessage, file, function, line);
}

template<typename T>
void LogManager<T>::Log(string_view logMessage)
{
	logger->Log(logMessage);
}

template<typename T>
void LogManager<T>::Log(const LogType logType, string_view logMessage)
{
	logger->Log(logType, logMessage);
}