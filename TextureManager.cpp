//Texture Manager
//Daniel Goodrum, Jan 2018

#include "TextureManager.h"
#include <fstream>

TextureManager* TextureManager::ptrInstance = nullptr;


TextureManager::~TextureManager()
{
}

void TextureManager::privLoad(const std::string MapKey, const std::string path)
{
	if (!doesKeyExist(MapKey))
	{
		const std::string temp = path + ".tga";
		GameTextures[MapKey] = new Texture(temp.c_str());
	}
}

void TextureManager::privLoad(const std::string MapKey, const unsigned char red, const unsigned char green, const unsigned char blue, const unsigned char alpha)
{
	if (!doesKeyExist(MapKey))
	{
		GameTextures[MapKey] = new Texture(red, green, blue, alpha);
	}
}

Texture * TextureManager::privGet(const std::string MapKey)
{
	if (doesKeyExist(MapKey))
	{
		return GameTextures[MapKey];
	}
	return nullptr;
}

void TextureManager::privDelete()
{
	Texture* temp;
	auto itr = GameTextures.begin();
	while (!GameTextures.empty())
	{
		auto tempitr = itr;
		temp = (*itr).second;
		itr++;
		delete temp;
		GameTextures.erase((*tempitr).first);
	}
	delete ptrInstance;
	ptrInstance = nullptr;
}

bool TextureManager::doesKeyExist(const std::string MapKey)
{
	return(GameTextures.count(MapKey) != 0);
}
