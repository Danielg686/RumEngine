#include "AlarmDeregistrationCommand.h"
#include "Alarmable.h"
#include "AlarmableAttorney.h"

AlarmDeregistrationCommand::AlarmDeregistrationCommand(Alarmable * al, AlarmManager::ALARM_ID id)
	:ptrAlarmable(al), al_id(id)
{
}

void AlarmDeregistrationCommand::execute()
{
	//ptrAlarmable->AlarmDeregistration(al_id);
	AlarmableAttorney::Registration::AlarmDeregistration(ptrAlarmable, al_id);

}
