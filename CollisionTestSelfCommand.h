//CollisionTestSelfCommand
//Daniel Goodrum, Feb 2018


#ifndef COLLISIONTESTSELFCOMMAND_H
#define COLLISIONTESTSELFCOMMAND_H

#include "CollisionTestCommandBase.h"
#include "CollidableGroup.h"
#include "CollisionVolumeBSphere.h"
#include "MathTools.h"
#include "Color.h"
#include "Visualizer.h"
//#include "CollisionManager.h"

template < typename C >
class CollisionTestSelfCommand : public CollisionTestCommandBase
{
private:
	typename const CollidableGroup<C>::CollidableCollection& Collection1;

public:
	CollisionTestSelfCommand()
		:Collection1(CollidableGroup<C>::GetColliderCollection())
	{};

	virtual void execute() override
	{
		for (auto it1 = Collection1.begin(); it1 != Collection1.end(); it1++)
		{
			auto it2 = it1;
			it2++;
			for (it2; it2 != Collection1.end(); it2++)
			{/*
				const CollisionVolumeBSphere& bs1 = (*it1)->GetBSphere();
				const CollisionVolumeBSphere& bs2 = (*it2)->GetBSphere();
				bool test_result = MathTools::Intersect(bs1,bs2);*/
			
				bool test_result = MathTools::Intersect((*it1)->GetStandardBSphere(), (*it2)->GetStandardBSphere());

				if (test_result)
				{
					test_result = MathTools::Intersect(*it1, *it2);

					if (test_result)
					{
						(*it1)->Collision(*it2);
						(*it2)->Collision(*it1);
						Visualizer::ShowCollisionVolume(*it1, Color::Red);
						Visualizer::ShowCollisionVolume(*it2, Color::Red);
						//Visualizer::ShowBSphere(bs1, Color::Red);
						//Visualizer::ShowBSphere(bs2, Color::Red);
					}
					else
					{
						Visualizer::ShowCollisionVolume(*it1, Color::Blue);
						Visualizer::ShowCollisionVolume(*it2, Color::Blue);
						//Visualizer::ShowBSphere(bs1, Color::Blue);
						//Visualizer::ShowBSphere(bs2, Color::Blue);
					}
				}
			}
		}
	}
};


#endif // !COLLISIONTESTSELFCOMMAND_H
