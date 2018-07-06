
#ifndef RUMENGINE_H
#define RUMENGINE_H

#include "AzulCore.h"


class RumEngine : public Engine
{
public:

	static int GetHeight() { return Instance().privGetHeight(); }
	static int GetWidth() { return Instance().privGetWidth(); }
	//static float GetTime() { return Instance().privGetTime(); }
	static void SetClearColor(float red, float green, float blue, float alpha) { Instance().privSetClear(red, green, blue, alpha); }
	static void SetWidthAndHeight(int width, int height) { Instance().privSetWidthHeight(width, height); }
	static void SetWindowName(const char* name) { Instance().privSetWindowName(name); }

	//static float GetCurrentTimeInSeconds() { return Instance().GetTimeInSeconds(); }

	static void Start() { Instance().run(); }
private:
	static RumEngine* ptrInstance;

	//constructor
	RumEngine() = default;

	RumEngine &operator = (const RumEngine&) = delete;
	RumEngine(const RumEngine&) = delete;
	~RumEngine() = default;

	static RumEngine& Instance()
	{
		if (!ptrInstance)
		{
			ptrInstance = new RumEngine;
		}
		return *ptrInstance;
	}


	//Methods user need to overload
	virtual void Initialize();
	virtual void LoadContent();
	virtual void Update();

	/// \brief Calls Draw on all GameObjects
	virtual void Draw();
	virtual void UnLoadContent();

	//legacy
	RumEngine(const char* windowName, const int Width, const int Height);

	int privGetHeight();
	int privGetWidth();
	float privGetTime();
	void privSetClear(float r, float g, float b, float a);
	void privSetWidthHeight(int w, int h);
	void privSetWindowName(const char* name);

	void LoadAllResources();
	///	\brief	Window initialziation
	/// \code
	///		RumEngine::SetWindowName("Place Window Title here");
	///		RumEngine::SetWidthAndHeight(X size of window, Y size of window);
	///
	///		//GLFW Magic in the code below
	///		RumEngine::SetClearColor(0.4f, 0.4f, 0.8f, 1.0f);
	///	\endcode
	void GameInitialize();

	static float GetTime() { return Instance().privGetTime(); }
	static float GetCurrentTimeInSeconds() { return Instance().GetTimeInSeconds(); }
};


#endif // !RUMENGINE_H
