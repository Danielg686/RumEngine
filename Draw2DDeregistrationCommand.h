//Draw2dDeregistrationCommand
//Daniel Goodrum, Mar 2018

#ifndef DRAW2DDEREGISTRATIONCOMMAND_H
#define DRAW2DDEREGISTRATIONCOMMAND_H

#include "CommandBase.h"
class Drawable2D;

class Draw2DDeregistrationCommand :public CommandBase
{
public:
	Draw2DDeregistrationCommand() = delete;
	Draw2DDeregistrationCommand(Drawable2D* dr);

	virtual void execute() override;

private:
	Drawable2D* ptrDrawable;
};



#endif // !DRAW2DDEREGISTRATIONCOMMAND_H
