//GameObject
//Daniel Goodrum, Jan 2018

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Alarmable.h"
#include "Updatable.h"
#include "Drawable.h"
#include "Inputable.h"
#include <malloc.h>
#include "Align16.h"
#include "Collidable.h"
#include "Drawable2D.h"

class GameObjectEntryCommand;
class GameObjectExitCommand;

class GameObject : public virtual Updatable, public virtual Drawable, public virtual Alarmable, public virtual Align16, public virtual Inputable, public virtual Collidable, public virtual Drawable2D
{
	friend class GameObjectAttorney;

public:
	GameObject();
	virtual ~GameObject();


	/// \ingroup DEFAULTEVENTS
	/// \brief Optional function, code can be placed in SceneEntry that will be 
	/// implimented when GameObject::SubmitEntry() is executed.
	/// \code
	///	
	///		Bullet::Bullet()
	///		{
	///			this->SubmitEntry();
	///		}
	///		void Bullet::SceneEntry()
	///		{	
	///
	///		this->SubmitDrawRegistration();
	///		this->SubmitUpdateRegistration();
	///		this->SubmitAlarmRegistration0(4.0f);
	///
	///		this->CollisionRegistration<Bullet>(this);
	///		}
	///
	///\endcode
	virtual void SceneEntry();
	
	/// \ingroup DEFAULTEVENTS
	/// \brief Optional function, code can be placed in SceneExit that will be 
	/// implimented when GameObject::SubmitExit() is executed.
	/// \code
	///	
	///		void Bullet::Destroy()
	///		{
	///			this->SubmitExit();
	///		}
	///		void Bullet::SceneExit()
	///		{	
	///
	///		this->SubmitDrawDeregistration();
	///		this->SubmitUpdateDeregistration();
	///		this->SubmitAlarmDeregistration0();
	///
	///		this->CollisionDeregistration<Bullet>(this);
	///		}
	///
	///\endcode
	virtual void SceneExit();

private:

	RegistrationState CurrRegState;
	GameObjectEntryCommand* ptrEntryCommand;
	GameObjectExitCommand* ptrExitCommand;

	virtual void ConnectToScene();
	virtual void DisconnectFromScene();




protected:
	virtual void SubmitEntry();
	virtual void SubmitExit();
	//virtual ~GameObject() { DebugMsg::out("GameObject class destructor called\n"); }
};
#endif // !GAMEOBJECT_H
