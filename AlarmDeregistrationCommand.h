//Alarm Deregistration Command
//Daniel Goodrum, Jan 2018


#ifndef ALARMDEREGISTRATIONCOMMAND_H
#define ALARMDEREGISTRATIONCOMMAND_H

#include "SceneRegistrationCommand.h"
#include "AlarmManager.h"
class Alarmable;

class AlarmDeregistrationCommand : public SceneRegistrationCommand
{
public:
	AlarmDeregistrationCommand() = delete;
	AlarmDeregistrationCommand(Alarmable* al, AlarmManager::ALARM_ID id);

	virtual void execute() override;

	virtual ~AlarmDeregistrationCommand() {}
private:
	Alarmable* ptrAlarmable;
	AlarmManager::ALARM_ID al_id;

};





#endif // !ALARMDEREGISTRATIONCOMMAND_H
