#include "VisualizerCommandFactory.h"
#include "VisualizeBSphereCommand.h"
#include "VisualizeAABBCommand.h"
VisualizerCommandFactory* VisualizerCommandFactory::ptrInstance = nullptr;

void VisualizerCommandFactory::Terminate()
{
	VisualizeBSphereCommand* c;
	while (!Instance().recycledBSphere.empty())
	{
		c = Instance().recycledBSphere.top();
		delete c;
		Instance().recycledBSphere.pop();
	}
	auto itr = Instance().activeBSphere.begin();
	while (!Instance().activeBSphere.empty())
	{
		c = (*itr);
		Instance().activeBSphere.remove(c);
		itr = Instance().activeBSphere.begin();
		delete c;
	}
	delete ptrInstance;
	ptrInstance = nullptr;
}

VisualizerCommandFactory::~VisualizerCommandFactory()
{

}



VisualizeBSphereCommand * VisualizerCommandFactory::privCreateBSphereCommand(Matrix& ref, Vect& col)
{
	VisualizeBSphereCommand* c;

	if (recycledBSphere.empty())
	{
		c = new VisualizeBSphereCommand(ref, col);
		numCommands++;
	}
	else
	{
		c = recycledBSphere.top();
		recycledBSphere.pop();
		numCommands++;
	}
	c->initialize(ref, col);
	activeBSphere.push_front(c);

	//DebugMsg::out("current number of Visualizer Commands is %d\n", numSpheres);

	return c;
}

void VisualizerCommandFactory::privRecycleBSphereCommand(CommandBase * c)
{
	activeBSphere.remove((VisualizeBSphereCommand*)c);
	recycledBSphere.push((VisualizeBSphereCommand*)c);
	numCommands--;
}

VisualizeAABBCommand * VisualizerCommandFactory::privCreateAABBCommand(Matrix& ref, Vect& Col)
{
	VisualizeAABBCommand* c;

	if (recycledAABB.empty())
	{
		c = new VisualizeAABBCommand(ref, Col);
		numCommands++;
	}
	else
	{
		c = recycledAABB.top();
		recycledAABB.pop();
		numCommands++;
	}
	c->Initialize(ref, Col);
	activeAABB.push_front(c);
	return c;
}

void VisualizerCommandFactory::privRecycleAABBCommand(CommandBase * C)
{
	activeAABB.remove((VisualizeAABBCommand*)C);
	recycledAABB.push((VisualizeAABBCommand*)C);
	numCommands--;
}
