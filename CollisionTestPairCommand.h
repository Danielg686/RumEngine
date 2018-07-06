//CollisionTestPairCommand
//Daniel Goodrum

#ifndef COLLISIONTESTPAIRCOMMAND_H
#define COLLISIONTESTPAIRCOMMAND_H

#include "CollisionTestCommandBase.h"
#include "CollidableGroup.h"
#include "CollisionVolumeBSphere.h"
#include "CollisionVolumeAABB.h"
#include "MathTools.h"
#include "Color.h"
#include "Visualizer.h"
//#include "Collidable.h"
//#include "CollisionManager.h"

template< typename C1, typename C2>
class CollisionTestPairCommand : public CollisionTestCommandBase
{
private:
	typename const CollidableGroup<C1>::CollidableCollection& Collection1;
	typename const CollidableGroup<C2>::CollidableCollection& Collection2;


public:
	CollisionTestPairCommand()
		:Collection1(CollidableGroup<C1>::GetColliderCollection()), Collection2(CollidableGroup<C2>::GetColliderCollection())
	{};

	virtual void execute() override
	{
		CollisionVolumeAABB CollGroup1AABB; // = new CollisionVolumeAABB();
		CollisionVolumeAABB CollGroup2AABB; // = new CollisionVolumeAABB();

		CollidableGroup<C1>::GetGroupAABB(CollGroup1AABB, Collection1);
		CollidableGroup<C2>::GetGroupAABB(CollGroup2AABB, Collection2);
		bool test_result = MathTools::Intersect(CollGroup1AABB, CollGroup2AABB);

		if (test_result)
		{
			Visualizer::ShowGroupAABB(CollGroup1AABB, Color::Orange);
			Visualizer::ShowGroupAABB(CollGroup2AABB, Color::Orange);
			for (auto it1 = Collection1.begin(); it1 != Collection1.end(); it1++)
			{
				test_result = MathTools::Intersect((*it1)->GetStandardBSphere(), CollGroup2AABB);
				if (test_result)
				{
					Visualizer::ShowBSphere((*it1)->GetStandardBSphere(), Color::Orange);
				
					for (auto it2 = Collection2.begin(); it2 != Collection2.end(); it2++)
					{
						test_result = MathTools::Intersect((*it1)->GetStandardBSphere(), (*it2)->GetStandardBSphere());

						if (test_result)
						{
							test_result = MathTools::Intersect(*it1, *it2);
							if (test_result)
							{
								(*it1)->Collision(*it2);
								(*it2)->Collision(*it1);
								Visualizer::ShowCollisionVolume(*it1, Color::Orange);
								Visualizer::ShowCollisionVolume(*it2, Color::Orange);
							}
							else
							{
								Visualizer::ShowCollisionVolume(*it1, Color::Blue);
								Visualizer::ShowCollisionVolume(*it2, Color::Blue);
							}
						}
						
					}
				}
				else
				{
			//		Visualizer::ShowBSphere((*it1)->GetStandardBSphere(), Color::Aquamarine);
				}
			}
		
		}
		else
		{
		//	Visualizer::ShowGroupAABB(CollGroup1AABB, Color::Aquamarine);
		//	Visualizer::ShowGroupAABB(CollGroup2AABB, Color::Aquamarine);
		}
	}
	
