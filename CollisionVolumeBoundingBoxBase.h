//CollisionVolumeBoundingBoxBase
//Daniel Goodrum, April 2018

#ifndef _CollisionVolumeBoundingBoxBase
#define _CollisionVolumeBoundingBoxBase

#include "AzulCore.h"
#include "CollisionVolume.h"

class Model;

class CollisionVolumeBoundingBoxBase : public CollisionVolume, public Align16
{
public: 
	CollisionVolumeBoundingBoxBase() {};
	virtual ~CollisionVolumeBoundingBoxBase() = default;
	
	const Vect& GetCornerMin() const { return CornerMin; }

	const Vect& GetCornerMax() const { return CornerMax; }

	const Vect& GetStartingCornerMin() const { return StartingCornerMin; }

	const Vect& GetStartingCornerMax() const { return StartingCornerMax; }

	const Vect& GetCurrentCenter() const { return CurrentCenter; }

	const float GetScaleSquared() const { return Scale * Scale; }

	const Vect& GetHalfDiag() const { return HalfDiag; }
	
	const Matrix& GetWorld() const { return World; }

private:


protected:
//	const void CalcCornerMinMax(Matrix& mat, Vect& MinCorner, Vect& MaxCorner);


	Matrix World;
	Vect StartingCornerMin;
	Vect StartingCornerMax;
	Vect CurrentCenter;
	Vect CornerMin;
	Vect CornerMax;
	Vect Center;
	Vect HalfDiag;
	Model* model;
	float Scale;
};


#endif // !_CollisionVolumeBoundingBoxBase
