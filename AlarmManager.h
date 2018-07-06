//AlarmManager
//Daniel Goodrum

#ifndef ALARMMANGER_H
#define ALARMMANGER_H

#include "AzulCore.h"
#include <map>


class Alarmable;

class AlarmManager
{


public:
	AlarmManager();
	~AlarmManager();

	void ProcessAlarms();

	
	enum ALARM_ID { ALARM_0, ALARM_1, ALARM_2 };
	static const int ALARM_NUMBER = 3;



	void Deregister(Alarmable* al, AlarmManager::ALARM_ID id);

private:
	using AlarmEvent = std::pair<Alarmable*, ALARM_ID>;
	using TimeLineMap = std::multimap<float, AlarmEvent>;
	TimeLineMap timeline;

public:
	using StorageListRef = TimeLineMap::iterator;

	void Register(float t, Alarmable* al, AlarmManager::ALARM_ID id, StorageListRef& ref);

};


#endif // !ALARMMANGER_H