	//void GetGroupAABB(CollisionVolumeAABB & CollGroup1AABB , CollisionVolumeAABB& CollGroup2AABB)
	//{
	//	auto it1 = Collection1.begin();
	//	if (it1 != Collection1.end())
	//	{
	//		CollisionVolumeBSphere temp = (*it1)->GetStandardBSphere();
	//		float minX, minY, minZ, maxX, maxY, maxZ;
	//		minX = temp.GetCenter().X() - temp.GetRadius();
	//		minY = temp.GetCenter().Y() - temp.GetRadius();
	//		minZ = temp.GetCenter().Z() - temp.GetRadius();
	//		maxX = temp.GetCenter().X() + temp.GetRadius();
	//		maxY = temp.GetCenter().Y() + temp.GetRadius();
	//		maxZ = temp.GetCenter().Z() + temp.GetRadius();
	//		//it1++;
	//		for (it1; it1 != Collection1.end(); it1++)
	//		{
	//			temp = (*it1)->GetStandardBSphere();
	//			if ((temp.GetCenter().X() - temp.GetRadius()) < minX)
	//			{
	//				minX = temp.GetCenter().X() - temp.GetRadius();
	//			}
	//			if ((temp.GetCenter().Y() - temp.GetRadius()) < minY)
	//			{
	//				minY = temp.GetCenter().Y() - temp.GetRadius();
	//			}
	//			if ((temp.GetCenter().Z() - temp.GetRadius()) < minZ)
	//			{
	//				minZ = temp.GetCenter().Z() - temp.GetRadius();
	//			}
	//			if ((temp.GetCenter().X() + temp.GetRadius()) > maxX)
	//			{
	//				maxX = temp.GetCenter().X() + temp.GetRadius();
	//			}
	//			if ((temp.GetCenter().Y() + temp.GetRadius()) > maxY)
	//			{
	//				maxY = temp.GetCenter().Y() + temp.GetRadius();
	//			}
	//			if ((temp.GetCenter().Z() + temp.GetRadius()) > maxZ)
	//			{
	//				maxZ = temp.GetCenter().Z() + temp.GetRadius();
	//			}
	//		}
	//		CollGroup1AABB.SetMinAndMax(Vect(minX, minY, minZ), Vect(maxX, maxY, maxZ));
	//	}
	//	auto it2 = Collection2.begin();
	//	if (it2 != Collection2.end())
	//	{
	//		CollisionVolumeBSphere temp = (*it2)->GetStandardBSphere();
	//		float minX, minY, minZ, maxX, maxY, maxZ;
	//		minX = temp.GetCenter().X() - temp.GetRadius();
	//		minY = temp.GetCenter().Y() - temp.GetRadius();
	//		minZ = temp.GetCenter().Z() - temp.GetRadius();
	//		maxX = temp.GetCenter().X() + temp.GetRadius();
	//		maxY = temp.GetCenter().Y() + temp.GetRadius();
	//		maxZ = temp.GetCenter().Z() + temp.GetRadius();
	//		//it2++;
	//		for (it2; it2 != Collection2.end(); it2++)
	//		{
	//			temp = (*it2)->GetStandardBSphere();
	//			if ((temp.GetCenter().X() - temp.GetRadius()) < minX)
	//			{
	//				minX = temp.GetCenter().X() - temp.GetRadius();
	//			}
	//			if ((temp.GetCenter().Y() - temp.GetRadius()) < minY)
	//			{
	//				minY = temp.GetCenter().Y() - temp.GetRadius();
	//			}
	//			if ((temp.GetCenter().Z() - temp.GetRadius()) < minZ)
	//			{
	//				minZ = temp.GetCenter().Z() - temp.GetRadius();
	//			}
	//			if ((temp.GetCenter().X() + temp.GetRadius()) > maxX)
	//			{
	//				maxX = temp.GetCenter().X() + temp.GetRadius();
	//			}
	//			if ((temp.GetCenter().Y() + temp.GetRadius()) > maxY)
	//			{
	//				maxY = temp.GetCenter().Y() + temp.GetRadius();
	//			}
	//			if ((temp.GetCenter().Z() + temp.GetRadius()) > maxZ)
	//			{
	//				maxZ = temp.GetCenter().Z() + temp.GetRadius();
	//			}
	//		}
	//		CollGroup2AABB.SetMinAndMax(Vect(minX, minY, minZ), Vect(maxX, maxY, maxZ));
	//	}
	//}

};

#endif // !COLLISIONTESTPAIRCOMMAND_H


