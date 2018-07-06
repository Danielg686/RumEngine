//ModelManager
//Daniel Goodrum, Jan 2018	

#include "ModelManager.h"
#include <fstream>


ModelManager* ModelManager::ptrInstance = nullptr;


ModelManager::~ModelManager()
{
}

void ModelManager::privLoad(const std::string MapKey, const std::string path)
{
	if (!doesKeyExist(MapKey))
	{
		const std::string temp = path + ".azul";
		GameModels[MapKey] = new Model(temp.c_str());
	}
}

void ModelManager::privLoad(const std::string MapKey, Model::PreMadedeModels pm)
{
	if (!doesKeyExist(MapKey))
	{
		GameModels[MapKey] = new Model(pm);
	}

}

Model* ModelManager::privGet(const std::string MapKey)
{
	if (doesKeyExist(MapKey))
	{
		return GameModels[MapKey];
	}
	return nullptr;
}

void ModelManager::privDelete()
{
	Model* temp;
	auto itr = GameModels.begin();
	while (!GameModels.empty())
	{
		auto tempitr = itr;
		temp = (*itr).second;
		itr++;
		delete temp;
		GameModels.erase((*tempitr).first);
	}
	delete ptrInstance;
	ptrInstance = nullptr;
}

bool ModelManager::canOpenFile(const std::string& fileName)
{
	std::ifstream temp(fileName);
	return (bool)temp;
}

bool ModelManager::doesKeyExist(const std::string MapKey)
{
	return(GameModels.count(MapKey) != 0);
}
