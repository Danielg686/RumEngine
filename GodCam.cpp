#include "GodCam.h"

GodCam::GodCam()
{
	Cam = new Camera(Camera::Type::PERSPECTIVE_3D);
	Cam->setViewport(0, 0, RumEngine::GetWidth(), RumEngine::GetHeight());
	Cam->setPerspective(35.0f, float(RumEngine::GetWidth()) / float(RumEngine::GetHeight()), 1.0f, 5000.0f);

	
	this->vPos = Vect(50.0f, 50.0f, 150.0f);
	this->vUp = Vect(0.0f, 1.0f, 0.0f);
	this->vLookAt = Vect(0.0f, 0.0f, 0.0f);
	this->vDir = -(vLookAt - vPos);
	this->vDir.norm();

	this->vRight = vUp.cross(this->vDir);
	this->vRight.norm();

	Cam->setOrientAndPosition(vUp, vLookAt, vPos);
	Cam->updateCamera();

	this->SubmitUpdateRegistration();

	//this->SubmitKeyRegistration(AZUL_KEY::KEY_ARROW_UP, INPUT_EVENT_TYPE::KEY_PRESS);
	//this->SubmitKeyRegistration(AZUL_KEY::KEY_ARROW_DOWN, INPUT_EVENT_TYPE::KEY_PRESS);
	//this->SubmitKeyRegistration(AZUL_KEY::KEY_ARROW_LEFT, INPUT_EVENT_TYPE::KEY_PRESS);
	//this->SubmitKeyRegistration(AZUL_KEY::KEY_ARROW_RIGHT, INPUT_EVENT_TYPE::KEY_PRESS);
}

GodCam::~GodCam()
{
}


void GodCam::Draw()
{
}

void GodCam::Update()
{
	float camSpeed = .05f;

	//if (Keyboard::GetKeyState(AZUL_KEY::KEY_Q))
	//{
	//	vDir = vDir *Matrix(ROT_AXIS_ANGLE, vRight, camSpeed);
	//}
	//else if (Keyboard::GetKeyState(AZUL_KEY::KEY_E))
	//{
	//	vDir = vDir *Matrix(ROT_AXIS_ANGLE, vRight, -camSpeed);
	//}
	//else if (Keyboard::GetKeyState(AZUL_KEY::KEY_I))
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_I))
	{
		vPos -= vDir * 40 * camSpeed;
	}
	else if (Keyboard::GetKeyState(AZUL_KEY::KEY_J))
	{
		vPos += vRight * 40 *-camSpeed;
	}
	else if (Keyboard::GetKeyState(AZUL_KEY::KEY_K))
	{
		vPos -= vDir * 40 * -camSpeed;
	}
	else if (Keyboard::GetKeyState(AZUL_KEY::KEY_L))
	{
		vPos += vRight * 40 * camSpeed;
	}
	else if (Keyboard::GetKeyState(AZUL_KEY::KEY_ARROW_UP))
	{
		vDir = vDir * Matrix(ROT_AXIS_ANGLE, vRight, camSpeed);
	}
	else if (Keyboard::GetKeyState(AZUL_KEY::KEY_ARROW_LEFT))
	{
		vDir = vDir * Matrix(ROT_Y, camSpeed);
	}
	else if (Keyboard::GetKeyState(AZUL_KEY::KEY_ARROW_DOWN))
	{
		vDir = vDir * Matrix(ROT_AXIS_ANGLE, vRight, -camSpeed);
	}
	else if (Keyboard::GetKeyState(AZUL_KEY::KEY_ARROW_RIGHT))
	{
		vDir = vDir * Matrix(ROT_Y, -camSpeed);
	}
	
	Cam->setOrientAndPosition(Vect(0, 1, 0), vPos - vDir, vPos);
	Cam->updateCamera();
	//DebugMsg::out("Input recognize\n");
}

void GodCam::KeyPressed(AZUL_KEY k)
{
	UNREFERENCED_PARAMETER(k);
	//float camSpeed = .004f;
	//switch(k)
	//{
	//case AZUL_KEY::KEY_Q:
	//	vDir = vDir *Matrix(ROT_AXIS_ANGLE, vRight, camSpeed);
	//	break;
	//case AZUL_KEY::KEY_E:
	//	vDir = vDir *Matrix(ROT_AXIS_ANGLE, vRight, -camSpeed);
	//	break;
	////case AZUL_KEY::KEY_W:
	////	vPos = vDir * camSpeed;
	////	break;
	////case AZUL_KEY::KEY_A:
	////	vPos += vRight * camSpeed;
	////	break;
	////case AZUL_KEY::KEY_S:
	////	vPos = vDir * -camSpeed;
	////	break;
	////case AZUL_KEY::KEY_D:
	////	vPos += vRight * -camSpeed;
	////	break;
	//case AZUL_KEY::KEY_ARROW_UP:
	//	vDir = vDir * Matrix(ROT_AXIS_ANGLE, vRight, camSpeed);
	//	break;
	//case AZUL_KEY::KEY_ARROW_LEFT:
	//	vDir = vDir * Matrix(ROT_Y, camSpeed);
	//	break;
	//case AZUL_KEY::KEY_ARROW_DOWN:
	//	vDir = vDir * Matrix(ROT_AXIS_ANGLE, vRight, -camSpeed);
	//	break;
	//case AZUL_KEY::KEY_ARROW_RIGHT:
	//	vDir = vDir * Matrix(ROT_Y, -camSpeed);
	//	break;
	//}
	//Cam->setOrientAndPosition(Vect(0, 1, 0), vPos - vDir, vPos);
	//Cam->updateCamera();
	//DebugMsg::out("Input recognized in GodCam\n");
}

void GodCam::KeyReleased(AZUL_KEY k)
{
	UNREFERENCED_PARAMETER(k);
}
