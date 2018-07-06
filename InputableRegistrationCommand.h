//InputableRegistrationCommand
//Daniel Goodrum, Feb 2018

#ifndef INPUTABLEREGISTRATIONCOMMAND_H
#define INPUTABLEREGISTRATIONCOMMAND_H

#include "CommandBase.h"
#include "AzulCore.h"
#include "Input_Event_Type.h"

class Inputable;

class InputableRegistrationCommand : public CommandBase
{
public:
	InputableRegistrationCommand() = delete;
	InputableRegistrationCommand(Inputable* in, AZUL_KEY k, INPUT_EVENT_TYPE e);

	virtual void execute() override;

private:
	Inputable* ptrInputable;
	AZUL_KEY key;
	INPUT_EVENT_TYPE Event;
};


#endif // !INPUTABLEREGISTRSTIONCOMMAND
