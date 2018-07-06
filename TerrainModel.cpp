  #include "TerrainModel.h"
#include "TextureTGA.h"
#include "RumEngine.h"
#include "Model.h"
#include "MathTools.h"
#include "Visualizer.h"
#include "Collidable.h"
#include "ShaderManager.h"

//#include "CollisionVolume.h"
//#include "Matrix.h"




TerrainModel::TerrainModel(const char * filename, float sidelength, float height, float ytrans, int RepeatU, int RepeatV, Texture* text)
{
	Sidelength = sidelength;
	int imgWidth, imgHeight, icomp;
	unsigned int dtype;
	GLbyte* imgData = gltReadTGABits(filename, &imgWidth, &imgHeight, &icomp, &dtype);
	assert(imgWidth == imgHeight && imgWidth != 0);
	
	gridSideLength = imgHeight;

	int nsquared = (int)((int)(powf(imgHeight - 1.0f, 2.0f)) - 0.5f);

	int pixelWidth = 3;
	
	int numTris = nsquared * 2;
	int numVerts = numTris * 3;
	VertexStride_VUN * pVerts = new VertexStride_VUN[numVerts];
	TriangleIndex *tlist = new TriangleIndex[numTris];
	MinMaxArray = new TerrainMinMax[nsquared];
	sizeofMinMaxArray = nsquared;

	float start = -1 * (sidelength / 2);
	float xpos = 0;		// start at back left corner
	float zpos = 0;
	float step = 1 * (sidelength / imgHeight);
	Step = step;
	int count = 0;
	int vertItr = 0;
	int triItr = 0;

	float x, y, z;
	Vect temp;

	float MinX, MinY, MinZ, MaxX, MaxY, MaxZ;

//	for (int squareItr = 0; squareItr < nsquared; ++squareItr)
	for (int squareItr = 0; squareItr < nsquared; ++squareItr)
	{
		if (count == imgHeight)
		{
			count = 0;
			xpos = 0;
			zpos += 1.0f;
		}

		x = start + xpos * step;
		y = this->PixelHeight(xpos, zpos, height, imgData, pixelWidth, imgHeight);
		z = start + zpos * step;

		temp = Vect(x, y, z).norm();
		pVerts[vertItr].set(x, y, z, (float)RepeatU, (float)RepeatV, temp.X(),temp.Y(),temp.Z());  //this needs to be changed for x/y/z norms
		
		//pVerts[vertItr].normal = Vect(x, y, z).norm();

		MinX = x;
		MinY = y;
		MinZ = z;
		MaxX = x;
		MaxY = y;
		MaxZ = z;


		x = start + xpos * step;
		y = this->PixelHeight(xpos, (zpos + 1), height, imgData, pixelWidth, imgHeight);
		z = start + (zpos + 1) * step;
		temp = Vect(x, y, z).norm();
		pVerts[vertItr + 1].set(x, y, z, (float)RepeatU, 0.0f, temp.X(), temp.Y(), temp.Z()); //this needs to be changed for x/y/z norms
		//pVerts[vertItr + 1].set(x, y, z, 0.0f, 0.0f, temp.X(), temp.Y(), temp.Z()); //this needs to be changed for x/y/z norms
		//pVerts[vertItr + 1].normal = Vect(x, y, z).norm();

		if (x < MinX)
		{
			MinX = x;
		}
		if(y < MinY)
		{
			MinY = y;
		}
		if (z < MinZ)
		{
			MinZ = z;
		}
		if (x > MaxX)
		{
			MaxX = x;
		}
		if (y > MaxY)
		{
			MaxY = y;
		}
		if (z > MaxZ)
		{
			MaxZ = z;
		}

		x = start + (xpos + 1) * step;
		y = this->PixelHeight((xpos + 1), (zpos + 1), height, imgData, pixelWidth, imgHeight);
		z = start + (zpos + 1) * step;
		temp = Vect(x, y, z).norm();
		pVerts[vertItr + 2].set(x, y, z, 0.0f, 0.0f, temp.X(), temp.Y(), temp.Z());  //this needs to be changed for x/y/z norms
		//pVerts[vertItr + 2].set(x, y, z, 0.0f, 0.0f, (float)RepeatV, temp.X(), temp.Y(), temp.Z());  //this needs to be changed for x/y/z norms
		//pVerts[vertItr + 2].normal = Vect(x, y, z).norm();

		if (x < MinX)
		{
			MinX = x;
		}
		if (y < MinY)
		{
			MinY = y;
		}
		if (z < MinZ)
		{
			MinZ = z;
		}
		if (x > MaxX)
		{
			MaxX = x;
		}
		if (y > MaxY)
		{
			MaxY = y;
		}
		if (z > MaxZ)
		{
			MaxZ = z;
		}

		x = start + (xpos + 1) * step;
		y = this->PixelHeight((xpos + 1), zpos, height, imgData, pixelWidth, imgHeight);
		z = start + zpos * step;
		temp = Vect(x, y, z).norm();
		pVerts[vertItr + 3].set(x, y, z, 0.0f, (float)RepeatV, temp.X(), temp.Y(), temp.Z()); //this needs to be changed for x/y/z norms
		//pVerts[vertItr + 3].set(x, y, z, 0, (float)RepeatU, (float)RepeatV, temp.X(), temp.Y(), temp.Z()); //this needs to be changed for x/y/z norms
		//pVerts[vertItr + 3].normal = Vect(x, y, z).norm();

		if (x < MinX)
		{
			MinX = x;
		}
		if (y < MinY)
		{
			MinY = y;
		}
		if (z < MinZ)
		{
			MinZ = z;
		}
		if (x > MaxX)
		{
			MaxX = x;
		}
		if (y > MaxY)
		{
			MaxY = y;
		}
		if (z > MaxZ)
		{
			MaxZ = z;
		}

		tlist[triItr].set(vertItr, vertItr + 1, vertItr + 2);
		tlist[triItr + 1].set(vertItr, vertItr + 2, vertItr + 3);

		vertItr += 4;
		triItr += 2;
		++count;
		xpos += 1.0f;

		MinMaxArray[squareItr].Max = Vect(MaxX, MaxY, MaxZ);
		MinMaxArray[squareItr].Min = Vect(MinX, MinY, MinZ);

	}

	pTerrainMod = new Model(pVerts, numVerts, tlist, numTris);
	pTexture = text;

	WorldMatrix = Matrix(TRANS, 0.0f, ytrans, 0.0f);

	delete[] pVerts;
	delete[] tlist;



	//Vect col = Color::Black;
	//pGO_Ground = new GraphicsObject_WireframeConstantColor(pTerrainModel->GetModel(), ShaderManager::Get("pShaderObject_constantColor"), col);

	//Matrix world = Matrix(IDENTITY);
	//Vect pos = Vect(0, 0, 0);
	//world = Matrix(SCALE, 1, 1, 1) * Matrix(IDENTITY) * Matrix(TRANS, pos);
	//pGO_Ground->SetWorld(world);

	Vect LightColor(1.50f, 1.50f, 1.50f, 1.0f);
	Vect LightPos(100.0f, 100.0f, 100.0f, 100.0f);
	//pGO_Text = new GraphicsObject_TextureLight(pTerrainMod, ShaderManager::Get("pShaderObject_textureLight"), pTexture, LightColor, LightPos);

	pGO_Text = new GraphicsObject_TextureFlat(pTerrainMod, ShaderManager::Get("pShaderObject_texture"), pTexture);
	Matrix world = Matrix(IDENTITY);
	Vect pos = Vect(0, 0, 0);
	world = Matrix(SCALE, 1, 1, 1) * Matrix(IDENTITY) * Matrix(TRANS, pos);
	pGO_Text->SetWorld(world);

	//this->SubmitDrawRegistration();
	this->SubmitDrawRegistration();
}

