//Single Key Event Manager
//Daniel Goodrum Feb 2018

#ifndef SINGLEKEYEVENTMANAGER_H
#define SINGLEKEYEVENTMANAGER_H

#include "AzulCore.h"
#include <list>
#include "Inputable.h"
#include "Input_Event_Type.h"

class SingleKeyEventManager
{
public:
	SingleKeyEventManager() = delete;
	SingleKeyEventManager(AZUL_KEY k);

	void ProcessKeyEvent();

	void Register(Inputable* a, INPUT_EVENT_TYPE e);
	void Deregister(Inputable* a, INPUT_EVENT_TYPE e);

	~SingleKeyEventManager();



private:

	AZUL_KEY key;
	using KeyCol = std::list<Inputable*>;
	KeyCol KeyPressCol;
	KeyCol KeyReleaseCol;
	INPUT_EVENT_TYPE CurrentKeyState;



};




#endif // !SINGLEKEYEVENTMANAGER_H

