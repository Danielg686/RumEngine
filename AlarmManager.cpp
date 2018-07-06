#include "AlarmManager.h"
#include "RumEngine.h"
#include "Alarmable.h"
#include "TimeManager.h"
#include "AlarmableAttorney.h"

AlarmManager::AlarmManager()
{
	timeline.clear();
}

AlarmManager::~AlarmManager()
{
}

void AlarmManager::ProcessAlarms()
{
//	int t = timeline.size();
//	DebugMsg::out("size of alarm queue %d \n", t);
	TimeLineMap::const_iterator it = timeline.begin();
	float temp = TimeManager::GetTime();
	while (it != timeline.end())
	{
		//float temp = TimeManager::GetFrameTime();
		float alarmTime = (*it).first;
		if (alarmTime <= temp)
		{
			Alarmable* al = (*it).second.first;
			AlarmableAttorney::GameLoop::TriggerAlarm(al, (*it).second.second);

			timeline.erase(it++);
		}
		if(alarmTime >= temp || timeline.size() == 0)
		{
			break;
		}
	}
}

void AlarmManager::Register(float t, Alarmable* al, AlarmManager::ALARM_ID id, StorageListRef& ref)
{
	AlarmEvent temp (al, id);
	ref = timeline.insert(std::pair<float, AlarmEvent>(TimeManager::GetTime() + t, temp));
	//ref = timeline.find(t);
}

void AlarmManager::Deregister(Alarmable* al, AlarmManager::ALARM_ID id)
{
	timeline.erase(AlarmableAttorney::Registration::Deregister(al, id));

}
