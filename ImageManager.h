//ImageManager
//Daniel Goodrum, Mar 2017

#ifndef IMAGEMANAGER_H
#define IMAGEMANAGER_H

#include "RumEngine.h"
#include "AzulCore.h"
#include <map>
#include <string>


class ImageManager
{
	friend class ImageManagerAttorney;
public:
	/// \brief Loads Images to be managed by the system accessable during runtime. 
	/// MapKey is used to reference the Image. TextureKey is a texture loaded into the Texture Manager
	static void Load(const std::string MapKey, const std::string TextureKey) { Instance().privLoad(MapKey, TextureKey); }

	/// \brief Same as other Load function with a user defined Rect 
	/// Rect indicates the x/y values of the upper left anchor point of the image in pxles, and width/height is the pixle width/height
	static void Load(const std::string MapKey, const std::string TextureKey, Rect* rectSize) { Instance().privLoad(MapKey, TextureKey, rectSize); }
	
	/// \brief Returns a pointer to an Image that was loaded into the manager from LoadAllResources.
	static Image* Get(const std::string MapKey) { return Instance().privGet(MapKey); }

private:
	static ImageManager* ptrInstance;

	ImageManager() = default;

	ImageManager(const ImageManager&) = delete;
	ImageManager &operator = (const ImageManager&) = delete;
	~ImageManager();

	static ImageManager& Instance()
	{
		if (!ptrInstance)
		{
			ptrInstance = new ImageManager;
		}
		return *ptrInstance;
	}

	std::map<std::string, Image*> GameImages;

	void privLoad(const std::string MapKey, const std::string TextureKey);
	void privLoad(const std::string MapKey, const std::string TextureKey, Rect* rectSize);

	Image* privGet(const std::string MapKey);

	static void Delete() { Instance().privDelete(); }
	void privDelete();



	bool doesKeyExist(const std::string MapKey);
	
};



#endif // !IMAGEMANAGER_H
