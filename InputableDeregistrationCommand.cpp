#include "InputableDeregistrationCommand.h"
#include "InputableAttorney.h"

InputableDeregistrationCommand::InputableDeregistrationCommand(Inputable* in, AZUL_KEY k, INPUT_EVENT_TYPE e)
	:ptrInputable(in), key(k), Event(e)
{
}

void InputableDeregistrationCommand::execute()
{
	InputableAttorney::Registration::InputableDeregistration(ptrInputable, key, Event);
}
