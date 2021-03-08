#include "Global.h"

FileLogger::FileLogger()
{
	Init();
}

FileLogger::~FileLogger()
{
    this->output.close();
}

void FileLogger::MakeFullPath(void)
{
    this->currFullPath = this->filePath + TIME_MANAGER.GetDate() + this->fileExtension;
}

void FileLogger::Init()
{
    _mkdir(filePath.c_str());

    MakeFullPath();
}

void FileLogger::UpdateFile(void)
{
    MakeFullPath();

    if (this->prevFullPath != this->currFullPath)
    {
        this->prevFullPath = this->currFullPath;

        if (this->output.is_open())
        {
            this->output.close();
        }

        this->output.open(this->currFullPath, ios::app);

        if (!this->output.is_open())
        {
            throw runtime_error(CONSOLE_LOG.MakeLog(LogType::LOG_ERROR, this->currFullPath, __FILE__, __FUNCTION__, __LINE__));
        }
    }
}

void FileLogger::Log(string_view logMessage)
{
    UpdateFile();

    this->output << TIME_MANAGER.GetTime() << this->delimiter << logMessage << endl;
}

void FileLogger::Log(const LogType logType, string_view logMessage)
{
	MakeLog(logType, logMessage);

    UpdateFile();

    this->output << TIME_MANAGER.GetTime() << this->delimiter << this->log << endl;
}