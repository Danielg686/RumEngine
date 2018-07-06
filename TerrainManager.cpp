#include "TerrainManager.h"

TerrainManager* TerrainManager::ptrInstance = nullptr;

TerrainManager::~TerrainManager()
{
}

void TerrainManager::privLoad(const std::string Mapkey, const std::string path, Texture* text, float sidelength, float height, float yStart, float repeatU, float repeatV)
{
	if (!doesKeyExist(Mapkey))
	{
		const std::string temp = path + ".tga";
		GameTerrains[Mapkey] = new TerrainModel(temp.c_str(), sidelength, height, yStart,(int)repeatU, (int)repeatV, text);
	}
}

TerrainModel * TerrainManager::privGetTerrainModel(const std::string MapKey)
{
	if (doesKeyExist(MapKey))
	{
		return GameTerrains[MapKey];
	}
	return nullptr;
}

bool TerrainManager::doesKeyExist(const std::string Mapkey)
{
	return (GameTerrains.count(Mapkey) != 0);
}

void TerrainManager::privDelete()
{
	TerrainModel* temp;
	auto itr = GameTerrains.begin();
	while (!GameTerrains.empty())
	{
		auto tempitr = itr;
		temp = (*itr).second;
		itr++;
		delete temp;
		GameTerrains.erase((*tempitr).first);
	}
	delete ptrInstance;
	ptrInstance = nullptr;
}
