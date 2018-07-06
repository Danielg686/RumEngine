//InputableDeRegistrationCommand
//Daniel Goodrum, Feb 2018

#ifndef INPUTABLEDEREGISTRATIONCOMMAND_H
#define INPUTABLEDEREGISTRATIONCOMMAND_H

#include "CommandBase.h"
#include "AzulCore.h"
#include "Input_Event_Type.h"

class Inputable;

class InputableDeregistrationCommand : public CommandBase
{
public:
	InputableDeregistrationCommand() = delete;
	InputableDeregistrationCommand(Inputable* in, AZUL_KEY k, INPUT_EVENT_TYPE e);

	virtual void execute() override;

private:
	Inputable* ptrInputable;
	AZUL_KEY key;
	INPUT_EVENT_TYPE Event;

};
#endif // !INPUTABLEDEREGISTRATIONCOMMAND_H
