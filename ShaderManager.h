//ShaderManager
//Daneil Goodrum, Jan 2018

#ifndef SHADERMANAGER_H
#define SHADERMANAGER_H

#include "RumEngine.h"
#include "AzulCore.h"
#include <map>
#include <string>

class ShaderManager
{
	friend class ShaderManagerAttorney;
public:

	///-----------------------------------------------------------------------------
	/// \brief ShaderManager::Load(const std::string MapKey, const std::string path)
	///     Loads a Shader
	///     MapKey should be a unique value.    
	///-----------------------------------------------------------------------------
	static void Load(const std::string MapKey, const std::string path) { Instance().privLoad(MapKey, path); }

	///-----------------------------------------------------------------------------
	/// \brief ShaderManager::Get(const std::string MapKey)
	///     Returns pointer to Shader object
	///-----------------------------------------------------------------------------
	static ShaderObject* Get(const std::string MapKey) { return Instance().privGet(MapKey); }

private:
	static ShaderManager* ptrInstance;

	ShaderManager() = default;

	ShaderManager(const ShaderManager&) = delete;
	ShaderManager &operator = (const ShaderManager&) = delete;
	~ShaderManager();

	static ShaderManager& Instance()
	{
		if (!ptrInstance)
		{
			ptrInstance = new ShaderManager;
		}
		return *ptrInstance;
	}

	/// \brief map containging Shaders
	std::map<std::string, ShaderObject*> GameShaders;

	void privLoad(const std::string MapKey, const std::string path);
	ShaderObject* privGet(const std::string MapKey);
	void privDelete();
	bool doesKeyExist(const std::string MapKey);

	///-----------------------------------------------------------------------------
	/// \brief ShaderManager::Delete()
	///     Deletes all loaded Shaders
	///-----------------------------------------------------------------------------
	static void Delete() { Instance().privDelete(); }


};

















#endif // !SHADERMANAGER_H
