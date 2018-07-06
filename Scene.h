//Scene
//Daniel Goodrum, Jan 2018

#ifndef SCENE_H
#define SCENE_H

#include "RumEngine.h"
#include "AlarmManager.h"
#include "UpdatableManager.h"
#include "DrawableManager.h"
#include "Drawable2DManager.h"
#include "KeyboardEventManager.h"
#include "CollisionManager.h"
#include "CollidableGroup.h"

class Updatable;
class Drawable;
class CommandBase;
class DrawableManager;
class UpdatableManager;
class SceneRegistrationBroker;
class AlarmManager;
class CameraManagerNonSingleton;
class CollisionManager;
class Collidable;
class Drawable2D;
class TerrainModel;
class TerrainSceneLevelManager;
//class Drawable2DManager;

class Scene
{
	friend class SceneManager;

	//friend class Updatable;
	//friend class Drawable;
	//friend class Alarmable;

	

public:
	///\brief BaseClass that all scenes inharit from
	///  provides processing features to run during the game cycle
	///  Manages the Draw and Update calls within the scene.
	Scene();
	Scene(const Scene&) = delete;
	Scene& operator= (const Scene&) = delete;

	virtual ~Scene();


	virtual Camera* GetCurrentCamera();
	virtual void SetCurrentCamera(Camera* cam);
	virtual Camera* Get2Dcam();

	virtual void SetTerrain(std::string TerrainName);

	virtual TerrainModel* GetTerrainModel() { return pTerrainModel; }
	//virtual void SetGodCamera();

	//for testing needs to be changed
	virtual void AddCollisionGroupDelete(CollisionTestCommandBase* cmd);
private:
	
	friend class SceneAttorney;

	virtual void Draw();
	/// \brief Initialize is where User classes should be created for the given Scene;
	virtual void Initialize() = 0;
	virtual void Update();
	/// \brief EndScene is for User cleanup, similar to a destructor
	virtual void EndScene() {};

	//Registration services
	virtual void Register(Updatable* up, UpdatableManager::UpdatableListRef& ref);
	virtual void Register(Drawable* dr, DrawableManager::DrawableListRef& ref);
	virtual void Register(Drawable2D* dr, Drawable2DManager::Drawable2DListRef& ref);
	virtual void Register(float t, Alarmable* al, AlarmManager::ALARM_ID id, AlarmManager::StorageListRef& ref) ;
	virtual void Register(Inputable* in, AZUL_KEY k, INPUT_EVENT_TYPE e);
	
	//virtual void Register(Collidable* co);

	virtual void Deregister(Updatable* up, UpdatableManager::UpdatableListRef& ref);
	virtual void Deregister(Drawable* dr, DrawableManager::DrawableListRef& ref);
	virtual void Deregister(Drawable2D*dr, Drawable2DManager::Drawable2DListRef& ref);
	virtual void Deregister(Alarmable* al, AlarmManager::ALARM_ID id);
	virtual void Deregister(Inputable* in, AZUL_KEY k, INPUT_EVENT_TYPE e);
	//virtual void Deregister(Collidable* co);
	 
	//Command Pattern
	virtual void SubmitCommand(CommandBase* cmd);

//	virtual void AddCollisionGroupDelete(CollisionTestCommandBase* cmd);
	


	DrawableManager* pDrawManager;
	Drawable2DManager* pDraw2DManager;
	UpdatableManager* pUpdateManager;
	AlarmManager* pAlarmManager;
	KeyboardEventManager* pKeyboardEventManager;
	CollisionManager* pCollisionManager;
	TerrainSceneLevelManager* pTerrainLevelManager;


	TerrainModel* pTerrainModel;

	SceneRegistrationBroker* pRegistrationBroker;

	CameraManagerNonSingleton* pCamManager;
	
protected:
	///\brief Sets a collision test pair between two game objects
	///		this will be used by the collision system to determine  
	///		if their Collision Volumes intersect.
	///\code
	///	this->SetCollisionPair<Tank, Bullet>()
	///\endcode
	template <typename C1, typename C2>
	void SetCollisionPair()
	{
		this->pCollisionManager->SetCollisionPair<C1, C2>();
	}

	///\brief Sets a collision test between two game objects
	///		this will be used by the collision system to determine 
	///		if an object collides with anothoer opject of the same
	///		type
	///		
	///\code
	///	this->SetCollisionSelf<Tank>()
	///\endcode
	template<typename C>
	void SetCollisionSelf()
	{
		this->pCollisionManager->SetCollisionSelf<C>();
	}

	///\brief Sets a collision test pair between a GameObject and 
	///		the current Terrain that is set
	///	
	///		
	///\code
	///	this->SetCollisionTerrain<Tank>()
	///\endcode
	template<typename C>
	void SetCollisionTerrain()
	{
		assert(pTerrainModel != nullptr);
		this->pCollisionManager->SetCollisionTerrain<C>();
	}

	//void DeleteScene();

};

#endif // !SCENE_H

