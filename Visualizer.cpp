#include "Visualizer.h"
#include "ModelManager.h"
#include "ShaderManager.h"
#include "SceneManager.h"
#include "CameraManager.h"
#include "AzulCore.h"
#include "VisualizeBSphereCommand.h"
#include "VisualizeAABBCommand.h"
#include "VisualizerCommandFactory.h"
#include "Collidable.h"

Visualizer* Visualizer::ptrInstance = nullptr;

Vect Visualizer::DEFAULT_COLOR = Color::Blue;

Visualizer::Visualizer()
{
	WFUnitSphere = new GraphicsObject_WireframeConstantColor(ModelManager::Get("PModelSphere"), ShaderManager::Get("pShaderObject_constantColor"), DEFAULT_COLOR);
	WFUnitBox = new GraphicsObject_WireframeConstantColor(ModelManager::Get("PModelBox"), ShaderManager::Get("pShaderObject_constantColor"), DEFAULT_COLOR);
}

Visualizer::~Visualizer()
{
	delete WFUnitSphere;
	VisualizerCommandFactory::Terminate();
}

void Visualizer::Delete()
{
	StorageList::const_iterator itr = Instance().VisualizeList.begin();
	while (itr != Instance().VisualizeList.end())
	{
		StorageList::const_iterator temp = itr;
		itr++;
		delete (*temp);
	}
	Instance().VisualizeList.clear();
	DebugMsg::out("Visualizer delete called\n");
	delete ptrInstance;
	ptrInstance = nullptr;
}

void Visualizer::privRenderBSphere(Matrix& S, Vect& col)
{
//	Vect temp = col;
	WFUnitSphere->SetWorld(S);
	WFUnitSphere->pWireColor->set(col);// = &temp;
	WFUnitSphere->Render(SceneManager::GetCurrentScene()->GetCurrentCamera());

}

void Visualizer::privRenderAABB(Matrix& S, Vect& col)
{
	WFUnitBox->SetWorld(S);
	WFUnitBox->pWireColor->set(col);
	WFUnitBox->Render(SceneManager::GetCurrentScene()->GetCurrentCamera());
}

void Visualizer::privShowBSphere(const CollisionVolumeBSphere & S, const Vect & col)
{
	//VisualizeBSphereCommand* temp = new VisualizeBSphereCommand(S, col);
	//VisualizeList.push_back(temp);
	Matrix m;
	Vect vBSSize = S.GetRadius() * Vect(1, 1, 1);
	Vect vBSPos = S.GetCenter();

	m = Matrix(SCALE, vBSSize) * Matrix(TRANS, vBSPos);

	Vect t = col;

	VisualizeBSphereCommand* temp = VisualizerCommandFactory::addBSphereVisualizeCommand(m, t);
	VisualizeList.push_front(temp);
}

void Visualizer::privShowAABB(const CollisionVolumeAABB & S, const Vect & col)
{
	Matrix m;
	Vect Scale = S.GetCornerMax() - S.GetCornerMin();
	Vect Trans = .5f *(S.GetCornerMin() + S.GetCornerMax());

	m = Matrix(SCALE, Scale) * Matrix(TRANS, Trans);

	Vect t = col;

	VisualizeAABBCommand* temp = VisualizerCommandFactory::addAABBVisualizeCommand(m, t);
	VisualizeList.push_front(temp);
	//UNREFERENCED_PARAMETER(S);
	//UNREFERENCED_PARAMETER(col);
}

void Visualizer::privShowClampPoint(const Vect & pos)
{
	Matrix m;
	Vect Scale = Vect(1.4f, 1.4f, 1.4f);
	//Vect Pos = pos;
	
	m = Matrix(SCALE, Scale)* Matrix(TRANS, pos);

	Vect t = Color::Purple;
	VisualizeAABBCommand* temp = VisualizerCommandFactory::addAABBVisualizeCommand(m, t);
	VisualizeList.push_front(temp);
}

void Visualizer::privShowOBB(const CollisionVolumeOBB & S, const Vect & col)
{
	Matrix m;
	Vect Scale = S.GetCornerMax() - S.GetCornerMin();
	Vect trans = .5f*(S.GetCornerMax() + S.GetCornerMin());
	m = Matrix(SCALE, Scale) * Matrix(TRANS, trans);
	Matrix world = S.GetWorld();
	m *= world;


	//Make sure this works, either rename to VizualizeBoxCommand or add for OBB
	Vect t = col;
	VisualizeAABBCommand* temp = VisualizerCommandFactory::addAABBVisualizeCommand(m, t);
	VisualizeList.push_front(temp);
}

void Visualizer::privShowGroupAABB(const CollisionVolumeAABB & S, const Vect & col)
{
	privShowAABB(S, col);
}

void Visualizer::privShowTerrainSquare(const Vect & Min, const Vect & Max, const Vect& col)
{
	Matrix m;
	Vect Scale = Max - Min;
	Vect Trans = .5f *(Min + Max);

	m = Matrix(SCALE, Scale) * Matrix(TRANS, Trans);

	Vect t = col;
	VisualizeAABBCommand* temp = VisualizerCommandFactory::addAABBVisualizeCommand(m, t);
	VisualizeList.push_front(temp);
}


void Visualizer::privVisualizeAll()
{
	CommandBase *temp;
	StorageList::const_iterator itr = VisualizeList.begin();
	//DebugMsg::out("Size of Visualizer List is %d \n", VisualizeList.size());
	while(itr != VisualizeList.end())
	{
		temp = (*itr);
		temp->execute();
		itr++;
		//VisualizeList.remove(temp);
		//VisualizerCommandFactory::RecycleBSphereCommand(temp);
		
	}
	//DebugMsg::out("Size of Visualizer list: %d\n", VisualizeList.size());
	VisualizeList.clear();
}

void Visualizer::ShowCollisionVolume(const Collidable * c, const Vect & col)
{
	c->GetColVolume().DebugView(col);
}
