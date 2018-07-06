//CollisionTestTerrainCommand
//Daniel Goodrum, May 2018

#ifndef _CollisionTestTerrainCommand
#define _CollisionTestTerrainCommand

#include "CollisionTestCommandBase.h"
#include "CollidableGroup.h"
#include "MathTools.h"
#include "Color.h"
#include "Visualizer.h"
#include "TerrainModel.h"
#include "SceneManager.h"
#include "TerrainIterator.h"

template < typename C >
class CollisionTestTerrainCommand : public CollisionTestCommandBase
{
private:
	typename const CollidableGroup<C>::CollidableCollection& Collection1;

public:
	CollisionTestTerrainCommand()
		:Collection1(CollidableGroup<C>::GetColliderCollection())
	{};

	virtual void execute() override
	{
		for (auto it1 = Collection1.begin(); it1 != Collection1.end(); it1++)
		{
			//TerrainModel* Terrain = SceneManager::GetCurrentScene()->GetTerrainModel();
			//Terrain->Intersect(*(*it1));

			TerrainIterator* itr = new TerrainIterator(SceneManager::GetCurrentScene()->GetTerrainModel(), (*it1));
			for (CollisionVolumeAABB* tempAABB = itr->begin(); !itr->isEnd(); itr->getNext())
			{
				float t = (*it1)->GetStandardBSphere().GetRadius();
				Vect temp = (*it1)->GetStandardBSphere().GetCenter();
				Vect min = Vect(temp.X() - t, temp.Y() - t, temp.Z() - t);
				Vect max = Vect(temp.X() + t, temp.Y() + t, temp.Z() + t);
				CollisionVolumeAABB renderAABB;
				renderAABB.SetMinAndMax(min, max);
				Visualizer::ShowAABB(renderAABB, Color::Red);

				bool test_result = MathTools::Intersect(*tempAABB, (*it1)->GetStandardBSphere());

				if (test_result)
				{
					
					test_result = MathTools::Intersect(*tempAABB, (*it1));
					if(test_result)
					{
						Visualizer::ShowAABB(*tempAABB, Color::Purple);
						//Visualizer::ShowCollisionVolume((*it1), Color::Black);
						Visualizer::ShowBSphere((*it1)->GetStandardBSphere(), Color::Black);

					}
					else
					{
						Visualizer::ShowAABB(*tempAABB, Color::Red);
						//Visualizer::ShowCollisionVolume((*it1), Color::Red);
						Visualizer::ShowBSphere((*it1)->GetStandardBSphere(), Color::Red);
					}
				}
				else
				{
					Visualizer::ShowAABB(*tempAABB, Color::Blue);
					//Visualizer::ShowCollisionVolume((*it1), Color::Blue);
					Visualizer::ShowBSphere((*it1)->GetStandardBSphere(), Color::Blue);
				}
			}
			delete itr;
		}
	}



};




#endif // !_CollisionTestTerrainCommand
