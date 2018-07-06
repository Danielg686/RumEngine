////CameraManager
////Daniel Goodrum, Jan 2018
//
//#include "CameraManager.h"
//
//CameraManager* CameraManager::ptrInstance = nullptr;
//
//CameraManager::CameraManager()
//{
//	defaultCam = new Camera(Camera::Type::PERSPECTIVE_3D);
//	defaultCam->setViewport(0, 0, RumEngine::GetWidth(), RumEngine::GetHeight());
//	defaultCam->setPerspective(35.0f, float(RumEngine::GetWidth()) / float(RumEngine::GetHeight()), 1.0f, 5000.0f);
//
//	Vect up3DCam(0.0f, 1.0f, 0.0f);
//	Vect pos3DCam(50.0f, 50.0f, 150.0f);
//	Vect lookAt3DCam(0.0f, 0.0f, 0.0f);
//	defaultCam->setOrientAndPosition(up3DCam, lookAt3DCam, pos3DCam);
//	defaultCam->updateCamera();  // Note: if the camera moves/changes, we need to call update again
//
//	this->currentCam = defaultCam;
//}
//
//
//void CameraManager::Terminate()
//{
//	delete Instance().defaultCam;
////	this->currentCam = nullptr;
//	delete ptrInstance;
//	ptrInstance = nullptr;
//}
//
//void CameraManager::privSetCurrentCamera(Camera * pCamera)
//{
//	this->currentCam = pCamera;
//}
