//Updatable Attorney
//Daniel Goodrum, Jan 2018

#ifndef UPDATABLEATTORNEY_H
#define UPDATABLEATTORNEY_H

#include "Updatable.h"


class UpdatableAttorney
{
public:
	class GameLoop
	{
	private:
		friend class UpdatableManager;

		///		\brief Passthrough for UpdateMNanager to access updatable.
		static void Update(Updatable* pMgr) { pMgr->Update(); }
	};

public:
	class Registration
	{
		friend class UpdateRegistrationCommand;
		friend class UpdateDeregisterCommand;

	private:
		///		\brief Passthrough for SceneRegistration 
		static void SceneRegistration(Updatable* pMgr) { pMgr->SceneRegistration(); }
		///		\brief Passthrough for SceneDeregistration.
		static void SceneDeregistration(Updatable* pMgr) { pMgr->SceneDeregistration(); }
	};
};



#endif // !UPDATABLEATTORNEY_H
