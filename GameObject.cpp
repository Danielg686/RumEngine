#include "GameObject.h"
#include "GameObjectEntryCommand.h"
#include "GameObjectExitCommand.h"
#include "SceneAttorney.h"

GameObject::GameObject()
{
	CurrRegState = RegistrationState::CURRENTLY_DEREGISTERED;
	ptrEntryCommand = new GameObjectEntryCommand(this);
	ptrExitCommand = new GameObjectExitCommand(this);
}

GameObject::~GameObject()
{
	delete ptrEntryCommand;
	delete ptrExitCommand;
}

void GameObject::SubmitEntry()
{
	assert(CurrRegState == RegistrationState::CURRENTLY_DEREGISTERED);
	SceneAttorney::Registration::SubmitCommand(SceneManager::GetCurrentScene(), ptrEntryCommand);
	CurrRegState = RegistrationState::PENDING_REGISTRION;
	
}

void GameObject::SubmitExit()
{
	assert(CurrRegState == RegistrationState::CURRENTLY_REGISTERED);
	SceneAttorney::Registration::SubmitCommand(SceneManager::GetCurrentScene(), ptrExitCommand);
	CurrRegState = RegistrationState::PENDING_DEREGISTRATION;
	
}

void GameObject::ConnectToScene()
{
	assert(CurrRegState == RegistrationState::PENDING_REGISTRION);
	CurrRegState = RegistrationState::CURRENTLY_REGISTERED;
	SceneEntry();
}

void GameObject::DisconnectFromScene()
{
	assert(CurrRegState == RegistrationState::PENDING_DEREGISTRATION);
	CurrRegState = RegistrationState::CURRENTLY_DEREGISTERED;
	SceneExit();
}

void GameObject::SceneEntry()
{
}

void GameObject::SceneExit()
{
}
