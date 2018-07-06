#include "CollisionVolumeAABB.h"
#include "MathTools.h"
#include "Visualizer.h"
#include "CollisionVolumeBSphere.h"
#include "CollisionVolumeOBB.h"

CollisionVolumeAABB::CollisionVolumeAABB(Model * mod)
{
	this->model = mod;
	this->CornerMax = mod->getMaxAABB();
	this->CornerMin = mod->getMinAABB();
	this->StartingCornerMax = CornerMax;
	this->StartingCornerMin = CornerMin;
	this->Center = .5f*(CornerMax + CornerMin);
	this->CurrentCenter = Center;
	this->HalfDiag = .5f *(CornerMax- CornerMin);
}

void CollisionVolumeAABB::ComputeData(Model * mod, Matrix & mat)
{
	//World = mat;
	//CalcCornerMinMax(mat, CornerMin, CornerMax);
	

	float maxX, maxY, maxZ, minX, minY, minZ;
	int size = mod->getVectNum();
	Vect *vectlist = mod->getVectList();
	Vect temp = vectlist[0];
	temp *= mat;
	maxX = temp.X();
	minX = temp.X();
	maxY = temp.Y();
	minY = temp.Y();
	maxZ = temp.Z();
	minZ = temp.Z();
	for (int i = 0; i < size; i++)
	{
		temp = vectlist[i] * mat;
		if (temp.X() < minX)
		{
			minX = temp.X();
		}
		else if (temp.X() > maxX)
		{
			maxX = temp.X();
		}
		else if (temp.Y() < minY)
		{
			minY = temp.Y();
		}
		else if (temp.Y() > maxY)
		{
			maxY = temp.Y();
		}
		else if (temp.Z() < minZ)
		{
			minZ = temp.Z();
		}
		else if (temp.Z() > maxZ)
		{
			maxZ = temp.Z();
		}
		CornerMax = Vect(maxX, maxY, maxZ);
		CornerMin = Vect(minX, minY, minZ);
	}
	CurrentCenter = .5f*(CornerMax + CornerMin);
	World = mat;
}

bool CollisionVolumeAABB::Intersect(const CollisionVolume & other)
{
	return other.IntersectAccept(*this);
}

bool CollisionVolumeAABB::Intersect(const CollisionVolumeBSphere & other)
{
	return MathTools::Intersect(*this, other);
}

void CollisionVolumeAABB::DebugView(const Vect & col) const
{
	Visualizer::ShowAABB(*this, col);
}

bool CollisionVolumeAABB::IntersectAccept(const CollisionVolume & other) const
{
	return other.IntersectVisit(*this);
}

bool CollisionVolumeAABB::IntersectVisit(const CollisionVolumeBSphere & other) const
{
	return MathTools::Intersect(*this, other);
}

bool CollisionVolumeAABB::IntersectVisit(const CollisionVolumeAABB & other) const
{
	return MathTools::Intersect(*this, other);;
}

bool CollisionVolumeAABB::IntersectVisit(const CollisionVolumeOBB & other) const
{
	return MathTools::Intersect(*this, other);
}

void CollisionVolumeAABB::SetMinAndMax(const Vect & min, const Vect & max)
{
	this->CornerMin = min;
	this->CornerMax = max;
}
