//Visualizer
//Daniel Goodrum, Feb 2018

#ifndef VISUALIZER_H
#define VISUALIZER_H


#include "Color.h"
#include "CollisionVolumeBSphere.h"
#include "CollisionVolumeAABB.h"
#include "CollisionVolumeOBB.h"
#include "Align16.h"
#include <list>

class CommandBase;
class Collidable;

class Visualizer : public virtual Align16
{
private:
	friend class VisualizerAttorney;
	static Visualizer* ptrInstance;

	Visualizer();
	Visualizer &operator = (const Visualizer&) = delete;
	Visualizer(const Visualizer&) = delete;
	~Visualizer();

	static Visualizer& Instance()
	{
		if (!ptrInstance)
		{
			ptrInstance = new Visualizer;
		}
		return *ptrInstance;
	}
	static void Delete();

	static Vect DEFAULT_COLOR;
	GraphicsObject_WireframeConstantColor* WFUnitSphere;
	GraphicsObject_WireframeConstantColor* WFUnitBox;

	static void RenderBSphere(Matrix& S, Vect& col) { Instance().privRenderBSphere(S, col); }
	static void RenderAABB(Matrix& S, Vect& col) { Instance().privRenderAABB(S, col); }
	void privRenderBSphere(Matrix& S, Vect& col);
	void privRenderAABB(Matrix& S, Vect& col);
	void privShowBSphere(const CollisionVolumeBSphere& S, const Vect& col);
	void privShowAABB(const CollisionVolumeAABB& S, const Vect& col);
	void privShowClampPoint(const Vect& pos);
	void privShowOBB(const CollisionVolumeOBB& S, const Vect& col);
	void privShowGroupAABB(const CollisionVolumeAABB& S, const Vect& col);

	void privShowTerrainSquare(const Vect& Min, const Vect& Max, const Vect& col);

	static void VisualizeAll() { Instance().privVisualizeAll(); }
	void privVisualizeAll();

	using StorageList = std::list<CommandBase*>;
	StorageList VisualizeList;

public:

	///	\brief	Shows a bounding sphere for a given object
	///
	///		S is a reference to a CollisionVolumeBSphere to reference, all game objects derive from this class
	///		col is an optional color vector
	///

	static void ShowBSphere(const CollisionVolumeBSphere& S, const Vect& col = DEFAULT_COLOR) { Instance().privShowBSphere(S, col); }

	static void ShowAABB(const CollisionVolumeAABB& S, const Vect& col = DEFAULT_COLOR) { Instance().privShowAABB(S, col); }

	static void ShowCollisionVolume(const Collidable* c, const Vect& col);

	static void ShowClampPoint(const Vect& pos) { Instance().privShowClampPoint(pos); }

	static void ShowOBB(const CollisionVolumeOBB& S, const Vect& col = DEFAULT_COLOR) { Instance().privShowOBB(S, col); }

	static void ShowGroupAABB(const CollisionVolumeAABB& S, const Vect& col) { Instance().privShowGroupAABB(S, col); }

	static void ShowPointTerrainSquare(const Vect& Min, const Vect& Max, const Vect& col = Color::Gold) { Instance().privShowTerrainSquare(Min, Max, col); }
};


#endif // !VISUALIZER_H
