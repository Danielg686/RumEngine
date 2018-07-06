//CollisionVolumeOBB
//Daniel Goodrum, April 2018

#ifndef _CollisionVolumeOBB
#define _CollisionVolumeOBB

#include "CollisionVolumeBoundingBoxBase.h"

class CollisionVolumeOBB : public CollisionVolumeBoundingBoxBase
{
public:
	CollisionVolumeOBB() = delete;
	///\brief creates a OBB for use with the collision and visualization system
	CollisionVolumeOBB(Model * mod);
	virtual ~CollisionVolumeOBB();

	virtual void ComputeData(Model* mod, Matrix& mat) override;

	virtual bool Intersect(const CollisionVolume& other) override;
	
	virtual bool Intersect(const CollisionVolumeBSphere& other) override;

	virtual void DebugView(const Vect& col) const override;

	virtual bool IntersectAccept(const CollisionVolume& other) const;

	virtual bool IntersectVisit(const CollisionVolumeBSphere& other) const override;

	virtual bool IntersectVisit(const CollisionVolumeAABB& other) const override;

	virtual bool IntersectVisit(const CollisionVolumeOBB& other) const override;

//	const Matrix& getWorld() const { return World; }
private:
	
};


#endif // !_CollisionVolumeOBB
