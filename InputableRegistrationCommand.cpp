#include "InputableRegistrationCommand.h"
#include "Inputable.h"
#include "KeyboardEventManager.h"
#include "InputableAttorney.h"

InputableRegistrationCommand::InputableRegistrationCommand(Inputable* in, AZUL_KEY k, INPUT_EVENT_TYPE e)
	:ptrInputable(in), key(k), Event(e)
{
}

void InputableRegistrationCommand::execute()
{
	InputableAttorney::Registration::InputableRegistration(ptrInputable, key, Event);
}
