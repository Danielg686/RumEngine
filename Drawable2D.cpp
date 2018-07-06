#include "Drawable2D.h"
#include "SceneManager.h"
#include "Draw2DRegistrationCommand.h"
#include "Draw2DDeregistrationCommand.h"
#include "CommandBase.h"
#include "SceneAttorney.h"

Drawable2D::Drawable2D()
{
	pRegistrationCommand = new Draw2DRegistrationCommand(this);
	pDeregisterCommand = new Draw2DDeregistrationCommand(this);

	CurrRegState = RegistrationState::CURRENTLY_DEREGISTERED;
}

Drawable2D::~Drawable2D()
{
	delete pRegistrationCommand;
	delete pDeregisterCommand;
}

void Drawable2D::SceneRegistration()
{
	assert(CurrRegState == RegistrationState::PENDING_REGISTRION);
	SceneAttorney::Registration::Register(SceneManager::GetCurrentScene(), this, pMyDeleteRef);
	CurrRegState = RegistrationState::CURRENTLY_REGISTERED;
}

void Drawable2D::SceneDeregistration()
{
	assert(CurrRegState == RegistrationState::PENDING_DEREGISTRATION);
	SceneAttorney::Registration::Deregister(SceneManager::GetCurrentScene(), this, pMyDeleteRef);
	CurrRegState = RegistrationState::CURRENTLY_DEREGISTERED;
}

void Drawable2D::SubmitDraw2DRegistration()
{
	assert(CurrRegState == RegistrationState::CURRENTLY_DEREGISTERED);
	SceneAttorney::Registration::SubmitCommand(SceneManager::GetCurrentScene(), pRegistrationCommand);
	CurrRegState = RegistrationState::PENDING_REGISTRION;
}

void Drawable2D::SubmitDraw2DDeregistration()
{
	assert(CurrRegState == RegistrationState::CURRENTLY_REGISTERED);
	SceneAttorney::Registration::SubmitCommand(SceneManager::GetCurrentScene(), pDeregisterCommand);
	CurrRegState = RegistrationState::PENDING_DEREGISTRATION;
}
