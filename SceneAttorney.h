//SceneAttorney
//Daniel Goodrum Feb 2018


#ifndef SCENEATTORNEY_H
#define SCENEATTORNEY_H


#include "Drawable.h"
#include "DrawableManager.h"
#include "AzulCore.h"
#include "Camera.h"
#include "Alarmable.h"
#include "AlarmManager.h"
#include "Updatable.h"
#include "UpdatableManager.h"
#include "CameraManagerNonSingleton.h"
#include "SceneManager.h"
#include "CommandBase.h"
#include "CollidableGroup.h"
#include "Drawable2D.h"
#include "CollisionTestTerrainCommand.h"


class SceneAttorney
{
public:
	class Registration
	{
	private:
		friend class Drawable;
		friend class Alarmable;
		friend class Updatable;
		friend class Inputable;
		friend class GameObject;
		friend class Collidable;
		friend class Drawable2D;
		//template<typename C>
		//friend class CollidableGroup<C>;

		///		\brief Passthrough to Register Drawable to current Scene.
		static void Register(Scene* sc, Drawable* dr, DrawableManager::DrawableListRef& ref) { sc->Register(dr, ref); }

		static void Register(Scene* sc, Drawable2D* dr, Drawable2DManager::Drawable2DListRef& ref) { sc->Register(dr, ref); }
		///		\brief Passthrough to Register Alarmable to current Scene.
		static void Register(Scene* sc, float t, Alarmable* al, AlarmManager::ALARM_ID id, AlarmManager::StorageListRef& ref) { sc->Register(t, al, id, ref); }
		///		\brief Passthrough to Register Updatable to current Scene.
		static void Register(Scene* sc, Updatable* up, UpdatableManager::UpdatableListRef& ref) { sc->Register(up, ref); }
		///		\brief Passthrough to Register Inputable to current Scene.
		static void Register(Scene* sc, Inputable* in, AZUL_KEY k, INPUT_EVENT_TYPE e) { sc->Register(in, k, e); }

		///		\brief Passthrough to Deregister Drawable from current Scene.
		static void Deregister(Scene* sc,Drawable* dr, DrawableManager::DrawableListRef& ref) { sc->Deregister(dr, ref); }

		static void Deregister(Scene* sc, Drawable2D* dr, Drawable2DManager::Drawable2DListRef& ref) { sc->Deregister(dr, ref); }
		///		\brief Passthrough to Deregister Alarmable from current Scene.
		static void Deregister(Scene* sc, Alarmable* al, AlarmManager::ALARM_ID id) { sc->Deregister(al, id); }
		///		\brief Passthrough to Deregister Updatable from current Scene.
		static void Deregister(Scene* sc, Updatable* up, UpdatableManager::UpdatableListRef& ref) { sc->Deregister(up, ref); }
		///		\brief Passthrough to Deregister Inputable from current Scene.
		static void Deregister(Scene* sc, Inputable* in, AZUL_KEY k, INPUT_EVENT_TYPE e) { sc->Deregister(in, k, e); }
	
		///		\brief Passthrough to Submit any command to current Scene.
		static void SubmitCommand(Scene* sc, CommandBase* cmd) { sc->SubmitCommand(cmd); }

		///		\brief Deletes Collision groups.
		static void SubmitCollisionGroupDelete(Scene* sc, CollidableGroupDeleteCommand* cmd) { sc->AddCollisionGroupDelete(cmd); }
		
	};
	class Unload
	{
	private:
		friend class RumEngine;
		friend class SceneManager;
		///		\brief Passthrough for Engine to Unload Current Scene.
		static void UnloadScene(Scene* sc) { sc->EndScene(); }

	};

	//class CameraStuff
	//{
	//public:

	//	static Camera* GetCurrentCamera(Scene* sc) { return sc->GetCurrentCamera(); }
	//	static void SetCurrentCamera(Scene* sc, Camera* cam) { sc->SetCurrentCamera(cam); }
	//};
	
};



#endif // !SCENEATTORNEY_H
