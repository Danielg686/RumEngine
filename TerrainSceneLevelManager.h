//Daniel Goodrum May 2018
//TerrainSceneLevelManager

#ifndef _TerrainSceneLevelManager
#define _TerrainSceneLevelManager

#include "AzulCore.h"
#include <string>
#include "TerrainManager.h"
class TerrainModel;

class TerrainSceneLevelManager
{
public:
	TerrainSceneLevelManager() = default;
	~TerrainSceneLevelManager() = default;
	TerrainSceneLevelManager(const TerrainSceneLevelManager&) = delete;
	TerrainSceneLevelManager& operator = (const TerrainSceneLevelManager&) = delete;

	void SetTerrain(std::string name) { pTerrain = TerrainManager::getTerrainModel(name); }
	TerrainModel* GetTerrain() { return pTerrain; }

private:
	TerrainModel* pTerrain;

};








#endif // !_TerrainSceneLevelManager
