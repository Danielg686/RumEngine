#include "AlarmRegistrationCommand.h"
#include "Alarmable.h"
#include "AlarmableAttorney.h"
AlarmRegistrationCommand::AlarmRegistrationCommand(Alarmable * al, AlarmManager::ALARM_ID id)
	:ptrAlarmable(al), al_id(id)
{
}

void AlarmRegistrationCommand::execute()
{
	AlarmableAttorney::Registration::AlarmRegistration(ptrAlarmable, time, al_id);
}

void AlarmRegistrationCommand::setTime(float t)
{
	this->time = t;
}
