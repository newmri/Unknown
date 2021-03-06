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

private:
	time_t now;
	tm date;
};