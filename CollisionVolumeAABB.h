//CollisionVolumeAABB
//Daniel Goodrum, April 2018

#ifndef _CollisionVolumeAABB
#define _CollisionVolumeAABB

#include "AzulCore.h"
#include "CollisionVolumeBoundingBoxBase.h"

class Model;

class CollisionVolumeAABB : public CollisionVolumeBoundingBoxBase
{
public:
	///-----------------------------------------------------------------------------
	/// \brief CollisionVolumeAABB::CollisionVolumeAABB()  
	///     used to determine the collision volume type
	///-----------------------------------------------------------------------------
	CollisionVolumeAABB() {};
	CollisionVolumeAABB(Model* mod);
	virtual ~CollisionVolumeAABB() = default;

	virtual void ComputeData(Model* mod, Matrix& mat) override;

	virtual bool Intersect(const CollisionVolume& other) override;
	///		\brief Determines if two BSpheres intersect. 
	virtual bool Intersect(const CollisionVolumeBSphere& other) override;

	virtual void DebugView(const Vect& col) const override;

	virtual bool IntersectAccept(const CollisionVolume& other) const;

	virtual bool IntersectVisit(const CollisionVolumeBSphere& other) const override;

	virtual bool IntersectVisit(const CollisionVolumeAABB& other) const override;

	virtual bool IntersectVisit(const CollisionVolumeOBB& other) const override;
	
	void SetMinAndMax(const Vect& min,const Vect& max);
private:

};


#endif // 
