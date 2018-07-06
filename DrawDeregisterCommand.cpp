#include "DrawDeregisterCommand.h"
#include "Drawable.h"
#include "DrawableAttorney.h"

DrawDeregisterCommand::DrawDeregisterCommand(Drawable * dr)
	:ptrDrawable(dr)
{
}

void DrawDeregisterCommand::execute()
{
	DrawableAttorney::Registration::SceneDeregistration(ptrDrawable);
//	ptrDrawable->SceneDeregistration();
}
