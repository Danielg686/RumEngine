#include "UpdateRegistrationCommand.h"
#include "Updatable.h"
#include "UpdatableAttorney.h"


UpdateRegistrationCommand::UpdateRegistrationCommand(Updatable * up)
	:ptrUpdatable(up)
{
}

void UpdateRegistrationCommand::execute()
{
	//ptrUpdatable->SceneRegistration();
	UpdatableAttorney::Registration::SceneRegistration(ptrUpdatable);
}
