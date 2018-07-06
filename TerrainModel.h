//TerrainModel
//Daniel Goodrum April 2018

#ifndef _TerrainModel
#define _TerrainModel

#include "GpuVertTypes.h"
#include "Texture.h"
#include <string>
#include "Matrix.h"
#include "TerrainMinMax.h"
#include "AzulCore.h"
//#include "GameObject.h"
#include "Drawable.h"

class Model;
class Collidable;
//class Matrix;
class CollisionVolumeBSphere;
//class GameObject;

class TerrainModel : public virtual Drawable, public Align16
{
	friend class TerrainIterator;
public:
	TerrainModel() = delete;
	TerrainModel(const char* filename,float sidelength, float height, float ytrans, int repeatU, int repeatV, Texture* text);
	Model* GetModel() { return pTerrainMod; }
	Texture* GetTexture() { return pTexture; }
	TerrainMinMax* GetTerrainMinMaxArray() { return MinMaxArray; }
	int GetSizeOfTerrainMinMaxArray() { return sizeofMinMaxArray; }

	void Intersect(const Vect& point);

	void Intersect(const CollisionVolumeBSphere& bsphere);

	void Intersect(const Collidable& c);

	void Intersect(const Collidable & c, TerrainMinMax& Array, int& minVal, int& maxVal);

	virtual void Draw();
	
	void VisualizeAll();

	float GetGridHeight(const Vect& pos);

	float GetSideLength() { return Sidelength; }
	
	~TerrainModel();

private:
	float PixelHeight(float x, float z, float maxheight, GLbyte * heightMapImg, int pixel_width, int side);

	int getGridSpace(const Vect& pos);

	Model* pTerrainMod;
	Texture* pTexture;
	Matrix WorldMatrix;
	TerrainMinMax* MinMaxArray;

	//for GO creation
	GraphicsObject_WireframeConstantColor *pGO_Ground;
	//	GraphicsObject_TextureLight *pGO_Text;
	GraphicsObject_TextureFlat *pGO_Text;

	int sizeofMinMaxArray;
	int gridSideLength;

	float Sidelength;
	float Step;
};




#endif // !_TerrainModel

