#include "GameObjectExitCommand.h"
#include "GameObject.h"
#include "GameObjectAttorney.h"


GameObjectExitCommand::GameObjectExitCommand(GameObject * go)
	:ptrGameObject(go)
{
}

void GameObjectExitCommand::execute()
{
	GameObjectAttorney::Registration::DisconnectFromScene(ptrGameObject);
}
