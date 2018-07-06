#include "MathTools.h"
#include "Collidable.h"
#include "CollisionVolume.h"
#include "CollisionVolumeBoundingBoxBase.h"
#include "VisualizerAttorney.h"
#include <cmath>

bool MathTools::Intersect(const CollisionVolumeBSphere & A, const CollisionVolumeBSphere & B)
{
	float radSquare = (A.GetRadius() + B.GetRadius());
	radSquare *= radSquare;
	const Vect temp1 = A.GetCenter() - B.GetCenter();
	float dist = temp1.magSqr();

	return (radSquare > dist);
}

bool MathTools::Intersect(const Collidable * c1, const Collidable * c2)
{
	const CollisionVolume& v1 = c1->GetColVolume();
	const CollisionVolume& v2 = c2->GetColVolume();
	return v1.IntersectAccept(v2);
}

bool MathTools::Intersect(const CollisionVolumeAABB & A, const Collidable * c)
{
	const CollisionVolume& v1 = c->GetColVolume();
	return A.IntersectAccept(v1);
	
}

bool MathTools::Intersect(const CollisionVolumeAABB & A, const CollisionVolumeAABB & B)
{
//	const Vect& Amax = A.GetCornerMax;
	//const Vect &Amin = A.GetCornerMin;
	//const Vect &Bmax = B.GetCornerMax;
	//const Vect &Bmin = B.GetCornerMin;
	if (Overlap(A.GetCornerMin().X(), A.GetCornerMax().X(), B.GetCornerMin().X(), B.GetCornerMax().X()) && Overlap(A.GetCornerMin().Y(), A.GetCornerMax().Y(), B.GetCornerMin().Y(), B.GetCornerMax().Y()) && Overlap(A.GetCornerMin().Z(), A.GetCornerMax().Z(), B.GetCornerMin().Z(), B.GetCornerMax().Z()))
	{
		return true;
	}
	return false;
}

bool MathTools::Intersect(const CollisionVolumeAABB & A, const CollisionVolumeBSphere & B)
{
	const Vect Amax = A.GetCornerMax();
	const Vect Amin = A.GetCornerMin();
	const Vect BCenter = B.GetCenter();
	float x, y, z;
	x = Clamp(BCenter.X(), Amin.X(), Amax.X());
	y = Clamp(BCenter.Y(), Amin.Y(), Amax.Y());
	z = Clamp(BCenter.Z(), Amin.Z(), Amax.Z());
	
	Vect temp = Vect(x, y, z) - BCenter;
	float radSquare = B.GetRadius()*B.GetRadius();
	float dist = temp.magSqr();
	if ((dist - radSquare) < 1000)
	{
		Vect a = Vect(x, y, z);
		VisualizerAttorney::Register::ShowClampPoint(a);
	}
	return (radSquare > dist);
}

bool MathTools::Intersect(const CollisionVolumeBSphere & B, const CollisionVolumeAABB & A)
{
	return Intersect(A, B);
}

bool MathTools::Intersect(const CollisionVolumeOBB & A, const CollisionVolumeOBB & B)
{
	return IntersectBoundingBox(A, B);
}

bool MathTools::Intersect(const CollisionVolumeOBB & A, const CollisionVolumeAABB & B)
{
	return IntersectBoundingBox(A, B);
}

bool MathTools::Intersect(const CollisionVolumeOBB & A, const CollisionVolumeBSphere & B)
{
	Matrix inv = A.GetWorld().getInv();
	Vect bSphereCenter = B.GetCenter();
	Vect localToOBB = bSphereCenter * inv;
	Vect Clamped = Clamp(localToOBB, A.GetCornerMin() , A.GetCornerMax());
	Clamped *= A.GetWorld();
	Visualizer::ShowClampPoint(Clamped);

	return PointInsideSphere(Clamped, B);
}

bool MathTools::Intersect(const CollisionVolumeAABB & A, const CollisionVolumeOBB & B)
{
	return IntersectBoundingBox(A, B);
}

bool MathTools::Intersect(const CollisionVolumeBSphere & A, const CollisionVolumeOBB & B)
{
	return MathTools::Intersect(B, A);
}

