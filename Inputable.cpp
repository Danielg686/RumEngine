#include "Inputable.h"
#include "SceneAttorney.h"
#include "SceneManager.h"
#include "InputableRegistrationCommand.h"
#include "InputableDeregistrationCommand.h"

Inputable::Inputable()
{
	KeyPressedState = RegistrationState::CURRENTLY_DEREGISTERED;
	KeyReleasedState = RegistrationState::CURRENTLY_DEREGISTERED;
}

Inputable::~Inputable()
{
}

void Inputable::SceneRegistration(AZUL_KEY k, INPUT_EVENT_TYPE e)
{
	SceneAttorney::Registration::Register(SceneManager::GetCurrentScene(), this, k, e);
}

void Inputable::SceneDeregistration(AZUL_KEY k, INPUT_EVENT_TYPE e)
{
	SceneAttorney::Registration::Deregister(SceneManager::GetCurrentScene(), this, k, e);
}

void Inputable::KeyPressed(AZUL_KEY k)
{
	UNREFERENCED_PARAMETER(k);
}

void Inputable::KeyReleased(AZUL_KEY k)
{
	UNREFERENCED_PARAMETER(k);
}

void Inputable::SubmitKeyRegistration(AZUL_KEY k, INPUT_EVENT_TYPE e)
{
	InputableRegistrationCommand* temp = new InputableRegistrationCommand(this, k, e);
	SceneAttorney::Registration::SubmitCommand(SceneManager::GetCurrentScene(), temp);
}

void Inputable::SubmitKeyDeregistration(AZUL_KEY k, INPUT_EVENT_TYPE e)
{
	InputableDeregistrationCommand* temp = new InputableDeregistrationCommand(this, k, e);
	SceneAttorney::Registration::SubmitCommand(SceneManager::GetCurrentScene(), temp);
}
