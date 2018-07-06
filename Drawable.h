//Drawable
//Daniel Goodrum, Jan 2018

#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "AzulCore.h"
#include "RegistrationState.h"
#include "DrawableManager.h"

class DrawDeregisterCommand;
class DrawRegistrationCommand;

class Drawable
{
	friend class DrawableAttorney;

	//friend class DrawableManager;
	//friend class DrawRegistrationCommand;
	//friend class DrawDeregisterCommand;

public:
	
	Drawable();
	virtual ~Drawable();
	Drawable(const Drawable&) = delete;
	Drawable& operator = (const Drawable&) = delete;
	

private:
	/// \brief Called once per frame on all GameObjects in the current Scene
	/// 
	/// \ingroup DEFAULTEVENTS
	/// All GameObjects are automatically registered to the current Scene 
	/// \code
	///		GameObject::Draw()
	///		{
	///			SomeModel->Render(SceneManager::GetCurrentScene()->GetCurrentCamera(); //Renders some model using a camera.
	///		}
	///	\endcode
	virtual void Draw() {};

	RegistrationState CurrRegState;
	DrawRegistrationCommand* pRegistrationCommand;
	DrawDeregisterCommand* pDeregisterCommand;
	DrawableManager::DrawableListRef pMyDeleteRef;

	virtual void SceneRegistration();
	virtual void SceneDeregistration();

protected:
	
	virtual void SubmitDrawRegistration();
	virtual void SubmitDrawDeregistration();

};
#endif // !DRAWABLE_H
