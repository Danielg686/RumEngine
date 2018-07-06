//GameObject Attorney
//Daniel Goodrum, Feb 2018

#ifndef GAMEOBJECTATTORNEY_H
#define GAMEOBJECTATTORNEY_H

#include "GameObject.h"

class GameObjectAttorney
{
public:
	class Registration
	{
	private:
		friend class GameObjectEntryCommand;
		friend class GameObjectExitCommand;

		///		\brief Passthrough for GameObject Entry into scene.
		static void ConnectToScene(GameObject* pMgr) { pMgr->ConnectToScene(); }
		///		\brief Passthrough for GameObject to be disconnected from scene.
		static void DisconnectFromScene(GameObject* pMgr) { pMgr->DisconnectFromScene(); }
	};





};






#endif // !GAMEOBJECTATTORNEY_H
