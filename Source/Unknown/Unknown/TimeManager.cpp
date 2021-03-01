#include "Global.h"

IMPLEMENT_SINGLETON(TimeManager)

void TimeManager::Init(void)
{
}

TIME_POINT TimeManager::GetNow(void)
{
	return chrono::system_clock::now();
}


void TimeManager::Start(void)
{
	this->start = GetNow();
}

void TimeManager::End(void)
{
	this->end = GetNow();

	this->sec = this->end - this->start;

	this->message.str(GET_INSTANCE(DummyManager).GetDummyString().data());

	this->message << "Time has been passed (sec)\t";
	this->message << this->sec.count() << endl;

	GET_INSTANCE(LogManager<ConsoleLogger>).Log(LogType::LOG_INFO, this->message.str());
}

string TimeManager::GetTime(void)
{
	this->now = chrono::system_clock::to_time_t(GetNow());

	localtime_s(&this->date, &this->now);

	this->message.str(GET_INSTANCE(DummyManager).GetDummyString().data());

	this->message << put_time(&this->date, "%F %T") << "\t";

	return this->message.str();
}
