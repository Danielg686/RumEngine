//CollisionVolumeBSphere
//Daniel Goodrum, Feb 2018


#ifndef COLLISIONVOLUMEBSPHERE_H
#define COLLISIONVOLUMEBSPHERE_H

#include "AzulCore.h"
#include "CollisionVolume.h"

class Model;


class CollisionVolumeBSphere : public CollisionVolume, public Align16
{
public:
	CollisionVolumeBSphere() {};
	virtual ~CollisionVolumeBSphere() = default;

	///		\brief Returns center position for BSphere to be rendered.
	const Vect& GetCenter() const { return Center; }
	///		\brief Returns radius of BSphere to be rendered.
	const float GetRadius() const{ return Radius; }
	///		\brief Computes new center and radius for a given model and world matrix.
	virtual void ComputeData(Model* mod, Matrix& mat) override;

	virtual bool Intersect(const CollisionVolume& other) override;
	///		\brief Determines if two BSpheres intersect. 
	virtual bool Intersect(const CollisionVolumeBSphere& other) override;

	//virtual void DebugView(const Vect& col) const override;

	//virtual bool IntersectAccept(const CollisionVolume& other) const override;
	//
	//virtual bool IntersectVisit(const CollisionVolumeBSphere& other) const override;

	virtual void DebugView(const Vect& col) const override;
	virtual bool IntersectAccept(const CollisionVolume& other) const override;
	virtual bool IntersectVisit(const CollisionVolumeBSphere& other) const override;
	virtual bool IntersectVisit(const CollisionVolumeAABB& other) const override;
	virtual bool IntersectVisit(const CollisionVolumeOBB& other) const override;

private:

	Vect Center;
	float Radius;


};


#endif // !COLLISIONVOLUMEBSPHERE
