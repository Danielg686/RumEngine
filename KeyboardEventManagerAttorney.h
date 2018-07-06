//KeyboardEventManagerAttorney
//Daniel Goodrum, Feb 2018

#ifndef KEYBOARDEVENTMANAGERATTORNEY_H
#define KEYBOARDEVENTMANAGERATTORNEY_H

#include "Inputable.h"

class KeyboardEventManagerAttorney
{
public:
	class GameLoop
	{
	private:
		friend class KeyboardEventManager;
		
	};
public:
	class Registration
	{
		friend class InputableRegistrationCommand;
		friend class InputableDeregistrationCommand;

	private:
		//static SceneRegistration(Inputable* in)

	};

};


#endif // !KEYBOARDEVENTMANAGERATTORNEY_H
