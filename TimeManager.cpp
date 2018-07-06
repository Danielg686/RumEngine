#include "TimeManager.h"


TimeManager* TimeManager::ptrInstance = nullptr;

TimeManager::TimeManager()
{
	FrzTime = new FreezeTime();
}

void TimeManager::privDelete()
{
	delete FrzTime;
	delete ptrInstance;
	ptrInstance = nullptr;
}

void TimeManager::privProcessTime(float sys_time)
{
	PreviousTime = CurrentTime;

	//CurrentTime = sys_time;
	CurrentTime = FrzTime->GetTimeInSeconds(sys_time);

	FrameTime = CurrentTime - PreviousTime;
}
