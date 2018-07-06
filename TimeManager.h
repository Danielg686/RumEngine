//TimeManager
//Daniel Goodrum, Feb 2018


#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H


#include "AzulCore.h"
#include "FreezeTime.h"

class TimeManager
{
	friend class TimeManagerAttorney;
public:
	/// \brief Gets Current Time
	static float GetTime() { return Instance().CurrentTime; }
	/// \brief Reference time used by the engine, specifically for functionallity of the freeze time feature
	static float GetFrameTime() { return Instance().FrameTime; }

private:


	static TimeManager* ptrInstance;

	TimeManager();
	TimeManager &operator = (const TimeManager&) = delete;
	TimeManager(const TimeManager&) = delete;
	~TimeManager() = default;

	static TimeManager& Instance()
	{
		if (!ptrInstance)
		{
			ptrInstance = new TimeManager;
		}
		return *ptrInstance;
	}

	float PreviousTime;
	float CurrentTime;
	float FrameTime;

	FreezeTime* FrzTime;

	
	void privDelete();
	void privProcessTime(float sys_time);
	static void ProcessTime(float sys_time) { Instance().privProcessTime(sys_time); }

	static void Delete() { Instance().privDelete(); }
};



#endif // !TIMEMANAGER_H
