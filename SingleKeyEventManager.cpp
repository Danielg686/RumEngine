#include "SingleKeyEventManager.h"
#include "InputableAttorney.h"
#include "KeypressLogging.h"


SingleKeyEventManager::SingleKeyEventManager(AZUL_KEY k)
{
	key = k;
	CurrentKeyState = INPUT_EVENT_TYPE::KEY_RELEASE;
}

void SingleKeyEventManager::ProcessKeyEvent()
{
	KeyCol::const_iterator itr;
	//bool KeyPressed = Keyboard::GetKeyState(key);
	bool KeyPressed = KeypressLogging::GetKeyState(key);
	if (KeyPressed && CurrentKeyState == INPUT_EVENT_TYPE::KEY_RELEASE)
	{
		itr = KeyReleaseCol.begin();
		while (itr != KeyReleaseCol.end())
		{
			Inputable* temp = (*itr);
			InputableAttorney::GameLoop::KeyReleased(temp, key);
			itr++;
		}
		CurrentKeyState = INPUT_EVENT_TYPE::KEY_PRESS;
	}
	else if (!KeyPressed && CurrentKeyState == INPUT_EVENT_TYPE::KEY_PRESS)
	{
		itr = KeyPressCol.begin();
		while (itr != KeyPressCol.end())
		{
			Inputable* temp = (*itr);
			InputableAttorney::GameLoop::KeyPressed(temp, key);
			itr++;
		}
		CurrentKeyState = INPUT_EVENT_TYPE::KEY_RELEASE;
	}

}

void SingleKeyEventManager::Register(Inputable * a, INPUT_EVENT_TYPE e)
{
	if (e == INPUT_EVENT_TYPE::KEY_PRESS)
	{
		KeyPressCol.push_back(a);
	}
	else
	{
		KeyReleaseCol.push_back(a);
	}
}

void SingleKeyEventManager::Deregister(Inputable * a, INPUT_EVENT_TYPE e)
{
	if (e == INPUT_EVENT_TYPE::KEY_PRESS)
	{
		KeyPressCol.remove(a);

	}
	else
	{
		KeyReleaseCol.remove(a);
	}
}

SingleKeyEventManager::~SingleKeyEventManager()
{
}
