//Drawable2D
//Daniel Goodrum, Mar 2018

#ifndef DRAWABLE2D_H
#define DRAWABLE2D_H

#include "AzulCore.h"
#include"RegistrationState.h"
#include "Drawable2DManager.h"

class Draw2DRegistrationCommand;
class Draw2DDeregistrationCommand;

class Drawable2D
{
	friend class DrawableAttorney;

public:

	Drawable2D();
	virtual ~Drawable2D();
	Drawable2D(const Drawable2D&) = delete;
	Drawable2D& operator = (const Drawable2D&) = delete;

private:
	/// \brief Called once per frame on all GameObjects in the current Scene
	/// 
	/// \ingroup DEFAULTEVENTS
	/// All GameObjects are automatically registered to the current Scene 
	/// IMPORTANT: this is intended for 2D objects such as sprites, It is intentionally 
	/// called after all Draw() operations have been done in the current frame.
	/// \code
	///		GameObject::Draw2D()
	///		{
	///			Sprite->Render(); //Renders some 2D model using a camera. Sprites Render function automatically uses 
	///								 //an Orthogonal 2D camera, this camera can by changed.
	///		}
	///	\endcode
	virtual void Draw2D() {};

	RegistrationState CurrRegState;
	Draw2DRegistrationCommand* pRegistrationCommand;
	Draw2DDeregistrationCommand* pDeregisterCommand;
	Drawable2DManager::Drawable2DListRef pMyDeleteRef;

	virtual void SceneRegistration();
	virtual void SceneDeregistration();

protected:
	virtual void SubmitDraw2DRegistration();
	virtual void SubmitDraw2DDeregistration();
};

#endif // !DRAWABLE2D_H
