//Draw2D Registration Command
//Daniel Goodrum, Mar 2018

#ifndef DRAW2DREGISTRATIONCOMMAND_H
#define DRAW2DREGISTRATIONCOMMAND_H

#include "CommandBase.h"
class Drawable2D;

class Draw2DRegistrationCommand : public CommandBase
{
public :
	Draw2DRegistrationCommand() = delete;
	Draw2DRegistrationCommand(Drawable2D* dr);
	virtual ~Draw2DRegistrationCommand() = default;
	virtual void execute() override;


private:
	Drawable2D* ptrDrawable2D;
};



#endif // !DRAW2DREGISTRATIONCOMMAND_H
