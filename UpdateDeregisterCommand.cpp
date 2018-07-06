#include "UpdateDeregisterCommand.h"
#include "Updatable.h"
#include "UpdatableAttorney.h"

UpdateDeregisterCommand::UpdateDeregisterCommand(Updatable * up)
	:ptrUpdatable(up)
{
}

void UpdateDeregisterCommand::execute()
{
	//ptrUpdatable->SceneDeregistration();
	UpdatableAttorney::Registration::SceneDeregistration(ptrUpdatable);
}
