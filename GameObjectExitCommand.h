//GameObject Exit Command
//Daniel Goodrum, Feb 2018

#ifndef GAMEOBJECTEXITCOMMAND_H
#define GAMEOBJECTEXITCOMMAND_H

#include "CommandBase.h"
class GameObject;

class GameObjectExitCommand : public CommandBase
{
public:
	GameObjectExitCommand() = delete;
	GameObjectExitCommand(GameObject* go);

	virtual void execute() override;

private:

	GameObject* ptrGameObject;


};




#endif // !GAMEOBJECTEXITCOMMAND_H
