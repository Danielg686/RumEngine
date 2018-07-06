// AlarmableAttorney
//Daniel Goodrum, Feb 2018

#ifndef ALARMABLEATTORNEY_H
#define ALARMABLEATTORNEY_H

#include "Alarmable.h"
#include "AlarmManager.h"

class AlarmableAttorney
{
public:
	class GameLoop
	{
	private:
		friend class AlarmManager;

		/// \brief Attorney passthrough for Triggering alarm in the Alarmable class. 
		static void TriggerAlarm(Alarmable* al, AlarmManager::ALARM_ID id) { al->TriggerAlarm(id); }
	};

public:
	class Registration
	{
		friend class AlarmRegistrationCommand;
		friend class AlarmDeregistrationCommand;
		friend class AlarmManager;

	private:
		///		\brief Passthrough for AlarmManager to get alarmable delete reference.
		static AlarmManager::StorageListRef Deregister(Alarmable* al, AlarmManager::ALARM_ID id) { return al->RegData[id].alarmRef; }
		///		\brief Passthrough for Alarmable Deregistration Command.
		static void AlarmDeregistration(Alarmable* al, AlarmManager::ALARM_ID id) { al->AlarmDeregistration(id); }
		///		\brief Passthrough for Alarmable Registration Command.
		static void AlarmRegistration(Alarmable* al,float t, AlarmManager::ALARM_ID id) { al->AlarmRegistration(t, id); }
	};
};



#endif // !ALARMABLEATTORNEY_H
