#include "Sprite.h"
#include "ModelManager.h"
#include"ShaderManager.h"
#include "ImageManager.h"
#include "TextureManager.h"
#include "SceneManager.h"

Sprite::Sprite(Model * pMod, ShaderObject * pShader, Image * pImage)
{
	pCam2D = SceneManager::GetCurrentScene()->Get2Dcam();
	pSprite = new GraphicsObject_Sprite(pMod, pShader, pImage, new Rect(150.0f, 400.0f, 100.0f, 100.0f));
	
	posX = pSprite->origPosX;
	posY = pSprite->origPosY;
	Scale.set(SCALE, 1.0f, 1.0f, 1.0f);
	RotZ.set(ROT_Z, 0.0f);
	Trans.set(TRANS, posX, posY, 0.0f);

	World = Scale * RotZ * Trans;

	pSprite->SetWorld(World);
}

Sprite::~Sprite()
{
	delete pSprite;
	pCam2D = nullptr;
}

//void Sprite::SetOrigCenter()
//{
//	SetOrigin(pSprite->origWidth / 2, pSprite->origHeight / 2);
//}

//void Sprite::SetOriginCenter()
//{
//	//pSprite->pImage->pImageRect->y = pSprite->pImage->pImageRect->height / 2;
//	//pSprite->pImage->pImageRect->x = pSprite->pImage->pImageRect->width/ 2;
//}
//
//void Sprite::SetOrigin(float x, float y)
//{
//	//pSprite->pImage->pImageRect->height = y;
//	//pSprite->pImage->pImageRect->width = x;
//}

void Sprite::Render()
{
	pSprite->Render(pCam2D);
}

void Sprite::SetLocation(float x, float y)
{
	posX = x;
	posY = y;

	Trans.set(TRANS, x, y, 0.0f);

	World = Scale * RotZ * Trans;

	pSprite->SetWorld(World);
}


void Sprite::RotateSprite(float Ang)
{
	RotZ.set(ROT_Z, Ang);

	World = Scale * RotZ * Trans;

	pSprite->SetWorld(World);
}

void Sprite::ScaleSprite(float xScale, float yScale)
{
	Scale.set(SCALE, xScale, yScale, 1.0f);

	World = Scale * RotZ * Trans;

	pSprite->SetWorld(World);
}

void Sprite::ChangeFromDefaultCamera(Camera * cam)
{
	pCam2D = cam;
}


