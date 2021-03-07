#pragma once

using TIME_POINT = chrono::system_clock::time_point;

class TimeManager
{
	DECLARE_SINGLETON(TimeManager)

private:
	TIME_POINT GetNow(void) const;
public:
	void Start(void);
	void End(void);
	string GetTime(void);

private:
	TIME_POINT start, end;
	chrono::duration<double> sec;
	ostringstream message;
	static const int timeBufferSize = 128;
	char timeBuffer[timeBufferSize];
	string time;
	string format = "%F %T";

private:
	time_t now;
	struct tm date;
};