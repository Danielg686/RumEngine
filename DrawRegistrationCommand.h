//Draw Registration Command
//Daniel Goodrum, Jan 2018

#ifndef DRAWREGISTRATIONCOMMAND_H
#define DRAWREGISTRATIONCOMMAND_H

#include "CommandBase.h"
class Drawable;


class DrawRegistrationCommand : public CommandBase
{


public:
	DrawRegistrationCommand() = delete;
	DrawRegistrationCommand(Drawable* dr);


	virtual void execute() override;

private:
	Drawable* ptrDrawable;

protected:

};


#endif // !DRAWREGISTRATIONCOMMAND_H