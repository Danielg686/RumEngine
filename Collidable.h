//Collidable
//Daniel Goodrum, Feb 2018

#ifndef COLLIDABLE_H
#define COLLIDABLE_H

#include "AzulCore.h"
//#include "SceneRegistrationCommand.h"
#include "CollisionRegistrationCommand.h"
#include "CollisionDeregistrationCommand.h"
#include "SceneAttorney.h"
#include "VolumeType.h"
//#include "CollisionVolumeBSphere.h"
//#include "CollisionVolume.h"
//#include "GameObject.h"
//class Frigate;

class CollisionVolume;

class Collidable
{
private:
	SceneRegistrationCommand* pRegisterCommand;
	SceneRegistrationCommand* pDeregisterCommand;

	CollisionVolume* ColVolume;
	CollisionVolumeBSphere* DefaultBSphere;
	//CollisionVolumeBSphere BSphere;
	Model* pColModel;

public:
	Collidable()
		:pRegisterCommand(nullptr), pDeregisterCommand(nullptr), ColVolume(nullptr), DefaultBSphere(nullptr)
	{};
//	friend class CollidableGroupAttorney;
//	friend class SceneRegistrationCommand;

	virtual void Collision(Collidable*) { DebugMsg::out("Collidable Collision \n"); }
	virtual ~Collidable()
	{
		delete pRegisterCommand;
		delete pDeregisterCommand;
		//if (ColVolume != nullptr)
		//{
		//	delete ColVolume;
		//}
	//	delete ColVolume;
		//delete pColModel;
		DebugMsg::out("Collidable Destructor called \n");
	}

	//const CollisionVolumeBSphere& GetBSphere() const { return BSphere; }
	const CollisionVolume& GetColVolume() const { return *ColVolume; }

	const CollisionVolumeBSphere& GetStandardBSphere() const { return *DefaultBSphere; }

protected:
	template<typename C1>
	void CollisionRegistration(C1* c)
	{
		if (pRegisterCommand == nullptr)
		{
			pRegisterCommand = new CollisionRegistrationCommand<C1>(c);
		}
		SceneAttorney::Registration::SubmitCommand(SceneManager::GetCurrentScene(), pRegisterCommand);
	}

	template<typename C>
	void CollisionDeregistration(C* c)
	{
		if (pDeregisterCommand == nullptr)
		{
			pDeregisterCommand = new CollisionDeregistrationCommand<C>(c);
		}
		SceneAttorney::Registration::SubmitCommand(SceneManager::GetCurrentScene(), pDeregisterCommand);
	}

	/// \brief Sets the Model that is used to Register Collision data within the system, Does not have to be same model that is visualized
	void SetColliderModel(Model* mod, VolumeType vol) 
	{

		assert(vol == VolumeType::BSPHERE || vol == VolumeType::AABB || vol == VolumeType::OBB);
		pColModel = mod;
		DefaultBSphere = new CollisionVolumeBSphere();
		switch (vol)
		{
		case VolumeType::BSPHERE:
			ColVolume = DefaultBSphere;
			break;
		case VolumeType::AABB:
			ColVolume = new CollisionVolumeAABB(mod);
			break;
		case VolumeType::OBB:
			ColVolume = new CollisionVolumeOBB(mod);
			break;
		default:
			break;
		}
		
	}
	/// \brief Updates Collision Data with current world Matrix
	void UpdateCollisionData(Matrix& mat);//TODO

};



#endif // !COLLIDABLE_H

