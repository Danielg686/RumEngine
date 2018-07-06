#include "Scene.h"
#include "SceneManager.h"
//#include "DrawableManager.h"
//#include "UpdatableManager.h"
#include "SceneRegistrationBroker.h"
#include "CameraManagerNonSingleton.h"
#include "CollisionManager.h"
#include "VisualizerAttorney.h"
#include "TerrainManager.h"
//#include "Drawable2DManager.h"
//#include "AlarmManager.h"
#include "TerrainSceneLevelManager.h"
Scene::Scene()
{
	pDrawManager = new DrawableManager();
	pDraw2DManager = new Drawable2DManager();
	pUpdateManager = new UpdatableManager();
	pAlarmManager = new AlarmManager();
	pKeyboardEventManager = new KeyboardEventManager();

	pCamManager = new CameraManagerNonSingleton();
	pCollisionManager = new CollisionManager();

	pRegistrationBroker = new SceneRegistrationBroker();

	pTerrainLevelManager = new TerrainSceneLevelManager();

	pTerrainModel = nullptr;
}

Scene::~Scene()
{
	DebugMsg::out("Scene class destructor called\n"); 
	
	delete pDrawManager;
	delete pUpdateManager;
	delete pAlarmManager;
	delete pKeyboardEventManager;
	delete pCollisionManager;
	delete pRegistrationBroker;
	delete pDraw2DManager;
	delete pCamManager;
	delete pTerrainLevelManager;
}

void Scene::Draw()
{
	pDrawManager->ProcessElements();
	pDraw2DManager->ProcessElements();
}

void Scene::Update()
{
	pRegistrationBroker->executeCommands();

	pCollisionManager->ProcessCollisions();

	pAlarmManager->ProcessAlarms();

 	pKeyboardEventManager->ProcessKeyEvents();

	pUpdateManager->ProcessElements();
}


void Scene::Register(Updatable * up, UpdatableManager::UpdatableListRef& ref)
{
	pUpdateManager->Register(up, ref);
}

void Scene::Register(Drawable * dr, DrawableManager::DrawableListRef& ref)
{
	pDrawManager->Register(dr, ref);
}

void Scene::Register(Drawable2D * dr, Drawable2DManager::Drawable2DListRef & ref)
{
	pDraw2DManager->Register(dr, ref);
}





void Scene::Register(float t, Alarmable* al, AlarmManager::ALARM_ID id, AlarmManager::StorageListRef& ref)
{
	pAlarmManager->Register(t, al, id, ref);
}

void Scene::Register(Inputable * in, AZUL_KEY k, INPUT_EVENT_TYPE e)
{
	pKeyboardEventManager->Register(in, k, e);
}


void Scene::Deregister(Updatable * up, UpdatableManager::UpdatableListRef& ref)
{
	pUpdateManager->Degregister(up, ref);
}

void Scene::Deregister(Drawable * dr, DrawableManager::DrawableListRef & ref)
{
	//pDrawManager->Deregister(dr, ref);
	pDrawManager->Deregister(dr, ref);
}

void Scene::Deregister(Drawable2D * dr, Drawable2DManager::Drawable2DListRef & ref)
{
	pDraw2DManager->Deregister(dr, ref);
}


void Scene::Deregister(Alarmable* al, AlarmManager::ALARM_ID id)
{
	pAlarmManager->Deregister(al, id);
}

void Scene::Deregister(Inputable * in, AZUL_KEY k, INPUT_EVENT_TYPE e)
{
	pKeyboardEventManager->Deregister(in, k, e);
}


void Scene::SubmitCommand(CommandBase * cmd)
{
	pRegistrationBroker->addCommands(cmd);
}

void Scene::SetTerrain(std::string TerrainName)
{
	pTerrainLevelManager->SetTerrain(TerrainName);
	pTerrainModel = pTerrainLevelManager->GetTerrain();
}

void Scene::AddCollisionGroupDelete(CollisionTestCommandBase * cmd)
{
	pCollisionManager->RegisterDeleteCommand(cmd);
}
//
//void Scene::GetCurrentCamera(Camera& cam)
//{
//	 return pCamManager->getCurrentCamera();
//}

Camera * Scene::GetCurrentCamera()
{
	return pCamManager->getCurrentCamera();
}

void Scene::SetCurrentCamera(Camera* cam)
{
	pCamManager->setCurrentCamera(cam);
}

Camera * Scene::Get2Dcam()
{
	return pCamManager->get2DCamera(); 
}

//void Scene::SetGodCamera()
//{
//	pCamManager->SetGodCamera();
//}
