//Inputable
//Daniel Goodrum, Jan 2018

#ifndef INPUTABLE_H
#define INPUTABLE_H

#include "AzulCore.h"
#include "Input_Event_Type.h"
#include "RegistrationState.h"

class Inputable
{
	friend class InputableAttorney;

public:

	Inputable();
	virtual ~Inputable();
	Inputable(const Inputable&) = delete;
	Inputable& operator = (const Inputable&) = delete;

	/// \brief  Register an input for a GameObject.
	/// \code
	///
	///		Tank::Tank()
	///		{
	///			this->SubmitKeyRegistration(AZUL_KEY::KEY_SPACE, INPUT_EVENT_TYPE::KEY_PRESS); //Registers this Tank Object to Recieve a notification
	///		}																					of Space Key being pressed. 
	///
	///
	///		GameObject::KeyPressed(AZUL_KEY k)
	///		{
	///			if(k == AZUL_KEY_SPACE)
	///			{
	///				Fire...;// any operation desired.
	///			}
	///		}
	///\endcode
	virtual void SceneRegistration(AZUL_KEY k, INPUT_EVENT_TYPE e);
	/// \brief	Deregister an input for a GameObject
	virtual void SceneDeregistration(AZUL_KEY k, INPUT_EVENT_TYPE e);

private:

	virtual void KeyPressed(AZUL_KEY k);
	virtual void KeyReleased(AZUL_KEY k);
	
	RegistrationState KeyPressedState;
	RegistrationState KeyReleasedState;



protected:
	virtual void SubmitKeyRegistration(AZUL_KEY k, INPUT_EVENT_TYPE e);
	virtual void SubmitKeyDeregistration(AZUL_KEY k, INPUT_EVENT_TYPE e);
};



#endif // !INPUTABLE_H