bool MathTools::IntersectBoundingBox(const CollisionVolumeBoundingBoxBase & A, const CollisionVolumeBoundingBoxBase & B)
{
	Vect Axis[15];
	//Vect A1, A2, A3, B1, B2, B3, AB1, AB2, AB3, AB4, AB5, AB6, AB7, AB8, AB9;
	Axis[0] = A.GetWorld().get(ROW_0);//A.X
	Axis[1] = A.GetWorld().get(ROW_1);//A.Y
	Axis[2] = A.GetWorld().get(ROW_2);//A.Z
	Axis[3] = B.GetWorld().get(ROW_0);//B.X
	Axis[4] = B.GetWorld().get(ROW_1);//B.Y
	Axis[5] = B.GetWorld().get(ROW_2);//B.Z
	Axis[6] = Axis[0].cross(Axis[3]);//x cross x
	Axis[7] = Axis[0].cross(Axis[4]);//x cross y
	Axis[8] = Axis[0].cross(Axis[5]);//x cross z
	Axis[9] = Axis[1].cross(Axis[3]);//y cross x
	Axis[10] = Axis[1].cross(Axis[4]);//y cross y
	Axis[11] = Axis[1].cross(Axis[5]);//y cross z
	Axis[12] = Axis[2].cross(Axis[3]);//z cross x
	Axis[13] = Axis[2].cross(Axis[4]);//z cross y
	Axis[14] = Axis[2].cross(Axis[5]);//z cross z
	float Proj1, Proj2, D;
	
	for (int i = 0; i < 15; ++i)
	{
		if (Axis[i].magSqr() > FLT_EPSILON)
		{
			Proj1 = Projection(A, Axis[i]);
			Proj2 = Projection(B, Axis[i]);
		//	D = AbsoluteValue(GetDistBetweenPoints(A.GetCurrentCenter(), B.GetCurrentCenter()).dot(Axis[i])) / Axis[i].mag();
			D = GetD(A.GetCurrentCenter(), B.GetCurrentCenter(), Axis[i]);
			if (D > Proj1 + Proj2)
			{
				return false;
			}
		}
	}
	return true;
}

bool MathTools::Intersect(const Vect & point, const Vect & Min, const Vect & Max)
{
	if (point.X() >= Min.X() && point.X() <= Max.X() && point.Y() >= Min.Y() && point.Y() <= Max.Y() &&point.Z() >= Min.Z() && point.Z() <= Max.Z())
	{
		return true;
	}
	return false;
}

bool MathTools::Intersect(const CollisionVolumeBSphere & A, const Vect & Min, const Vect & Max)
{
	const Vect Amax = Max;
	const Vect Amin = Min;
	const Vect BCenter = A.GetCenter();
	float x, y, z;
	x = Clamp(BCenter.X(), Amin.X(), Amax.X());
	y = Clamp(BCenter.Y(), Amin.Y(), Amax.Y());
	z = Clamp(BCenter.Z(), Amin.Z(), Amax.Z());

	Vect temp = Vect(x, y, z) - BCenter;
	float radSquare = A.GetRadius()*A.GetRadius();
	float dist = temp.magSqr();
	if ((dist - radSquare) < 1000)
	{
		Vect t = Vect(x, y, z);
		VisualizerAttorney::Register::ShowClampPoint(t);
	}
	return (radSquare > dist);
}


//returns inverse of local transform
Matrix MathTools::getOBBInverseTransform(const CollisionVolumeOBB & S)
{
	Matrix m;
	Vect Scale = S.GetCornerMax() - S.GetCornerMin();
	Vect trans = .5f*(S.GetCornerMax() + S.GetCornerMin());
	m = Matrix(SCALE, Scale) * Matrix(TRANS, trans);
	m *= S.GetWorld();
	m = m.getInv();
	return m;
}

bool MathTools::Overlap(const float Amin, const float Amax, const float Bmin, const float Bmax)
{
	if ((Amax < Bmin) || (Bmax < Amin))
	{
		return false;
	}
	return true;
}

float MathTools::Clamp(const float val, const float min, const float max)
{
	if (val < min)
	{
		return min;
	}
	else if (max < val)
	{
		return max;
	}
	return val;
}

Vect MathTools::Clamp(const Vect & val, const Vect & min, const Vect & max)
{
	float x, y, z;
	x = Clamp(val.X(), min.X(), max.X());
	y = Clamp(val.Y(), min.Y(), max.Y());
	z = Clamp(val.Z(), min.Z(), max.Z());
	return Vect(x, y, z);
}


