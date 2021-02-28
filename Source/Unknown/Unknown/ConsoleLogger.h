#pragma once

class ConsoleLogger : public Logger
{
	OVERRIDE_OBJ(ConsoleLogger)

public:
	virtual void Log(string_view logMessage) override;
	virtual void Log(const LogType logType, string_view logMessage) override;
};