void TerrainModel::Intersect(const Vect & point)
{

	int t = getGridSpace(point);
	if (t >= 0)
	{
		if (MathTools::Intersect(point, MinMaxArray[t].Min, MinMaxArray[t].Max))
		{
			Visualizer::ShowPointTerrainSquare(MinMaxArray[t].Min, MinMaxArray[t].Max, Color::Red);
		}
	}
}

//Code is no longer used, the functionallity has been moved to the CollisionTestTerrainCommand.
void TerrainModel::Intersect(const CollisionVolumeBSphere & bsphere)
{
	CollisionVolumeAABB tempAABB;
	float t = bsphere.GetRadius();
	Vect temp = bsphere.GetCenter();
	Vect min = Vect(temp.X() - t, temp.Y() - t, temp.Z() - t);
	Vect max = Vect(temp.X() + t, temp.Y() + t, temp.Z() + t);
	int minbox = getGridSpace(min);
	int maxbox = getGridSpace(max);
	CollisionVolumeAABB renderAABB;
	renderAABB.SetMinAndMax(min, max);
	Visualizer::ShowAABB(renderAABB, Color::Red);
	int i = minbox;
	int j = 0;
	int k = 0;
	while ( i <= maxbox)
	{
		tempAABB.SetMinAndMax(MinMaxArray[i].Min, MinMaxArray[i].Max);
		if (MathTools::Intersect(bsphere, tempAABB))
		{
			Visualizer::ShowPointTerrainSquare(MinMaxArray[i].Min, MinMaxArray[i].Max, Color::Purple);
		}
		if ((i + gridSideLength) <= maxbox)
		{
			i += gridSideLength;
		}
		else
		{
			j += 1;
			i = minbox + j;
		}
		k++;
	}
	k++;
}

