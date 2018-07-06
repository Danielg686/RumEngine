//CollidableGroup
//Daniel Goodrum

#ifndef COLLIDABLEGROUP_H
#define COLLIDABLEGROUP_H

#include <set>
//#include "Collidable.h"
#include "CollidableGroupBase.h"
#include "CollisionVolumeAABB.h"


class CollisionManager;
class SceneAttorney;

template< typename C>
class CollidableGroup : public CollidableGroupBase
{
	//template <typename C>
	//friend class CollidableGroupAttorney

public:
	using CollidableCollection = std::set<C*>;


private:
	template<typename C>
	friend class CollisionRegistrationCommand;
	template<typename C>
	friend class CollisionDeregistrationCommand;
	template<typename C>
	friend class CollisionTestSelfCommand;
	template<typename C, typename D>
	friend class CollisionTestPairCommand;
	friend class CollisionManager;

	template<typename C>
	friend class CollisionTestTerrainCommand;

	static CollidableGroup* ptrInstance;

	/// \brief Creates a new GollidableGroup for each class of object created.
	/// Allows for each object type to be compared to others.
	

	CollidableGroup<C>() 
	{
		CollidableGroupDeleteCommand* temp = new CollidableGroupDeleteCommand(this);
		//SceneAttorney::Registration::SubmitCollisionGroupDelete(SceneManager::GetCurrentScene(), temp);
		SceneManager::GetCurrentScene()->AddCollisionGroupDelete(temp);
	}
	CollidableGroup<C> &operator = (const CollidableGroup<C>&) = delete;
	CollidableGroup<C>(const CollidableGroup<C>&) = delete;
	virtual ~CollidableGroup<C>() = default;

	static CollidableGroup<C>& Instance()
	{
		if (!ptrInstance)
		{
			ptrInstance = new CollidableGroup<C>;
		}
		return *ptrInstance;
	}

	
	typename CollidableCollection ColCollection;

	static void Register(C* p)
	{
		Instance().ColCollection.insert(p);
	}

	static void privDeregister(C* p)
	{
		Instance().ColCollection.erase(p);
	}

	static const CollidableCollection& GetColliderCollection()
	{
		return Instance().ColCollection;
	}

	//void privDelete()
	//{
	//	delete ptrInstance;
	//	ptrInstance = nullptr;
	//}
	virtual void Delete() override
	{
		DebugMsg::out("Collision Group Delete Called\n");
		delete ptrInstance;
		ptrInstance = nullptr;
	}


	static void GetGroupAABB(CollisionVolumeAABB & CollGroup1AABB, const CollidableCollection& Collection1)
	{
		auto it1 = Collection1.begin();
		if (it1 != Collection1.end())
		{
			CollisionVolumeBSphere temp = (*it1)->GetStandardBSphere();
			float minX, minY, minZ, maxX, maxY, maxZ;
			minX = temp.GetCenter().X() - temp.GetRadius();
			minY = temp.GetCenter().Y() - temp.GetRadius();
			minZ = temp.GetCenter().Z() - temp.GetRadius();
			maxX = temp.GetCenter().X() + temp.GetRadius();
			maxY = temp.GetCenter().Y() + temp.GetRadius();
			maxZ = temp.GetCenter().Z() + temp.GetRadius();
			//it1++;
			for (it1; it1 != Collection1.end(); it1++)
			{
				temp = (*it1)->GetStandardBSphere();
				if ((temp.GetCenter().X() - temp.GetRadius()) < minX)
				{
					minX = temp.GetCenter().X() - temp.GetRadius();
				}
				if ((temp.GetCenter().Y() - temp.GetRadius()) < minY)
				{
					minY = temp.GetCenter().Y() - temp.GetRadius();
				}
				if ((temp.GetCenter().Z() - temp.GetRadius()) < minZ)
				{
					minZ = temp.GetCenter().Z() - temp.GetRadius();
				}
				if ((temp.GetCenter().X() + temp.GetRadius()) > maxX)
				{
					maxX = temp.GetCenter().X() + temp.GetRadius();
				}
				if ((temp.GetCenter().Y() + temp.GetRadius()) > maxY)
				{
					maxY = temp.GetCenter().Y() + temp.GetRadius();
				}
				if ((temp.GetCenter().Z() + temp.GetRadius()) > maxZ)
				{
					maxZ = temp.GetCenter().Z() + temp.GetRadius();
				}
			}
			CollGroup1AABB.SetMinAndMax(Vect(minX, minY, minZ), Vect(maxX, maxY, maxZ));
		}
	}
public:

};


template<typename C>
CollidableGroup<C>* CollidableGroup<C>::ptrInstance = nullptr;



#endif // !COLLIDABLEGROUP_H

//template<typename C>
//inline void CollidableGroup<C>::Register(C * p)
//{
//	this->ColCollection.push_back(p);
//}

//template<typename C>
//inline void CollidableGroup<C>::Deregister(C * p)
//{
//	this->ColCollection.erase(p);
//}

//template<typename C>
//const CollidableCollection& CollidableGroup<C>::GetColliderCollection()
//{
//	return this->ColCollection;
//	// TODO: insert return statement here
//}

//template<typename C>
//inline void CollidableGroup<C>::privDelete()
//{
//		delete ptrInstance;
//		ptrInstance = nullptr;
//}
