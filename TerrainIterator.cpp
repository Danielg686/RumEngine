#include "TerrainIterator.h"
#include "TerrainModel.h"
#include "Collidable.h"
#include "CollisionVolumeAABB.h"

TerrainIterator::TerrainIterator(TerrainModel * t, Collidable * c)
	:pTerrain(t), C(c)
{
	float rad = C->GetStandardBSphere().GetRadius();
	Vect temp = C->GetStandardBSphere().GetCenter();
	Vect min = Vect(temp.X() - rad, temp.Y() - rad, temp.Z() - rad);
	Vect max = Vect(temp.X() + rad, temp.Y() + rad, temp.Z() + rad);
	minBox = pTerrain->getGridSpace(min);
	maxBox = pTerrain->getGridSpace(max);
	currentBox = minBox;
	size = pTerrain->gridSideLength;

	TerrainArray = pTerrain->MinMaxArray;

	thisAABB = new CollisionVolumeAABB();
	lastBox = new CollisionVolumeAABB();
	lastBox->SetMinAndMax(TerrainArray[maxBox].Min, TerrainArray[maxBox].Max);
}

//TerrainIterator & TerrainIterator::operator++()
//{
//	if ((currentBox + size) <= maxBox)
//	{
//		currentBox += size;
//	}
//	else
//	{
//		IterationHelper += 1;
//		currentBox = minBox + IterationHelper;
//	}
//	thisAABB->SetMinAndMax(TerrainArray[currentBox].Min, TerrainArray[currentBox].Max);
//	return;
//}

TerrainIterator::~TerrainIterator()
{
	delete thisAABB;
	delete lastBox;
}

CollisionVolumeAABB * TerrainIterator::begin()
{
	currentBox = minBox;
	thisAABB->SetMinAndMax(TerrainArray[currentBox].Min, TerrainArray[currentBox].Max);
	return thisAABB;
}

CollisionVolumeAABB * TerrainIterator::getAABB()
{
	return nullptr;
}

void TerrainIterator::getNext()
{
	if ((currentBox + size) <= maxBox)
	{
		currentBox += size;
	}
	else
	{
		IterationHelper += 1;
		currentBox = minBox + IterationHelper;
	}
	thisAABB->SetMinAndMax(TerrainArray[currentBox].Min, TerrainArray[currentBox].Max);
}

bool TerrainIterator::isEnd()
{
	return (currentBox == maxBox);
}
