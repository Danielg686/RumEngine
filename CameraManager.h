////Camera Manager
////Daniel Goodrum, Jan 2018
//
//#ifndef CAMERAMANAGER_H
//#define CAMERAMANAGER_H
//
//#include "RumEngine.h"
////#include "AzulCore.h"
//
//
//class CameraManager
//{
//
//public:
//
//	static void setCurrentCamera(Camera* pCamera) { Instance().privSetCurrentCamera(pCamera); }
//	static Camera* getCurrentCamera() { return Instance().currentCam; }
//
//private:
//	static CameraManager* ptrInstance;
//
//	CameraManager();
//
//	CameraManager(const CameraManager&) = delete;
//	CameraManager &operator = (const CameraManager&) = delete;
//	~CameraManager() = default;
//
//	static CameraManager& Instance()
//	{
//		if (!ptrInstance)
//		{
//			ptrInstance = new CameraManager;
//		}
//		return *ptrInstance;
//	}
//
//	friend class RumEngine;
//
//	static void Terminate();
//
//
//
//	void privSetCurrentCamera(Camera* pCamera);
//
//	Camera* defaultCam;
//	Camera* currentCam;
//
//};
//
//
//
//
//#endif // !CAMERAMANAGER_H
