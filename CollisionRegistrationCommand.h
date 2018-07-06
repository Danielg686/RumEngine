//CollisionRegistrationCommand
//Daniel Goodrum, Feb 2018

#ifndef COLLISIONREGISTRATIONCOMMAND_H
#define COLLISIONREGISTRATIONCOMMAND_H

#include "SceneRegistrationCommand.h"
#include "CollidableGroup.h"

class SceneRegistrationCommand;

template <typename C>
class CollisionRegistrationCommand : public SceneRegistrationCommand
{
private:
	C* ptrCol;

public:
	CollisionRegistrationCommand() = delete;

	///		Creates a collision registration command for any game object
	CollisionRegistrationCommand(C* c)
		:ptrCol(c)
	{};



	virtual void execute() override
	{
		//TODO
		CollidableGroup<C>::Register(ptrCol);
	}

};




#endif // !COLLISIONREGISTRATIONCOMMAND_H
