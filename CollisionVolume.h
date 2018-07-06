//CollisionVolume
//Daniel Goodrum

#ifndef COLLISIONVOLUME_H
#define COLLISIONVOLUME_H

#include "AzulCore.h"

class CollisionVolumeOBB;
class CollisionVolumeBSphere;
class CollisionVolumeAABB;
class Model;

class CollisionVolume
{
public:
	///-----------------------------------------------------------------------------
	/// \brief CollisionVolume::CollisionVolume() abstract base class for all 
	///     other CollisionVolumes to utilize
	///-----------------------------------------------------------------------------
	CollisionVolume() {};
	~CollisionVolume() = default;
	virtual void ComputeData(Model* mod, Matrix& mat) = 0;
	virtual bool Intersect(const CollisionVolume& other) = 0;
	virtual bool Intersect(const CollisionVolumeBSphere& other) = 0;
	virtual void DebugView(const Vect& col) const = 0;
	///-----------------------------------------------------------------------------
	/// \brief CollisionVolume::IntersectAccept(const CollisionVolume& other) abstract function 
	///     for use with dirived class' double dispatch 
	///-----------------------------------------------------------------------------
	virtual bool IntersectAccept(const CollisionVolume& other) const = 0;
	///-----------------------------------------------------------------------------
	/// \brief CollisionVolume::IntersectAccept(const CollisionVolumeBSphere& other) abstract function 
	///     for use with dirived class' double dispatch 
	///-----------------------------------------------------------------------------
	virtual bool IntersectVisit(const CollisionVolumeBSphere& other) const = 0;
	///-----------------------------------------------------------------------------
	/// \brief CollisionVolume::IntersectAccept(const CollisionVolumeAABB& other) abstract function 
	///     for use with dirived class' double dispatch 
	///-----------------------------------------------------------------------------
	virtual bool IntersectVisit(const CollisionVolumeAABB& other) const = 0;
	///-----------------------------------------------------------------------------
	/// \brief CollisionVolume::IntersectAccept(const CollisionVolumeOBB& other) abstract function 
	///     for use with dirived class' double dispatch 
	///-----------------------------------------------------------------------------
	virtual bool IntersectVisit(const CollisionVolumeOBB& other) const = 0;

};


#endif // !COLLISIONVOLUME_H
