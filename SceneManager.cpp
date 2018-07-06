#include "SceneManager.h"
#include "VoidSceneCommand.h"
#include "ChangeSceneCommand.h"
#include "SceneAttorney.h"
#include "VisualizerAttorney.h"


SceneManager* SceneManager::ptrInstance = nullptr;

SceneManager::SceneManager()
	:ptrCurrentScene(nullptr), ptrNextScene(nullptr)
{
	defaultVoidCommand = new VoidSceneCommand();
	NextCommand = defaultVoidCommand;
	changeingCommand = new ChangeSceneCommand(nullptr);
}

void SceneManager::privDelete()
{
	delete defaultVoidCommand;
	delete changeingCommand;
//	ptrCurrentScene->EndScene();
	delete ptrCurrentScene;
	delete ptrInstance;
	ptrInstance = nullptr;
}

void SceneManager::privExecuteSceneCommand()
{
	NextCommand->execute();
	NextCommand = defaultVoidCommand;
}

void SceneManager::privSetNextScene(Scene * newScene)
{
	changeingCommand->updateScene(newScene);
	NextCommand = changeingCommand;
}

void SceneManager::privChangeScene(Scene * S)
{
	Scene* temp = ptrCurrentScene;
	SceneAttorney::Unload::UnloadScene(temp);
	VisualizerAttorney::GameLoop::Delete();
	delete temp;
	ptrCurrentScene = S;
	S->Initialize();
}
