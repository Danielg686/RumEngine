#include "ImageManager.h"
#include "TextureManager.h"

ImageManager* ImageManager::ptrInstance = nullptr;

ImageManager::~ImageManager()
{
}

void ImageManager::privLoad(const std::string MapKey, const std::string TextureKey)
{
	Texture* temp = TextureManager::Get(TextureKey);
	this->privLoad(MapKey, TextureKey, new Rect(0.0f, 0.0f,(float)temp->getWidth(),(float)temp->getHeight()));
}

void ImageManager::privLoad(const std::string MapKey, const std::string TextureKey, Rect* rectSize)
{
	if (!doesKeyExist(MapKey))
	{
		Image *pImage = new Image(TextureManager::Get(TextureKey), rectSize);
		GameImages[MapKey] = pImage;
	}
}

Image * ImageManager::privGet(const std::string MapKey)
{
	if (doesKeyExist(MapKey))
	{
		return GameImages[MapKey];
	}
	return nullptr;
}

void ImageManager::privDelete()
{
	Image* temp;
	auto itr = GameImages.begin();
	while (!GameImages.empty())
	{
		auto tempitr = itr;
		temp = (*itr).second;
		itr++;
		delete temp;
		GameImages.erase((*tempitr).first);
	}
	delete ptrInstance;
	ptrInstance = nullptr;
}

bool ImageManager::doesKeyExist(const std::string MapKey)
{
	return(GameImages.count(MapKey) != 0);
}
