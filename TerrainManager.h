//Terrain Manager
//Daniel Goodrum May 2018

#ifndef _TerrainManager
#define _TerrainManager

#include "RumEngine.h"
#include <map>
#include <string>
#include "TerrainModel.h"

class Texture;
class Model;

class TerrainManager
{
	friend class TerrainManagerAttorney;
public:
	
	///-----------------------------------------------------------------------------
	/// \brief TerrainManager::Load(const std::string MapKey, const std::string path, Texture* text,  float sidelength, float height, float yStart, float repeatU, float repeatV)
	///     Loads a Terrain using a greyscale map loaded as a texture. Sidelength is the size of the terrain, height is the y-value max height of the terrain
	///		yStart is the start height value of the terrain, repeatU and repeatV are the UV coord values
	///     MapKey should be a unique value.
	///
	///		Terrain model should be first thing loaded within each scene if there is one.
	///     
	///-----------------------------------------------------------------------------
	static void Load(const std::string Mapkey, const std::string path, Texture* text, float sidelength, float height, float yStart, float repeatU, float repeatV) { Instance().privLoad(Mapkey, path, text, sidelength, height, yStart, repeatU, repeatV); }

	///-----------------------------------------------------------------------------
	/// \brief TerrainManager::getTerrainModel(const std::string MapKey)
	///		returns a Terrain Model that is represented by the specific user specified key
	///	
	/// 
	///
	///	
	/// 
	///-----------------------------------------------------------------------------
	static TerrainModel* getTerrainModel(const std::string MapKey) { return Instance().privGetTerrainModel(MapKey); }

private:
	static TerrainManager* ptrInstance;

	TerrainManager() = default;

	TerrainManager(const TerrainManager&) = delete;
	TerrainManager &operator = (const TerrainManager&) = delete;
	~TerrainManager();

	static TerrainManager& Instance()
	{
		if (!ptrInstance)
		{
			ptrInstance = new TerrainManager;
		}
		return *ptrInstance;
	}
	std::map<std::string, TerrainModel*>GameTerrains;

	void privLoad(const std::string Mapkey, const std::string path, Texture* text, float sidelength, float height, float yStart, float repeatU, float repeatV);
	TerrainModel* privGetTerrainModel(const std::string MapKey);

	bool doesKeyExist(const std::string Mapkey);


	///----------------------------------------------------------------------------
	/// \brief TerrainManager::Delete()
	///		Deletes all loaded Models
	///-----------------------------------------------------------------------------	
	
	static void Delete() { Instance().privDelete(); }
	void privDelete();
};





#endif // !_TerrainManager
