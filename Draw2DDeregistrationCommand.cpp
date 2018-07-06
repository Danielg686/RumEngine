#include "Draw2DDeregistrationCommand.h"
#include "Drawable2D.h"
#include "DrawableAttorney.h"

Draw2DDeregistrationCommand::Draw2DDeregistrationCommand(Drawable2D * dr)
	:ptrDrawable(dr)
{
}

void Draw2DDeregistrationCommand::execute()
{
	DrawableAttorney::Registration2D::SceneDeregistration2D(ptrDrawable);
}
