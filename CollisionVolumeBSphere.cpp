#include "CollisionVolumeBSphere.h"
#include "CollisionVolumeAABB.h"
#include "MathTools.h"
#include "Visualizer.h"

void CollisionVolumeBSphere::ComputeData(Model * mod, Matrix & mat)
{
	Center = mod->getCenter() *mat;
	Vect temp = mat.get(MatrixRowType::ROW_0);
	float temp1 = temp.mag();
	Radius = mod->getRadius()* temp1;
}

bool CollisionVolumeBSphere::Intersect(const CollisionVolume & other)
{
	UNREFERENCED_PARAMETER(other);
	return false;
}

bool CollisionVolumeBSphere::Intersect(const CollisionVolumeBSphere & other)
{
	return MathTools::Intersect(*this, other);
}

void CollisionVolumeBSphere::DebugView(const Vect & col) const
{
	Visualizer::ShowBSphere(*this, col);
}

bool CollisionVolumeBSphere::IntersectAccept(const CollisionVolume & other) const
{
	return other.IntersectVisit(*this);
}

bool CollisionVolumeBSphere::IntersectVisit(const CollisionVolumeBSphere & other) const
{
	return MathTools::Intersect(*this, other);
}

bool CollisionVolumeBSphere::IntersectVisit(const CollisionVolumeAABB & other) const
{
	return MathTools::Intersect(*this, other);
}

bool CollisionVolumeBSphere::IntersectVisit(const CollisionVolumeOBB & other) const
{
	return MathTools::Intersect(*this, other);
}
