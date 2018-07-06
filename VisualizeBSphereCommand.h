//VisualizeBSphereCommand
//Daniel Goodrum, Feb 2018


#ifndef VISUALIZEBSPHERECOMMAND_H
#define VISUALIZEBSPHERECOMMAND_H

#include "CommandBase.h"
#include "AzulCore.h"

class Visualizer;
class CollisionVolumeBSphere;

class VisualizeBSphereCommand : public CommandBase, public virtual Align16
{
public:
	VisualizeBSphereCommand() = delete;
	VisualizeBSphereCommand(Matrix& S, Vect& vect);
	virtual ~VisualizeBSphereCommand() {};
	VisualizeBSphereCommand(const VisualizeBSphereCommand&) = delete;
	VisualizeBSphereCommand& operator = (const VisualizeBSphereCommand&) = delete;

	void initialize(Matrix& S, Vect& vect);
	virtual void execute() override;

private:
	Matrix m;
	Vect col;
};




#endif // !VISUALIZEBSPHERECOMMAND_H
