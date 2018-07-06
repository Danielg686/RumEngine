//GodCam
//Daniel Goodrum, Feb 2018

#ifndef GODCAM_H
#define GODCAM_H

#include "Camera.h"
#include "GameObject.h"

class GodCam : public virtual GameObject
{
public:
	/// \brief GodCam::GodCam() Camera that allows movements anywhere, good for debugging.
	/// Controlled with the I,J,K,L and arrow keys.
	GodCam();
	virtual ~GodCam();

	GodCam(const GodCam&) = default;
	GodCam &operator = (const GodCam&) = default;

	virtual void Draw();
	virtual void Update();
	Camera* GetGodCam() { return Cam; }

	virtual void KeyPressed(AZUL_KEY k) override;
	virtual void KeyReleased(AZUL_KEY k) override;
private:

	Camera* Cam;
	Matrix projMatrix;
	Matrix ViewMatrix;
	
	Vect	vUp;
	Vect	vDir;
	Vect	vRight;  // derived by up and dir
	Vect	vPos;
	Vect	vLookAt;
};





#endif // !GODCAM_H
