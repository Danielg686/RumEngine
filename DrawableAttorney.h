//DrawableAttorney
//Daniel Goodrum, Jan 2018

#ifndef DRAWABLEATTORNEY_H
#define DRAWABLEATTORNEY_H

#include "Drawable.h"
#include "Drawable2D.h"

class DrawableAttorney
{
public:
	class GameLoop
	{
	private:
		friend class DrawableManager;
		///		\brief Passthrough for DrawableManager.
		static void Draw(Drawable* pMgr) { pMgr->Draw(); }
	};

public:
	class Registration
	{
		friend class DrawRegistrationCommand;
		friend class DrawDeregisterCommand;

	private:
		///		\brief Passthrough for SceneRegistration for Drawable.
		static void SceneRegistration(Drawable* pMgr) { pMgr->SceneRegistration(); }
		///		\brief Passthrough for SceneDeregistration for Drawable.
		static void SceneDeregistration(Drawable* pMgr) { pMgr->SceneDeregistration(); }
	};

public:
	class Registration2D
	{
		friend class Draw2DRegistrationCommand;
		friend class Draw2DDeregistrationCommand;

	private:
		///		\brief Passthrough for SceneRegistration for Drawable2D.
		static void SceneRegistration2D(Drawable2D* pMgr) { pMgr->SceneRegistration(); }
		///		\brief Passthrough for SceneDeregistration for Drawable2D.
		static void SceneDeregistration2D(Drawable2D* pMgr) { pMgr->SceneDeregistration(); }
	};
	class GameLoop2D
	{
		friend class Drawable2DManager;
	private:
		///		\brief Passthrough for Drawable2DManager.
		static void Draw2D(Drawable2D* pMgr) { pMgr->Draw2D(); }
	};
};


#endif // 
