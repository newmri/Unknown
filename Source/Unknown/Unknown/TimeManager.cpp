#include "Global.h"

IMPLEMENT_SINGLETON(TimeManager)

void TimeManager::Init(void)
{

}

TIME_POINT TimeManager::GetNow(void) const
{
	return chrono::system_clock::now();
}

TIME_VALUE TimeManager::GetNowSeconds(void) const
{
	return chrono::duration_cast<chrono::seconds>(GetNow().time_since_epoch()).count();
}

TIME_VALUE TimeManager::GetEndSeconds(size_t limitTime) const
{
	TIME_VALUE endSeconds = limitTime;

	if (endSeconds)
		endSeconds += GetNowSeconds();

	return endSeconds;
}

void TimeManager::Start(void)
{
	this->start = GetNow();
}

void TimeManager::End(void)
{
	this->end = GetNow();

	this->sec = this->end - this->start;

	this->time = timeEndMessage + to_string(this->sec.count());

	LOG.Log(LogType::LOG_INFO, this->time);
}

void TimeManager::GetTime(string_view format)
{
	this->now = chrono::system_clock::to_time_t(GetNow());

	localtime_s(&this->date, &this->now);

	strftime(this->timeBuffer, this->timeBufferSize, format.data(), &this->date);

	this->time = timeBuffer;
}

string TimeManager::GetDate(void)
{
	GetTime(this->dateFormat);
	return this->time;
}

string TimeManager::GetTime(void)
{
	GetTime(this->timeFormat);
	return this->time;
}

string TimeManager::GetDateTime(void)
{
	GetTime(this->dateTimeFormat);
	return this->time;

	// MDd에서 크래시 발생
	//this->message.str(DUMMY_MANAGER.GetDummyString().data());
	//this->message = put_time(&this->date, format.c_str());
	//this->message << put_time(&this->date, format.c_str()) << "\t";

}
