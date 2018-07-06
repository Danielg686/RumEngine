//ModelManager
//Daniel Goodrum, Jan 2018

#include "ShaderManager.h"
#include <fstream>

ShaderManager* ShaderManager::ptrInstance = nullptr;

ShaderManager::~ShaderManager()
{
}

void ShaderManager::privLoad(const std::string MapKey, const std::string path)
{
	if (!doesKeyExist(MapKey))
	{
		GameShaders[MapKey] = new ShaderObject(path.c_str());
	}
}

ShaderObject * ShaderManager::privGet(const std::string MapKey)
{
	if (doesKeyExist(MapKey))
	{
		return GameShaders[MapKey];
	}
	return nullptr;
}

void ShaderManager::privDelete()
{
	ShaderObject* temp;
	auto itr = GameShaders.begin();
	while (!GameShaders.empty())
	{
		auto tempitr = itr;
		temp = (*itr).second;
		itr++;
		delete temp;
		GameShaders.erase((*tempitr).first);
	}
	delete ptrInstance;
	ptrInstance = nullptr;

}

bool ShaderManager::doesKeyExist(const std::string MapKey)
{
	return(GameShaders.count(MapKey) != 0);
}
