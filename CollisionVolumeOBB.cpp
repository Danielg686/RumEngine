#include "CollisionVolumeOBB.h"
#include "CollisionVolumeBSphere.h"
#include "CollisionVolumeAABB.h"
#include "MathTools.h"
#include "Visualizer.h"

CollisionVolumeOBB::CollisionVolumeOBB(Model * mod)
{
	this->model = mod;
	this->CornerMax = mod->getMaxAABB();
	this->CornerMin = mod->getMinAABB();
	this->StartingCornerMax = CornerMax;
	this->StartingCornerMin = CornerMin;
	this->CurrentCenter = Center;
	this->HalfDiag = .5f *(CornerMax - CornerMin);
	this->Center = .5f*(CornerMin + HalfDiag);
}

CollisionVolumeOBB::~CollisionVolumeOBB()
{
}

void CollisionVolumeOBB::ComputeData(Model * mod, Matrix & mat)
{
	UNREFERENCED_PARAMETER(mod);

	CurrentCenter = Center *mat;
	World = mat;
}

bool CollisionVolumeOBB::Intersect(const CollisionVolume & other)
{
	UNREFERENCED_PARAMETER(other);
	return false;
}

bool CollisionVolumeOBB::Intersect(const CollisionVolumeBSphere & other)
{
	return MathTools::Intersect(*this, other);
}

void CollisionVolumeOBB::DebugView(const Vect & col) const
{
	Visualizer::ShowOBB(*this, col);
}

bool CollisionVolumeOBB::IntersectAccept(const CollisionVolume & other) const
{
	return other.IntersectVisit(*this);
}

bool CollisionVolumeOBB::IntersectVisit(const CollisionVolumeBSphere & other) const
{
	return MathTools::Intersect(*this, other);
}

bool CollisionVolumeOBB::IntersectVisit(const CollisionVolumeAABB & other) const
{
	return MathTools::Intersect(*this, other);
}

bool CollisionVolumeOBB::IntersectVisit(const CollisionVolumeOBB & other) const
{
	return MathTools::Intersect(*this, other);
}
