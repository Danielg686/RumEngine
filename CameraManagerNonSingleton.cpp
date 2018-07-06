#include "CameraManagerNonSingleton.h"
#include "GodCam.h"

CameraManagerNonSingleton::CameraManagerNonSingleton()
{
//	GodClass = new GodCam();
//	GodCamera = GodClass->GetGodCam();

	defaultCam = new Camera(Camera::Type::PERSPECTIVE_3D);
	defaultCam->setViewport(0, 0, RumEngine::GetWidth(), RumEngine::GetHeight());
	defaultCam->setPerspective(35.0f, float(RumEngine::GetWidth()) / float(RumEngine::GetHeight()), 1.0f, 5000.0f);

	Vect up3DCam(0.0f, 1.0f, 0.0f);
	Vect pos3DCam(50.0f, 50.0f, 150.0f);
	Vect lookAt3DCam(0.0f, 0.0f, 0.0f);
	defaultCam->setOrientAndPosition(up3DCam, lookAt3DCam, pos3DCam);
	defaultCam->updateCamera();  // Note: if the camera moves/changes, we need to call update again

	this->currentCam = defaultCam;

	Cam2D = new Camera(Camera::Type::ORTHOGRAPHIC_2D);
	assert(Cam2D);
	Cam2D->setViewport(0, 0, RumEngine::GetWidth(), RumEngine::GetHeight());

	Cam2D->setOrthographic(-0.5f* RumEngine::GetWidth(), 0.5f* RumEngine::GetWidth(),
							-0.5f* RumEngine::GetHeight(), 0.5f* RumEngine::GetHeight(),
							1.0f, 1000.0f);

	Vect up2DCam(0.0f, 1.0f, 0.0f);
	Vect pos2DCam(0.0f, 0.0f, 0.0f);
	Vect lookAt2DCam(0.0f, 0.0f, -1.0f);
	Cam2D->setOrientAndPosition(up2DCam, lookAt2DCam, pos2DCam);
	Cam2D->updateCamera();
}

CameraManagerNonSingleton::~CameraManagerNonSingleton()
{
	delete defaultCam;
//	delete currentCam;
	delete Cam2D;
//	delete GodCamera;
	
//	delete GodClass; 
	this->currentCam = nullptr;
}
