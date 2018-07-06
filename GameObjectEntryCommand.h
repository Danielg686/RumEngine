//Game Object Entry Command
//Daniel Goodrum, Feb 2018

#ifndef GAMEOBJECTENTRYCOMMAND_H
#define GAMEOBJECTENTRYCOMMAND_H

#include "CommandBase.h"
class GameObject;

class GameObjectEntryCommand : public CommandBase
{
public:
	GameObjectEntryCommand() = delete;
	GameObjectEntryCommand(GameObject* go);

	virtual void execute() override;

private:

	GameObject* ptrGameObject;
};

#endif // !GAMEOBJECTENTRYCOMMAND_H
