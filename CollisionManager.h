//CollisionManager
//Daniel Goodrum, Feb 2018

#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

//#include "CollisionTestCommandBase.h"
#include "CollisionTestPairCommand.h"
#include "CollisionTestSelfCommand.h"
//#include "CollisionTestTerrainCommand.h"
#include "CollidableGroup.h"
#include "CollidableGroupDeleteCommand.h"
#include <list>

class Collidable;

class CollisionManager
{
private:

	using ColTestCommands = std::list<CollisionTestCommandBase*>;
	using ColDeleteCommands = std::list<CollisionTestCommandBase*>;


	ColTestCommands TestCommands;
	ColDeleteCommands DeleteCommands;

public:
	friend class Scene;


	CollisionManager() {};
	virtual ~CollisionManager() 
	{
		CollisionTestCommandBase* temp;
		DebugMsg::out("Collision Manager Destructor Called\n");
		ColDeleteCommands::const_iterator it = DeleteCommands.begin();
		//while(it != DeleteCommands.end())
		//{
		//	temp = (*it);
		//	it++;
		//	
		//	delete temp;
		//}
		this->DeleteCommand();
		DeleteCommands.clear();
		ColTestCommands::const_iterator itr = TestCommands.begin();
		while (itr != TestCommands.end())
		{
			temp = (*itr);
			itr++;
			delete temp;
		}
		TestCommands.clear();

	}
	virtual void DeleteCommand()
	{
		for(ColDeleteCommands::const_iterator it = DeleteCommands.begin(); it != DeleteCommands.end(); it++)
		{
			(*it)->execute();
		}
	}

	template <typename C1, typename C2>
	void SetCollisionPair()
	{
		CollisionTestPairCommand<C1, C2>* temp = new CollisionTestPairCommand<C1, C2>();
		TestCommands.push_back(temp);
	}

	template <typename C>
	void SetCollisionSelf()
	{
		CollisionTestSelfCommand<C>* temp = new CollisionTestSelfCommand<C>();
		TestCommands.push_back(temp);
	}

	template <typename C>
	void SetCollisionTerrain()
	{
		CollisionTestTerrainCommand<C>* temp = new CollisionTestTerrainCommand<C>();
		TestCommands.push_back(temp);
	}

	
	void RegisterDeleteCommand(CollisionTestCommandBase* c)
	{
		DeleteCommands.push_back(c);
	}


private:

	void ProcessCollisions()
	{
		for (ColTestCommands::const_iterator it = TestCommands.begin(); it != TestCommands.end(); it++)
		{
			(*it)->execute();
		}
		//for (ColDeleteCommands::const_iterator itr = DeleteCommands.begin(); itr != DeleteCommands.end(); itr++)
		//{
		//	(*itr)->execute();
		//}
	}

};



#endif // !COLLISIONMANAGER_H

