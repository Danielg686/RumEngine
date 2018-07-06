#include "AzulCore.h"
#include "RumEngine.h"
#include "ModelManager.h"
#include "ShaderManager.h"
#include "TextureManager.h"
#include "SceneManager.h"
#include "CameraManager.h"
#include "ModelManagerAttorney.h"
#include "TimeManagerAttorney.h"
#include "SceneAttorney.h"
#include "TextureManagerAttorney.h"
#include "ShaderManagerAttorney.h"
#include "ImageManagerAttorney.h"
#include "VisualizerAttorney.h"
#include "TerrainManager.h"
#include "TerrainManagerAttorney.h"
#include "KeypressLogging.h"


// Global varables just for the demo:
// Note: Don't do this!
// Global vars should always be avoided in a finished product! 

RumEngine* RumEngine::ptrInstance = nullptr;



///-----------------------------------------------------------------------------
/// \brief RumEngine::Initialize()
///		Allows the engine to perform any initialization it needs to before 
///      starting to run.  This is where it can query for any required services 
///      and load any non-graphic related content. 
///-----------------------------------------------------------------------------
void RumEngine::Initialize()
{
	this->GameInitialize();
	

}


///-----------------------------------------------------------------------------
/// \brief RumEngine::LoadContent()
///		Allows you to load all content needed for your engine,
///	    such as objects, graphics, etc.
///-----------------------------------------------------------------------------
void RumEngine::LoadContent()
{
	this->LoadAllResources();
	
	SceneManager::InitStartScene();
}


///-----------------------------------------------------------------------------
/// \brief RumEngine::Update()
///      Called once per frame, update data, tranformations, etc
///      Use this function to control process order
///      Input, AI, Physics, Animation, and Graphics
///-----------------------------------------------------------------------------
void RumEngine::Update()
{

	//if (SceneManager::GetNextScene() != nullptr)
	//{
	//	Scene* temp = SceneManager::GetCurrentScene();
	//	
	//	SceneAttorney::Unload::UnloadScene(temp);
	//	VisualizerAttorney::GameLoop::Delete();
	//	delete temp;
	//	SceneManager::SetStartScene(SceneManager::GetNextScene());
	//	SceneManager::SetNextScene(nullptr);
	//	SceneManager::InitStartScene();
	//}
	KeypressLogging::Update();
	SceneManager::ExecuteSceneCommand();
	TimeManagerAttorney::GameLoop::ProcessTime(this->GetTimeInSeconds());
	SceneManager::Update();

}

///-----------------------------------------------------------------------------
/// \brief RumEngine::Draw()
///		This function is called once per frame
///	    Use this for draw graphics to the screen.
///      Only do rendering here
///-----------------------------------------------------------------------------
void RumEngine::Draw()
{
	VisualizerAttorney::GameLoop::VisualizeAll();
	SceneManager::Draw();
}

///-----------------------------------------------------------------------------
/// \brief RumEngine::UnLoadContent()
///       unload content (resources loaded above)
///       unload all content that was loaded before the Engine Loop started
///-----------------------------------------------------------------------------
void RumEngine::UnLoadContent()
{
	// general clean up.
	VisualizerAttorney::GameLoop::Delete();
	SceneManager::Delete();
	ModelManagerAttorney::Delete();
	TextureManagerAttorney::Delete();
	ShaderManagerAttorney::Delete();
	ImageManagerAttorney::Delete();
	TimeManagerAttorney::GameLoop::Delete();
	TerrainManagerAttorney::Delete();
	KeypressLogging::Delete();
}

int RumEngine::privGetHeight()
{
	return this->getHeight();
}

int RumEngine::privGetWidth()
{
	return this->getWidth();
}

float RumEngine::privGetTime()
{
	return this->GetTimeInSeconds();
}

void RumEngine::privSetClear(float r, float g, float b, float a)
{
	this->color[0] = r;
	this->color[1] = g;
	this->color[2] = b;
	this->color[3] = a;
}

void RumEngine::privSetWidthHeight(int w, int h)
{
	this->setWidthHeight(w, h);
}

void RumEngine::privSetWindowName(const char * name)
{
	this->setWindowName(name);
}