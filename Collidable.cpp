#include "Collidable.h"

void Collidable::UpdateCollisionData(Matrix & mat)
{
	DefaultBSphere->ComputeData(pColModel, mat);
	ColVolume->ComputeData(pColModel, mat);
}
