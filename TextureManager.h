//Texture Manager
//Daniel Goodrum, Jan 2018

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "RumEngine.h"
//#include "AzulCore.h"
#include <map>
#include <string>

class TextureManager
{
	friend class TextureManagerAttorney;
public:

	///-----------------------------------------------------------------------------
	/// \brief TextureManager::Load(const std::string MapKey, const std::string path)
	///     Loads a texture
	///     MapKey should be a unique value.    
	///-----------------------------------------------------------------------------
	static void Load(const std::string MapKey, const std::string path) { Instance().privLoad(MapKey, path); }
	///-----------------------------------------------------------------------------
	/// \brief TextureManager::Load(const std::string MapKey, const unsigned char red, const unsigned char green, const unsigned char blue, const unsigned char alpha)
	///     Loads a texture
	///     MapKey should be a unique value.    
	///-----------------------------------------------------------------------------
	static void Load(const std::string MapKey, const unsigned char red, const unsigned char green, const unsigned char blue, const unsigned char alpha) { Instance().privLoad(MapKey, red, green, blue, alpha); }
	///-----------------------------------------------------------------------------
	/// \brief  TextureManager::Get(const std::string MapKey)
	///      Returns pointer to Texture object
	///-----------------------------------------------------------------------------
	static Texture* Get(const std::string MapKey) { return Instance().privGet(MapKey); }
	
private:
	static TextureManager* ptrInstance;

	TextureManager() = default;

	TextureManager(const TextureManager&) = delete;
	TextureManager &operator = (const TextureManager&) = delete;
	~TextureManager();

	static TextureManager& Instance()
	{
		if (!ptrInstance)
		{
			ptrInstance = new TextureManager;
		}
		return *ptrInstance;
	}

	std::map<std::string, Texture*> GameTextures;


	void privLoad(const std::string MapKey, const std::string path);
	void privLoad(const std::string MapKey, const unsigned char red, const unsigned char green, const unsigned char blue, const unsigned char alpha);
	Texture* privGet(const std::string MapKey);
	void privDelete();
	bool doesKeyExist(const std::string MapKey);

	static void Delete() { Instance().privDelete(); }

};



#endif // !TEXTUREMANAGER_H
