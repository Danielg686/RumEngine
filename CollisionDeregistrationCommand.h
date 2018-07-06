//CollisionDeregistrationCommand
//Daniel Goodrum, Feb 2018

#ifndef COLLISIONDEREGISTRATIONCOMMAND_H
#define COLLISIONDEREGISTRATIONCOMMAND_H

#include "SceneRegistrationCommand.h"
#include "CollidableGroup.h"

class SceneRegistrationCommand;

template <typename C>
class CollisionDeregistrationCommand : public SceneRegistrationCommand
{
private:
	C* ptrCol;

public:
	CollisionDeregistrationCommand() = delete;
	CollisionDeregistrationCommand(C* c)
		:ptrCol(c)
	{};

	virtual void execute() override
	{
		//TODO
		CollidableGroup<C>::privDeregister(ptrCol);
	}

};

#endif // !COLLISIONDEREGISTRATIONCOMMAND_H
