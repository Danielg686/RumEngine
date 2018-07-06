//ModelManager
//Daniel Goodrum, Jan 2018

#ifndef MODELMANAGER_H
#define MODELMANAGER_H


#include "RumEngine.h"
#include "AzulCore.h"
#include <map>
#include <string>

class ModelManager
{
	friend class ModelManagerAttorney;


public:

	///-----------------------------------------------------------------------------
	/// \brief ModelManager::Load(const std::string MapKey, const std::string path)
	///     Loads a Model with .azul format(not needed in the path string)
	///     MapKey should be a unique value.
	///     
	///-----------------------------------------------------------------------------
	static void Load(const std::string MapKey, const std::string path) { Instance().privLoad(MapKey, path); }

	///-----------------------------------------------------------------------------
	/// \brief ModelManager::Load(const std::string MapKey, Model::PreMadedeModels)
	///     Loads a Model from Model::PreMadedeModels
	///     MapKey should be a unique value.
	///     
	///-----------------------------------------------------------------------------
   
	static void Load(const std::string MapKey, Model::PreMadedeModels pm) { Instance().privLoad(MapKey, pm); }
	///-----------------------------------------------------------------------------
	/// \brief ModelManager::get(const std::string MapKey)
	///    Returns a pointer to a model associated with a given MapKey
	///-----------------------------------------------------------------------------
	static Model* Get(const std::string MapKey) { return Instance().privGet(MapKey); }


	

private:
	static ModelManager* ptrInstance;

	ModelManager() = default;

	ModelManager(const ModelManager&) = delete;
	ModelManager &operator = (const ModelManager&) = delete;
	~ModelManager();

	static ModelManager& Instance()
	{
		if (!ptrInstance)
		{
			ptrInstance = new ModelManager;
		}
		return *ptrInstance;
	}

	//map containging Models
	std::map<std::string, Model*> GameModels;


	void privLoad(const std::string MapKey, const std::string path);
	void privLoad(const std::string MapKey, Model::PreMadedeModels pm);
	Model* privGet(const std::string MapKey);
	void privDelete();
	bool canOpenFile(const std::string& fileName);
	bool doesKeyExist(const std::string MapKey);

	///-----------------------------------------------------------------------------
	/// \brief ModelManager::Delete()
	///    Deletes all loaded Models
	///-----------------------------------------------------------------------------
	static void Delete() { Instance().privDelete(); };

};




#endif // !MODELMANAGER_H
