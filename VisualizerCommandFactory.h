//Visualizer Command Factory
//Daniel Goodrum, Mar 2018

#ifndef _VisualizerCommandFactory
#define _VisualizerCommandFactory

#include <stack>
#include <list>
#include "Align16.h"
#include "CollisionVolumeBSphere.h"
class VisualizeBSphereCommand;
class VisualizeAABBCommand;
class CommandBase;
//class CollisionVolumeBSphere;

class VisualizerCommandFactory : public Align16
{
public:
	static VisualizeBSphereCommand* addBSphereVisualizeCommand(Matrix& ref, Vect& pos) { return Instance().privCreateBSphereCommand(ref, pos); }
	static VisualizeAABBCommand* addAABBVisualizeCommand(Matrix& ref, Vect& pos) { return Instance().privCreateAABBCommand(ref, pos); }
	static void RecycleBSphereCommand(CommandBase* c) { Instance().privRecycleBSphereCommand(c); }
	static void RecycleAABBCommand(CommandBase* c) { Instance().privRecycleAABBCommand(c); }

	static void Terminate();
private:
	static VisualizerCommandFactory* ptrInstance;

	VisualizerCommandFactory() = default;
	VisualizerCommandFactory(const VisualizerCommandFactory&) = delete;
	VisualizerCommandFactory& operator = (const VisualizerCommandFactory&) = delete;
	~VisualizerCommandFactory();

	static VisualizerCommandFactory& Instance() 
	{
		if (!ptrInstance)
		{
			ptrInstance = new VisualizerCommandFactory;
		}
		return *ptrInstance;
	}

	std::stack<VisualizeBSphereCommand*> recycledBSphere;
	std::list<VisualizeBSphereCommand*> activeBSphere;


	std::stack<VisualizeAABBCommand*> recycledAABB;
	std::list<VisualizeAABBCommand*> activeAABB;

	VisualizeBSphereCommand* privCreateBSphereCommand(Matrix& ref, Vect& Col);
	void privRecycleBSphereCommand(CommandBase* c);

	VisualizeAABBCommand* privCreateAABBCommand(Matrix& ref, Vect& Col);
	void privRecycleAABBCommand(CommandBase* C);
	

	int numCommands = 0;

};

#endif // !_VisualizerCommandFactory
