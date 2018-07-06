#include "Updatable.h"
#include "SceneManager.h"
#include "UpdateRegistrationCommand.h"
#include "UpdateDeregisterCommand.h"
#include "CommandBase.h"
#include "SceneAttorney.h"

Updatable::Updatable()
{
	pRegistrationCommand = new UpdateRegistrationCommand(this);
	pDeregisterCommand = new UpdateDeregisterCommand(this);

	CurrRegState = RegistrationState::CURRENTLY_DEREGISTERED;
}

Updatable::~Updatable()
{
	DebugMsg::out("Updatable class destructor called\n");
	delete pRegistrationCommand;
	delete pDeregisterCommand;
}


void Updatable::SceneRegistration()
{
	assert(CurrRegState == RegistrationState::PENDING_REGISTRION);
	//SceneManager::GetCurrentScene()->Register(this, pMyDeleteRef);
	SceneAttorney::Registration::Register(SceneManager::GetCurrentScene(), this, pMyDeleteRef);
	CurrRegState = RegistrationState::CURRENTLY_REGISTERED;
}

void Updatable::SceneDeregistration()
{
	assert(CurrRegState == RegistrationState::PENDING_DEREGISTRATION);
	//SceneManager::GetCurrentScene()->Deregister(this, pMyDeleteRef);
	SceneAttorney::Registration::Deregister(SceneManager::GetCurrentScene(), this, pMyDeleteRef);
	CurrRegState = RegistrationState::CURRENTLY_DEREGISTERED;
}

void Updatable::SubmitUpdateRegistration()
{
	assert(CurrRegState == RegistrationState::CURRENTLY_DEREGISTERED);
	//SceneManager::GetCurrentScene()->SubmitCommand(pRegistrationCommand);
	SceneAttorney::Registration::SubmitCommand(SceneManager::GetCurrentScene(), pRegistrationCommand);
	CurrRegState = RegistrationState::PENDING_REGISTRION;
}

void Updatable::SubmitUpdateDeregistration()
{
	assert(CurrRegState == RegistrationState::CURRENTLY_REGISTERED);
	//SceneManager::GetCurrentScene()->SubmitCommand(pDeregisterCommand);
	SceneAttorney::Registration::SubmitCommand(SceneManager::GetCurrentScene(), pDeregisterCommand);
	CurrRegState = RegistrationState::PENDING_DEREGISTRATION;
}