bool MathTools::PointInsideSphere(const Vect & Point, const CollisionVolumeBSphere & bSphere)
{
	const Vect temp1 = bSphere.GetCenter() - Point;
	float radSquare = bSphere.GetRadius();
	radSquare *= radSquare;
	float dist = temp1.magSqr();

	return (radSquare > dist);
}

Vect MathTools::GetProjMax(const CollisionVolumeBoundingBoxBase & boundingBox , Vect& v)
{
	Vect t = v * boundingBox.GetWorld().getInv();
	Vect proMax = (t);
	return boundingBox.GetScaleSquared() * Vect();
}

//Vect MathTools::ProjVAlongW(const Vect & V, const Vect & W)
//{
//	return ((V.dot(W) / GetVectMagnitude(W))*W);
//}
//
//float MathTools::GetVectMagnitude( const Vect & V)
//{
//	return (V.dot(V));
//}

Vect MathTools::GetDistBetweenPoints(const Vect & C1, const Vect & C2)
{
	return (C2-C1);
}

//float MathTools::LengthOfProjOnV(const Vect & C1,const Vect & C2,const Vect & V)
//{
//	return (GetDistBetweenPoints(C1,C2).dot(V))/V.mag();
//}
//
//float MathTools::LengthOfProjOnV(const Vect & C,const Vect & V)
//{
//	return (C.dot(V) / GetVectMagnitude(V));
//}

float MathTools::GetD(const Vect & aCenter, const Vect & bCenter, const Vect & V)
{
	return (AbsoluteValue(GetDistBetweenPoints(aCenter,bCenter).dot(V)) / V.mag());
}

float MathTools::Projection(const CollisionVolumeBoundingBoxBase & boundingBox, const Vect & V)
{
	Matrix inv = boundingBox.GetWorld().getInv();
	Vect vPrime = V * inv;
	float x, y, z;
	x = AbsoluteValue(vPrime.X() * boundingBox.GetHalfDiag().X());
	y = AbsoluteValue(vPrime.Y() * boundingBox.GetHalfDiag().Y());
	z = AbsoluteValue(vPrime.Z() * boundingBox.GetHalfDiag().Z());
	float ProjMax = ( x+y+z	) / V.mag();
	return (GetUniformScaleValueSquared(boundingBox.GetWorld()) * ProjMax);
	//return (GetUniformScaleValueSquared(GetOBBWorld(boundingBox)) * ProjMax);
}

float MathTools::AbsoluteValue(const float x)
{
	if (x < 0)
	{
		return x*-1;
	}
	return x;
}

float MathTools::GetUniformScaleValueSquared(const Matrix & m)
{
//	Vect t = Vect(1, 1, 1) * m;
////	Vect t = m.get(ROW_0);
//	//float x = ((t.X() * t.X()) + (t.Y() * t.Y()) + (t.Z() * t.Z()));
//	float x = t.magSqr();
//	//	//	return ((t.X() * t.X()) + (t.Y() * t.Y()) + (t.Z() * t.Z()));
////	return x;
//	//float x = t.mag();
//	//UNREFERENCED_PARAMETER(x);
////	return t.magSqr();
//	return x;
	Vect t = Vect(1, 0, 0) * m;
	return t.magSqr();
}

Matrix MathTools::GetOBBWorld(const CollisionVolumeBoundingBoxBase & boundingBox)
{
	Matrix m;
	Vect Scale = boundingBox.GetCornerMax() - boundingBox.GetCornerMin();
	Vect trans = .5f*(boundingBox.GetCornerMax() + boundingBox.GetCornerMin());
	m = Matrix(SCALE, Scale) * Matrix(TRANS, trans);
	Matrix world = boundingBox.GetWorld();
	m *= world;
	return m;
}

float MathTools::GetRotationAngle(const Vect & vect1, const Vect& vect2)
{
	return	acos((vect1.dot(vect2)) / (vect1.mag()* vect2.mag()));// *360.0f / MATH_PI;
}

bool MathTools::IsleftOfVect(const Vect & line, const Vect & point)
{
	//float t = line.dot(point);
	//DebugMsg::out("DotProduct is %f\n", t);
	//return t > 0;
	return line.dot(point) > 0;

}

