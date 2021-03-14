#pragma once

#define TIME_MANAGER GET_INSTANCE(TimeManager)

using TIME_POINT = chrono::system_clock::time_point;
using TIME_VALUE = long long;

class TimeManager
{
	DECLARE_SINGLETON(TimeManager)


private:
	TIME_POINT GetNow(void) const;

public:
	TIME_VALUE GetNowSeconds(void) const;

public:
	void Start(void);
	void End(void);

private:
	void GetTime(string_view format);

public:
	string GetDate(void);
	string GetTime(void);
	string GetDateTime(void);

private:
	TIME_POINT start, end;
	chrono::duration<double> sec;
	string timeEndMessage = "Time has been passed (sec)";
	static const int timeBufferSize = 128;
	char timeBuffer[timeBufferSize];
	string time;
	string dateFormat = "%F";
	string timeFormat = "%T";
	string dateTimeFormat = "%F %T";

private:
	time_t now;
	struct tm date;
};