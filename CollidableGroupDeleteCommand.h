//CollidableGroupDeleteCommand
//Daniel Goodrum, Feb 2018

#ifndef COLLIDABLEGROUPDELETECOMMAND_H
#define COLLIDABLEGROUPDELETECOMMAND_H

#include "CollisionTestCommandBase.h"
#include "CollidableGroup.h"
#include "CollidableGroupBase.h"


class CollidableGroupDeleteCommand : public CollisionTestCommandBase
{
private:
	CollidableGroupBase* pColGroup;
public:
	CollidableGroupDeleteCommand() = delete;
	CollidableGroupDeleteCommand(CollidableGroupBase* p)
		:pColGroup(p)
	{};

	virtual void execute() override
	{
		pColGroup->Delete();
	}

};





#endif // !COLLIDABLEGROUPDELETECOMMAND_H
