//CameraManagerNonSingleton
//Daniel Goodrum, Feb 2018

#ifndef CAMERAMANAGERNONSINGLETON_H
#define CAMERAMANAGERNONSINGLETON_H

#include "RumEngine.h"
#include "Align16.h"
class GodCam;

class CameraManagerNonSingleton : public virtual Align16
{

public:
	CameraManagerNonSingleton();
	~CameraManagerNonSingleton();
	CameraManagerNonSingleton(const CameraManagerNonSingleton&) = delete;
	CameraManagerNonSingleton &operator = (const CameraManagerNonSingleton&) = delete;

	/// \brief Allows for a new user defined camera to be set as current camera;
	void setCurrentCamera(Camera* pCamera) { currentCam = pCamera; }

	//void SetGodCamera() { currentCam = GodCamera; }

	/// \brief Gets Current camera
	Camera* getCurrentCamera() { return currentCam; }

	/// \brief Returns Orthogonal 2D Camera
	Camera* get2DCamera() { return Cam2D; }

private:

	/// \brief Default loaded Camera
	Camera* defaultCam;
	/// \brief Current Camera Utilized throughout the system
	Camera* currentCam;
	/// \brief Orthogonal 2D Camera Preloaded
	Camera* Cam2D;
	//Camera* GodCamera;

	//GodCam* GodClass;


};



#endif // !CAMERAMANAGERNONSINGLETON_H
