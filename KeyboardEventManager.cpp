#include "KeyboardEventManager.h"


KeyboardEventManager::~KeyboardEventManager()
{
	KeyboardMap::const_iterator itr = KeyEventMap.begin();
	while (itr != KeyEventMap.end())
	{
		SingleKeyEventManager* temp = (*itr).second;
		KeyEventMap.erase(itr++);
		delete temp;
	}
}

void KeyboardEventManager::ProcessKeyEvents()
{
	KeyboardMap::const_iterator itr = KeyEventMap.begin();
	while (itr != KeyEventMap.end())
	{
		(*itr).second->ProcessKeyEvent();
		itr++;
	}
}

void KeyboardEventManager::Register(Inputable * p, AZUL_KEY k, INPUT_EVENT_TYPE e)
{
	if (KeyEventMap.find(k) == KeyEventMap.end())
	{
		//KeyboardMap::const_iterator itr = KeyEventMap.begin();
		//while (itr != KeyEventMap.end())
		//{
		//	if ((*itr).first == k)
		//	{
		//		(*itr).second->Register(p, e);
		//		break;
		//	}
		//	itr++;
		//}
		SingleKeyEventManager* temp = new SingleKeyEventManager(k);
		KeyInputablePair thisPair(k, temp);
		KeyEventMap.insert(thisPair);
	}
	
	KeyboardMap::const_iterator itr = KeyEventMap.find(k);
	(*itr).second->Register(p, e);
}

void KeyboardEventManager::Deregister(Inputable * p, AZUL_KEY k, INPUT_EVENT_TYPE e)
{
	KeyboardMap::const_iterator itr = KeyEventMap.begin();
	while (itr != KeyEventMap.end())
	{
		if ((*itr).first == k)
		{
			(*itr).second->Deregister(p, e);
			break;
		}
		itr++;
	}
}
