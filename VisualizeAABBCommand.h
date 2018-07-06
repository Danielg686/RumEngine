//VisualizeAABBCommand
//Daniel Goodrum, April 2018

#ifndef _VisualizeAABBCommand
#define _VisualizeAABBCommand

#include "CommandBase.h"
#include"AzulCore.h"

class Visualizer;
class CollisionVolumeAABB;

class VisualizeAABBCommand : public CommandBase, public virtual Align16
{
public:
	VisualizeAABBCommand() = delete;
	VisualizeAABBCommand(Matrix& S, Vect& vect);
	virtual ~VisualizeAABBCommand() {}
	VisualizeAABBCommand(const VisualizeAABBCommand&) = delete;
	VisualizeAABBCommand& operator = (const VisualizeAABBCommand&) = delete;

	void Initialize(Matrix& S, Vect& vect);
	virtual void execute() override;

private:
	Matrix m;
	Vect Col;

};
#endif // !_VisualizeAABBCommand
