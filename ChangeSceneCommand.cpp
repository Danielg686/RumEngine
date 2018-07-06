#include "ChangeSceneCommand.h"
#include "SceneManager.h"

ChangeSceneCommand::ChangeSceneCommand(Scene * S)
	:newScene(S)
{
}

void ChangeSceneCommand::updateScene(Scene * S)
{
	newScene = S;
}

void ChangeSceneCommand::execute()
{
	SceneManager::ChangeScene(newScene);
}
