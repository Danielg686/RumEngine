#include "KeypressLogging.h"
#include "LiveKeyInput.h"
#include "KeyPlayback.h"

KeypressLogging* KeypressLogging::ptrInstance = nullptr;

KeypressLogging::~KeypressLogging()
{
}

void KeypressLogging::privDelete()
{
	delete CurrentInput;
	ptrInstance = nullptr;
}

bool KeypressLogging::privGetKeyState(AZUL_KEY key)
{
	return CurrentInput->GetKeyState(key);
}

void KeypressLogging::privInitizlize(KeyInputState state)
{
	if (state == KeyInputState::LiveKeys)
	{
		CurrentInput = new LiveKeyInput();
		return;
	}
	else if (state == KeyInputState::RecordedKeys)
	{
		CurrentInput = new KeyPlayback();
		return;
	}

}
