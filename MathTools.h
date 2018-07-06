//MathTools
//Daniel Goodrum, Feb 2018

#ifndef MATHTOOLS_H
#define MATHTOOLS_H

#include "CollisionVolumeBSphere.h"
#include "CollisionVolumeOBB.h"
#include "Align16.h"
class Collidable;

class MathTools : public virtual Align16
{
public:
	static bool Intersect(const CollisionVolumeBSphere& A, const CollisionVolumeBSphere& B);
	static bool Intersect(const Collidable* c1, const Collidable* c2);
	static bool Intersect(const CollisionVolumeAABB& A, const Collidable* c);
	static bool Intersect(const CollisionVolumeAABB& A, const CollisionVolumeAABB& B);
	static bool Intersect(const CollisionVolumeAABB& A, const CollisionVolumeBSphere& B);
	static bool Intersect(const CollisionVolumeBSphere& B, const CollisionVolumeAABB& A);
	
	static bool Intersect(const CollisionVolumeOBB& A, const CollisionVolumeOBB& B);
	static bool Intersect(const CollisionVolumeOBB& A, const CollisionVolumeAABB& B);
	static bool Intersect(const CollisionVolumeOBB& A, const CollisionVolumeBSphere& B);
	static bool Intersect(const CollisionVolumeAABB& A, const CollisionVolumeOBB& B);
	static bool Intersect(const CollisionVolumeBSphere& A, const CollisionVolumeOBB& B);
	static bool IntersectBoundingBox(const CollisionVolumeBoundingBoxBase& A, const CollisionVolumeBoundingBoxBase& B);

	static bool Intersect(const Vect& point, const Vect& Min, const Vect& Max);
	static bool Intersect(const CollisionVolumeBSphere& A, const Vect& Min, const Vect& Max);
	
	static Matrix getOBBInverseTransform(const CollisionVolumeOBB& S);
	static bool Overlap(const float Amin,const float Amax, const float Bmin, const float Bmax);
	static float Clamp(const float val, const float min, const float max);
	static Vect Clamp(const Vect& val, const Vect& min, const Vect& max);
	static bool PointInsideSphere(const Vect& Point, const CollisionVolumeBSphere& bSphere);
	static Vect GetProjMax(const CollisionVolumeBoundingBoxBase& boundingBox, Vect& v);
//	static Vect ProjVAlongW(const Vect& V, const Vect& W);

	//returns dot product of V and V
	//static float GetVectMagnitude(const Vect& V);
	//dist between two points
	static Vect GetDistBetweenPoints(const Vect& C1,const Vect& C2);
	//projection of the distance between two center points along a seperating axis
	//static float LengthOfProjOnV(const Vect& C1,const Vect& C2,const Vect& V);
	//projection of a vector along a seperating axis
	//static float LengthOfProjOnV(const Vect& C,const Vect& V);

	static float GetD(const Vect& aCenter, const Vect& bCenter, const Vect& V);

	static float Projection(const CollisionVolumeBoundingBoxBase& boundingBox, const Vect& V);
	static float AbsoluteValue(const float x);
	static float GetUniformScaleValueSquared(const Matrix& m);

	static Matrix GetOBBWorld(const CollisionVolumeBoundingBoxBase& boundingBox);

	static float GetRotationAngle(const Vect& vect1, const Vect& vect2);

	static bool IsleftOfVect(const Vect& line, const Vect& point);
};







#endif // !MATHTOOLS_H
