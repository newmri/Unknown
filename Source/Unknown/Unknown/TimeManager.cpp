#include "Global.h"

IMPLEMENT_SINGLETON(TimeManager)

void TimeManager::Init(void)
{

}

TIME_POINT TimeManager::GetNow(void) const
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

	this->time = "Time has been passed (sec)\t";
	this->time.append(to_string(this->sec.count()));

	CONSOLE_LOG.Log(LogType::LOG_INFO, this->time);
}

string TimeManager::GetTime(void)
{
	this->now = chrono::system_clock::to_time_t(GetNow());

	localtime_s(&this->date, &this->now);

	strftime(timeBuffer, timeBufferSize, this->format.c_str(), &this->date);

	this->time = timeBuffer;

	// MDd에서 크래시 발생
	//this->message.str(GET_INSTANCE(DummyManager).GetDummyString().data());
	//this->message = put_time(&this->date, format.c_str());
	//this->message << put_time(&this->date, format.c_str()) << "\t";
	
	return this->time;
}
