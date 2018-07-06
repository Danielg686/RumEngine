#include "Alarmable.h"

#include "SceneManager.h"
#include "SceneAttorney.h"

Alarmable::Alarmable()
{

	RegData[0].pAlarmRegistrationCommand = new AlarmRegistrationCommand(this, AlarmManager::ALARM_0);
	RegData[0].pAlarmDeregistrationCommand = new AlarmDeregistrationCommand(this, AlarmManager::ALARM_0);
	RegData[0].CurrRegState = RegistrationState::CURRENTLY_DEREGISTERED;

	RegData[1].pAlarmRegistrationCommand = new AlarmRegistrationCommand(this, AlarmManager::ALARM_1);
	RegData[1].pAlarmDeregistrationCommand = new AlarmDeregistrationCommand(this, AlarmManager::ALARM_1);
	RegData[1].CurrRegState = RegistrationState::CURRENTLY_DEREGISTERED;

	RegData[2].pAlarmRegistrationCommand = new AlarmRegistrationCommand(this, AlarmManager::ALARM_2);
	RegData[2].pAlarmDeregistrationCommand = new AlarmDeregistrationCommand(this, AlarmManager::ALARM_2);
	RegData[2].CurrRegState = RegistrationState::CURRENTLY_DEREGISTERED;

}

Alarmable::~Alarmable()
{
	DebugMsg::out("Drawable class destructor called\n");
	for (int i = 0; i < AlarmManager::ALARM_NUMBER; i++)
	{
		delete RegData[i].pAlarmDeregistrationCommand;
		delete RegData[i].pAlarmRegistrationCommand;
	}
}

void Alarmable::Alarm0()
{
}

void Alarmable::Alarm1()
{
}

void Alarmable::Alarm2()
{
}

void Alarmable::AlarmRegistration(float t, AlarmManager::ALARM_ID id)
{
	assert(RegData[id].CurrRegState == RegistrationState::PENDING_REGISTRION);
	//SceneManager::GetCurrentScene()->Register(t, this, id, RegData[id].alarmRef);
	SceneAttorney::Registration::Register(SceneManager::GetCurrentScene(), t, this, id, RegData[id].alarmRef);
	RegData[id].CurrRegState = RegistrationState::CURRENTLY_REGISTERED;
}


void Alarmable::AlarmDeregistration(AlarmManager::ALARM_ID id)
{
	assert(RegData[id].CurrRegState == RegistrationState::PENDING_DEREGISTRATION);
	//SceneManager::GetCurrentScene()->Deregister(this, id);
	SceneAttorney::Registration::Deregister(SceneManager::GetCurrentScene(), this, id);
	RegData[id].CurrRegState = RegistrationState::CURRENTLY_DEREGISTERED;
}

void Alarmable::TriggerAlarm(AlarmManager::ALARM_ID id)
{
	switch (id)
	{
	case AlarmManager::ALARM_0:
		RegData[0].CurrRegState = RegistrationState::CURRENTLY_DEREGISTERED;
		this->Alarm0();
		break;
	case AlarmManager::ALARM_1:
		RegData[1].CurrRegState = RegistrationState::CURRENTLY_DEREGISTERED;
		this->Alarm1();
		break;
	case AlarmManager::ALARM_2:
		RegData[2].CurrRegState = RegistrationState::CURRENTLY_DEREGISTERED;
		this->Alarm2();
		break;
	}
}

void Alarmable::SubmitAlarmRegistration0(float t)
{
	assert(RegData[0].CurrRegState == RegistrationState::CURRENTLY_DEREGISTERED);
	RegData[0].pAlarmRegistrationCommand->setTime(t);
	//SceneManager::GetCurrentScene()->SubmitCommand(RegData[0].pAlarmRegistrationCommand);
	SceneAttorney::Registration::SubmitCommand(SceneManager::GetCurrentScene(), RegData[0].pAlarmRegistrationCommand);
	RegData[0].CurrRegState = RegistrationState::PENDING_REGISTRION;
}

void Alarmable::SubmitAlarmRegistration1(float t)
{
	assert(RegData[1].CurrRegState == RegistrationState::CURRENTLY_DEREGISTERED);
	RegData[1].pAlarmRegistrationCommand->setTime(t);
	//SceneManager::GetCurrentScene()->SubmitCommand(RegData[1].pAlarmRegistrationCommand);
	SceneAttorney::Registration::SubmitCommand(SceneManager::GetCurrentScene(), RegData[1].pAlarmRegistrationCommand);
	RegData[1].CurrRegState = RegistrationState::PENDING_REGISTRION;
}

void Alarmable::SubmitAlarmRegistration2(float t)
{
	assert(RegData[2].CurrRegState == RegistrationState::CURRENTLY_DEREGISTERED);
	RegData[2].pAlarmRegistrationCommand->setTime(t);
	//SceneManager::GetCurrentScene()->SubmitCommand(RegData[2].pAlarmRegistrationCommand);
	SceneAttorney::Registration::SubmitCommand(SceneManager::GetCurrentScene(), RegData[2].pAlarmRegistrationCommand);
	RegData[2].CurrRegState = RegistrationState::PENDING_REGISTRION;
}

void Alarmable::SubmitAlarmDeregistration0()
{
	assert(RegData[0].CurrRegState == RegistrationState::CURRENTLY_REGISTERED);
	//SceneManager::GetCurrentScene()->SubmitCommand(RegData[0].pAlarmDeregistrationCommand);
	SceneAttorney::Registration::SubmitCommand(SceneManager::GetCurrentScene(), RegData[0].pAlarmDeregistrationCommand);
	RegData[0].CurrRegState = RegistrationState::PENDING_DEREGISTRATION;
}

void Alarmable::SubmitAlarmDeregistration1()
{
	assert(RegData[1].CurrRegState == RegistrationState::CURRENTLY_REGISTERED);
	//SceneManager::GetCurrentScene()->SubmitCommand(RegData[1].pAlarmDeregistrationCommand);
	SceneAttorney::Registration::SubmitCommand(SceneManager::GetCurrentScene(), RegData[1].pAlarmDeregistrationCommand);
	RegData[1].CurrRegState = RegistrationState::PENDING_DEREGISTRATION;
}

void Alarmable::SubmitAlarmDeregistration2()
{
	assert(RegData[2].CurrRegState == RegistrationState::CURRENTLY_REGISTERED);
	//SceneManager::GetCurrentScene()->SubmitCommand(RegData[2].pAlarmDeregistrationCommand);
	SceneAttorney::Registration::SubmitCommand(SceneManager::GetCurrentScene(), RegData[3].pAlarmDeregistrationCommand);
	RegData[2].CurrRegState = RegistrationState::PENDING_DEREGISTRATION;
}