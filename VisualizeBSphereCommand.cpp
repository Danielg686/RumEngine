#include "VisualizeBSphereCommand.h"
#include "Visualizer.h"
#include "VisualizerAttorney.h"
#include "CollisionVolumeBSphere.h"
#include "VisualizerCommandFactory.h"
VisualizeBSphereCommand::VisualizeBSphereCommand(Matrix& S, Vect& vect)
	:m(S), col(vect)
{
}

void VisualizeBSphereCommand::initialize(Matrix& S, Vect& vect)
{
	m = S;
	col = vect;
}

void VisualizeBSphereCommand::execute()
{
	VisualizerAttorney::Register::RenderBSphere(m, col);
	VisualizerCommandFactory::RecycleBSphereCommand(this);
}
