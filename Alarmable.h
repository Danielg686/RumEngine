//Alarmable
//Daniel Goodrum, Jan 2018

#ifndef ALARMABLE_H
#define ALARMABLE_H

#include "AzulCore.h"
#include "RegistrationState.h"
#include "AlarmRegistrationCommand.h"
#include "AlarmDeregistrationCommand.h"
#include <map>
#include "AlarmManager.h"

class Alarmable
{
	friend class AlarmableAttorney;
	//friend class AlarmManager;
	//friend class AlarmRegistrationCommand;
	//friend class AlarmDeregistrationCommand;


public:

	/// \brief All Game objects derive from Alarmable.
	Alarmable();
	virtual ~Alarmable();
	Alarmable(const Alarmable&) = delete;
	Alarmable& operator = (const Alarmable&) = delete;
	
private:
	struct RegistrationData
	{
		AlarmManager::StorageListRef alarmRef;
		RegistrationState CurrRegState;
		AlarmRegistrationCommand* pAlarmRegistrationCommand;
		AlarmDeregistrationCommand* pAlarmDeregistrationCommand;
	};

	///	\brief 	Place code to execute when Alarm 0 is activated.
	///		\code
	///		Alarm0()
	///		{
	///			//make sound ect.
	///		}
	///\endcode
	virtual void Alarm0();
	
	///		\brief Same as Alarm0 but for Alarm 1.
	virtual void Alarm1();

	///		\brief Same as Alarm0 but for Alarm 2.
	virtual void Alarm2();

	///		\brief Registers an alarm. Behind the scenes stuff.
	virtual void AlarmRegistration(float t, AlarmManager::ALARM_ID id);

	///		\brief Deregisters an alarm before it actives.
	virtual void AlarmDeregistration(AlarmManager::ALARM_ID id);

	///		\brief Activates user defined code for a given alarm.
	virtual void TriggerAlarm(AlarmManager::ALARM_ID id);


	///		\brief Stores Registration data for alarms.
	RegistrationData RegData[AlarmManager::ALARM_NUMBER];


protected:

	///		\brief Registers alarm 0 for t seconds;
	void SubmitAlarmRegistration0(float t);
	///		\brief Registers alarm 1 for t seconds;
	void SubmitAlarmRegistration1(float t);
	///		\brief Registers alarm 2 for t seconds;
	void SubmitAlarmRegistration2(float t);

	///		\brief Deregisters alarm 0 for t seconds;
	void SubmitAlarmDeregistration0();
	///		\brief Deregisters alarm 1 for t seconds;
	void SubmitAlarmDeregistration1();
	///		\brief Deregisters alarm 2 for t seconds;
	void SubmitAlarmDeregistration2();

};

#endif



