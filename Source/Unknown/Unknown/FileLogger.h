#pragma once

class FileLogger : public Logger
{
	OVERRIDE_OBJ(FileLogger)

private:
	void MakeFullPath(void);
	void UpdateFile(void);

public:
	virtual void Log(string_view logMessage) override;
	virtual void Log(const LogType logType, string_view logMessage) override;

private:
	string prevFullPath, currFullPath;
	string filePath = ".\\DebugLog\\";
	string fileExtension = ".log";
	ofstream output;
};