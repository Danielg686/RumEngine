#include "VisualizeAABBCommand.h"
#include "Visualizer.h"
#include "VisualizerAttorney.h"
#include "VisualizerCommandFactory.h"
VisualizeAABBCommand::VisualizeAABBCommand(Matrix& S, Vect& vect)
	:m(S), Col(vect)
{
}

void VisualizeAABBCommand::Initialize(Matrix& S, Vect& vect)
{
	m = S;
	Col = vect;
}

void VisualizeAABBCommand::execute()
{
	VisualizerAttorney::Register::RenderAABB(m, Col);
	VisualizerCommandFactory::RecycleAABBCommand(this);
}
