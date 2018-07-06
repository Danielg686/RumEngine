//Draw Deregister Command
//Daniel Goodrum, Jan 2018

#ifndef DRAWDEREGISTERCOMMAND_H
#define DRAWDEREGISTERCOMMAND_H

#include "CommandBase.h"
class Drawable;

class DrawDeregisterCommand : public CommandBase
{
public:
	DrawDeregisterCommand() = delete;
	DrawDeregisterCommand(Drawable* dr);


	virtual void execute() override;

private:
	Drawable* ptrDrawable;

protected:


};
#endif // !DRAWDEREGISTERCOMMAND_H
