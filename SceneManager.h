//SceneManager
//Daniel Goodrum, Jan 2018

#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "Scene.h"
#include "CommandBase.h"

class ChangeSceneCommand;
class VoidSceneCommand;
//class Scene;

class SceneManager
{

public:
	/// \brief Used to gain access to current Scene
	static Scene* GetCurrentScene() { return Instance().privGetCurrentScene(); }
	/// \brief Sets Start Scene, Should only be used once, in GameInitialize 
	static void SetStartScene(Scene* newScene) { Instance().ptrCurrentScene = newScene; }
	/// \brief Should be used only when you want to initialize the change to the next scene;
	static void SetNextScene(Scene* newScene) { Instance().privSetNextScene(newScene); }
	/// \brief Used by the engine to change scenes.
	static Scene* GetNextScene() { return Instance().ptrNextScene; }

	static void ExecuteSceneCommand() { Instance().privExecuteSceneCommand(); }

	static void ChangeScene(Scene* S) { Instance().privChangeScene(S); }

private:
	static SceneManager* ptrInstance;

	SceneManager();
	SceneManager &operator = (const SceneManager&) = delete;
	SceneManager(const SceneManager&) = delete;
	~SceneManager() = default;

	static SceneManager& Instance()
	{
		if (!ptrInstance)
		{
			ptrInstance = new SceneManager;
		}
		return *ptrInstance;
	}

	Scene* privGetCurrentScene() { return ptrCurrentScene; }

	friend class RumEngine;
	static void Delete() { Instance().privDelete(); }
	void privDelete();
	static void Draw() { Instance().ptrCurrentScene->Draw(); }
	static void InitStartScene() { Instance().ptrCurrentScene->Initialize(); }
	static void Update() { Instance().ptrCurrentScene->Update(); }

	void privExecuteSceneCommand();
	void privSetNextScene(Scene* newScene);
	void privChangeScene(Scene* S);


	VoidSceneCommand* defaultVoidCommand;
	ChangeSceneCommand* changeingCommand;
	CommandBase* NextCommand;

	Scene* ptrCurrentScene;
	Scene* ptrNextScene;


};

#endif // 
