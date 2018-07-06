//Alarm Registration Command
//Daniel Goodrum, Jan 2018

#ifndef ALARMREGISTRATIONCOMMAND_H
#define ALARMREGISTRATIONCOMMAND_H

#include "SceneRegistrationCommand.h"
#include "AlarmManager.h"
class Alarmable;

class AlarmRegistrationCommand : public SceneRegistrationCommand
{
public:
	AlarmRegistrationCommand() = delete;
	AlarmRegistrationCommand(Alarmable* al, AlarmManager::ALARM_ID id);

	virtual void execute() override;
	void setTime(float t);

	virtual ~AlarmRegistrationCommand() {}
private:
	Alarmable* ptrAlarmable;
	AlarmManager::ALARM_ID al_id;
	float time;

protected:
	


};


#endif // !ALARMREGISTRATIONCOMMAND_H
