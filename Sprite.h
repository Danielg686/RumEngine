//Sprite
//Daniel Goodrum, Mar 2018

#ifndef SPRITE_H
#define SPRITE_H

#include "AzulCore.h"
#include "Align16.h"
class Sprite : public Align16
{
public:
	Sprite() = delete;
	///\brief Creates a Sprtie from a given Model, Shader and Image
	Sprite(Model* pMod, ShaderObject* pShader, Image* pImage);
	Sprite(const Sprite&) = default;
	Sprite& operator = (const Sprite&) = default;
	virtual ~Sprite();

	/// \brief Renders the sprite, Should be called Draw2D 
	void Render();

	/// \brief Sets Sprite at a specified value;
	void SetLocation(float x, float y);
	/// \brief Rotates the sprite around its origin.
	/// Default is 0;
	void RotateSprite(float Ang);
	/// \brief Scales Sprite by a given value
	/// Default is 1,1.
	void ScaleSprite(float xScale, float yScale);
	/// \brief Changes from default 2D camera.
	void ChangeFromDefaultCamera(Camera* cam);

	Camera* GetCamera() { return pCam2D; }
private:
	GraphicsObject_Sprite* pSprite;

	Camera* pCam2D;

	Matrix World;
	Matrix Scale;
	Matrix RotZ;
	Matrix Trans;

	float posX;
	float posY;
	float RotationAngle = 0;
protected:


};
#endif // !SPRITE_H
