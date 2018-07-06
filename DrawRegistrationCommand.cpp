#include "DrawRegistrationCommand.h"
#include "Drawable.h"
#include "DrawableAttorney.h"

DrawRegistrationCommand::DrawRegistrationCommand(Drawable * dr)
	:ptrDrawable(dr)
{
}

void DrawRegistrationCommand::execute()
{
	DrawableAttorney::Registration::SceneRegistration(ptrDrawable);
	//ptrDrawable->SceneRegistration();
}