//Code is no longer used, the functionallity has been moved to the CollisionTestTerrainCommand.
void TerrainModel::Intersect(const Collidable & c)
{
	CollisionVolumeAABB tempAABB;

	float t = c.GetStandardBSphere().GetRadius();
	Vect temp = c.GetStandardBSphere().GetCenter();
	Vect min = Vect(temp.X() - t, temp.Y() - t, temp.Z() - t);
	Vect max = Vect(temp.X() + t, temp.Y() + t, temp.Z() + t);
	int minbox = getGridSpace(min);
	int maxbox = getGridSpace(max);
	CollisionVolumeAABB renderAABB;
	renderAABB.SetMinAndMax(min, max);
	Visualizer::ShowAABB(renderAABB, Color::Red);
	int i = minbox;
	int j = 0;
	int k = 0;
	while (i <= maxbox)
	{
		
		tempAABB.SetMinAndMax(MinMaxArray[i].Min, MinMaxArray[i].Max);
		if (MathTools::Intersect(c.GetStandardBSphere(), tempAABB))
		{
			Visualizer::ShowPointTerrainSquare(MinMaxArray[i].Min, MinMaxArray[i].Max, Color::Red);
			Visualizer::ShowBSphere(c.GetStandardBSphere(), Color::Red);
			if (tempAABB.Intersect(c.GetColVolume()))
			{
				Visualizer::ShowPointTerrainSquare(MinMaxArray[i].Min, MinMaxArray[i].Max, Color::Black);
				Visualizer::ShowCollisionVolume(&c, Color::Black);
			}
		}
		if ((i + gridSideLength) <= maxbox)
		{
			i += gridSideLength;
		}
		else
		{
			j += 1;
			i = minbox + j;
		}
	//	k++;
	}
	k++;
}

void TerrainModel::Intersect(const Collidable & c, TerrainMinMax & Array, int & minVal, int & maxVal)
{
	Array = *MinMaxArray;
	float t = c.GetStandardBSphere().GetRadius();
	Vect temp = c.GetStandardBSphere().GetCenter();
	Vect min = Vect(temp.X() - t, temp.Y() - t, temp.Z() - t);
	Vect max = Vect(temp.X() + t, temp.Y() + t, temp.Z() + t);
	minVal = getGridSpace(min);
	maxVal = getGridSpace(max);
}



void TerrainModel::Draw()
{
	pGO_Text->Render(SceneManager::GetCurrentScene()->GetCurrentCamera());
}

void TerrainModel::VisualizeAll()
{
	for (int i = 0; i < sizeofMinMaxArray; i++)
	{
		Visualizer::ShowPointTerrainSquare(MinMaxArray[i].Min, MinMaxArray[i].Max);
	}
}

//TODO
//Need to fix once I figure baricentric out.
float TerrainModel::GetGridHeight(const Vect & pos)
{
	int space = getGridSpace(pos);
	Vect max = MinMaxArray[space].Max;
	Vect min = MinMaxArray[space].Min;
	Vect returnVect = (max + min);
	return returnVect.Y()/2;
}

TerrainModel::~TerrainModel()
{
	delete[] MinMaxArray;
}

float TerrainModel::PixelHeight(float x, float z, float maxheight, GLbyte * heightMapImg, int pixel_width, int side)
{

	uint8_t h_val = heightMapImg[(int)(pixel_width * (z * (float)side + x))];

	int heightInt = (int)h_val;
	float rval;

	if (heightInt == 0)
		rval = 0;
	else
		rval = maxheight * ((float)h_val / 255.0f);

	return rval;
	//return 0.0f;
}

int TerrainModel::getGridSpace(const Vect & pos)
{
	float tempx = pos.X() - MinMaxArray[0].Min.X();
	float sizex = MinMaxArray[0].Max.X() - MinMaxArray[0].Min.X();
	float tempz = pos.Z() - MinMaxArray[0].Min.Z()  ;
	float sizeZ = MinMaxArray[0].Max.Z() - MinMaxArray[0].Min.Z();

	int tx = (int)(tempx / sizex);
	int tz = (int)(tempz/ sizeZ);
	if (tx >= MinMaxArray[0].Min.X() && tz >= MinMaxArray[0].Min.Z())
	{
		return (int)(tx + ( 256 *tz));
	}
	return -1;
}
