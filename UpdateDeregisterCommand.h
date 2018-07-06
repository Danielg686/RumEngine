//Update Deregister Command
//Daniel Goodrum, Jan 2018

#ifndef UPDATEDEREGISTERCOMMAND_H
#define UPDATEDEREGISTERCOMMAND_H

#include "CommandBase.h"
class Updatable;

class UpdateDeregisterCommand : public CommandBase
{
public:
	UpdateDeregisterCommand() = delete;
	UpdateDeregisterCommand(Updatable* up);

	virtual void execute() override;

private:
	Updatable* ptrUpdatable;

protected:

};




#endif // !UPDATEDEREGISTERCOMMAND_H
