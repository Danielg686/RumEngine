#include "Draw2DRegistrationCommand.h"
#include "DrawableAttorney.h"
#include "Drawable2D.h"

Draw2DRegistrationCommand::Draw2DRegistrationCommand(Drawable2D * dr)
	:ptrDrawable2D(dr)
{
}

void Draw2DRegistrationCommand::execute()
{
	DrawableAttorney::Registration2D::SceneRegistration2D(ptrDrawable2D);
}
