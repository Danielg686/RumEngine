//Update Registration Command
//Daniel Goodrum, Jan 2018

#ifndef UPDATEREGISTRATIONCOMMAND_H
#define UPDATEREGISTRATIONCOMMAND_H

#include "CommandBase.h"
class Updatable;


class UpdateRegistrationCommand : public CommandBase
{


public:
	UpdateRegistrationCommand() = delete;
	UpdateRegistrationCommand(Updatable* up);

	virtual void execute() override;

private:
	Updatable* ptrUpdatable;

protected:

};



#endif // !UPDATEREGISTRATIONCOMMAND_H
