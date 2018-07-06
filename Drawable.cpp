#include "Drawable.h"
#include "SceneManager.h"
#include "DrawRegistrationCommand.h"
#include "DrawDeregisterCommand.h"
#include "CommandBase.h"
#include "SceneAttorney.h"

Drawable::Drawable()
{
	pRegistrationCommand = new DrawRegistrationCommand(this);
	pDeregisterCommand = new DrawDeregisterCommand(this);

	CurrRegState = RegistrationState::CURRENTLY_DEREGISTERED;
}

Drawable::~Drawable()
{
	DebugMsg::out("Drawable class destructor called\n");
	delete pRegistrationCommand;
	delete pDeregisterCommand;
}

void Drawable::SceneRegistration()
{
	assert(CurrRegState == RegistrationState::PENDING_REGISTRION);
	//SceneManager::GetCurrentScene()->Register(this, pMyDeleteRef);
	SceneAttorney::Registration::Register(SceneManager::GetCurrentScene(), this, pMyDeleteRef);
	CurrRegState = RegistrationState::CURRENTLY_REGISTERED;
}

void Drawable::SceneDeregistration()
{
	assert(CurrRegState == RegistrationState::PENDING_DEREGISTRATION);
	//SceneManager::GetCurrentScene()->Deregister(this, pMyDeleteRef);
	SceneAttorney::Registration::Deregister(SceneManager::GetCurrentScene(), this, pMyDeleteRef);
	CurrRegState = RegistrationState::CURRENTLY_DEREGISTERED;
}

void Drawable::SubmitDrawRegistration()
{
	assert(CurrRegState == RegistrationState::CURRENTLY_DEREGISTERED);
	//SceneManager::GetCurrentScene()->SubmitCommand(pRegistrationCommand);
	SceneAttorney::Registration::SubmitCommand(SceneManager::GetCurrentScene(), pRegistrationCommand);
	CurrRegState = RegistrationState::PENDING_REGISTRION;
}

void Drawable::SubmitDrawDeregistration()
{
	assert(CurrRegState == RegistrationState::CURRENTLY_REGISTERED);
	//SceneManager::GetCurrentScene()->SubmitCommand(pDeregisterCommand);
	SceneAttorney::Registration::SubmitCommand(SceneManager::GetCurrentScene(), pDeregisterCommand);
	CurrRegState = RegistrationState::PENDING_DEREGISTRATION;
}
