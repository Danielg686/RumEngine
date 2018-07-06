//InputableAttorney
//Daniel Goodrum, Feb 2018


#ifndef INPUTABLEATTORNEY_H
#define INPUTABLEATTORNEY_H

#include "Inputable.h"
#include "Input_Event_Type.h"

class InputableAttorney
{
public:
	class GameLoop
	{
		friend class SingleKeyEventManager;

		///		\brief Passthrough to indicatie a KeyPress.
		static void KeyPressed(Inputable* pMgr, AZUL_KEY k) { pMgr->KeyPressed(k); }
		///		\brief Passthrough to indicate a KeyRelease.
		static void KeyReleased(Inputable* pMgr, AZUL_KEY k) { pMgr->KeyReleased(k); }
	};

public:
	class Registration
	{
		friend class InputableRegistrationCommand;
		friend class InputableDeregistrationCommand;

	private:

		///		\brief Passthrough to Register an Inputable
		static void InputableRegistration(Inputable* pMgr, AZUL_KEY k, INPUT_EVENT_TYPE e) { pMgr->SceneRegistration(k, e); }
		///		\brief Passthrough to Deregister Inputable
		static void InputableDeregistration(Inputable* pMgr, AZUL_KEY k, INPUT_EVENT_TYPE e) { pMgr->SceneDeregistration(k, e); }
	};



};


#endif // !INPUTABLEATTORNEY_H
