#include "Global.h"

Loader::Loader()
{
	Init();
}

Loader::~Loader()
{

}

void Loader::Init()
{
	this->logStart = GET_INSTANCE(DummyManager).GetDummyString();
	this->logEnd = GET_INSTANCE(DummyManager).GetDummyString();
}

void Loader::LogLoadingStart(string_view filePath)
{
	this->logStart = "[";

	this->logStart.append(filePath);
	this->logStart.append(" is loading...]");

	GET_INSTANCE(LogManager<ConsoleLogger>).Log(LogType::LOG_INFO, this->logStart);
}

void Loader::LogLoadingEnd(string_view filePath)
{
	this->logEnd = "[";

	this->logEnd.append(filePath);
	this->logEnd.append(" is loaded...]");

	GET_INSTANCE(LogManager<ConsoleLogger>).Log(LogType::LOG_INFO, this->logEnd);
}
