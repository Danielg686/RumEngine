//Updatable
//Daniel Goodrum, Jan 2018

#ifndef UPDATABLE_H
#define UPDATABLE_H

#include "AzulCore.h"
#include "RegistrationState.h"
#include "UpdatableManager.h"

class UpdateRegistrationCommand;
class UpdateDeregisterCommand;

class Updatable
{
	friend class UpdatableAttorney;

	//friend class UpdatableManager;
	//friend class UpdateRegistrationCommand;
	//friend class UpdateDeregisterCommand;

public:

	Updatable();
	virtual ~Updatable();
	Updatable(const Updatable&) = delete;
	Updatable& operator = (const Updatable&) = delete;


private:
	/// \brief Called once per frame on all GameObjects in the current Scene
	/// 
	/// \ingroup DEFAULTEVENTS
	/// All GameObjects are automatically registered to the current Scene 
	/// By default does nothing but can be defined by the user.
	virtual void Update() {};

	RegistrationState CurrRegState;
	UpdateRegistrationCommand* pRegistrationCommand;
	UpdateDeregisterCommand* pDeregisterCommand;
	UpdatableManager::UpdatableListRef pMyDeleteRef;

	virtual void SceneRegistration();
	virtual void SceneDeregistration();
	
protected:


	virtual void SubmitUpdateRegistration();
	virtual void SubmitUpdateDeregistration();
};

#endif // !UPDATABLE_H