//Keyboard Event Manager
//Daniel Goodrum, Feb 2018

#ifndef KEYBOARDEVENTMANAGER_H
#define KEYBOARDEVENTMANAGER_H

#include "AzulCore.h"
#include <map>
#include "Inputable.h"
#include "Input_Event_Type.h"
#include "SingleKeyEventManager.h"

class KeyboardEventManager
{
public:
	KeyboardEventManager() = default;
	~KeyboardEventManager();

	void ProcessKeyEvents();

	void Register(Inputable* p, AZUL_KEY k, INPUT_EVENT_TYPE e);
	void Deregister(Inputable* p, AZUL_KEY k, INPUT_EVENT_TYPE e);


private:
	using KeyInputablePair = std::pair<AZUL_KEY, SingleKeyEventManager*>;
	using KeyboardMap = std::map<AZUL_KEY, SingleKeyEventManager*>;
	KeyboardMap KeyEventMap;

	int FrameProcessed = 0;

};



#endif // !KEYBOARDEVENTMANAGER_H


