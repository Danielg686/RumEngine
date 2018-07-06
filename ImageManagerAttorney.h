//ImageManagerAttorney
//Daniel Goodrum, Mar 2018

#ifndef IMAGEMANAGERATTORNEY_H
#define IMAGEMANAGERATTORNEY_H

#include "ImageManager.h"

class ImageManagerAttorney
{
	friend class RumEngine;
private:
	static void Delete() { ImageManager::Delete(); }
};



#endif // !IMAGEMANAGERATTORNEY_H
