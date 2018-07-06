#include "GameObjectEntryCommand.h"
#include "GameObject.h"
#include "GameObjectAttorney.h"

GameObjectEntryCommand::GameObjectEntryCommand(GameObject * go)
	:ptrGameObject(go)
{
}

void GameObjectEntryCommand::execute()
{
	GameObjectAttorney::Registration::ConnectToScene(ptrGameObject);
}
