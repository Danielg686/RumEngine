//Daniel Goodrum
//TerrainIterator

#ifndef _TerrainIterator
#define _TerrainIterator

#include "AzulCore.h"


class TerrainModel;
struct TerrainMinMax;
class Collidable;
class CollisionVolumeAABB;


class TerrainIterator
{
public:
	TerrainIterator() = delete;
	TerrainIterator(TerrainModel* t,Collidable* c);
	TerrainIterator(const TerrainIterator&) = default;
	TerrainIterator& operator = (const TerrainIterator&) = default;
//	TerrainIterator& operator ++ ();
	~TerrainIterator();

	CollisionVolumeAABB* begin();
	CollisionVolumeAABB* getAABB();
	void getNext();
	bool isEnd();

private:

	TerrainMinMax* TerrainArray;
	TerrainModel* pTerrain;
	Collidable* C;
	int minBox;
	int maxBox;
	int currentBox;
	int size;
	int IterationHelper = 0;
	CollisionVolumeAABB* thisAABB;
	CollisionVolumeAABB* lastBox;
	
};



#endif // !_TerrainIterator
