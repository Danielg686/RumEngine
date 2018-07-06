//TextureManagerAttorney
//Daniel Goodrum, Feb 2018


#ifndef TEXTUREMANAGERATTORNEY_H
#define TEXTUREMANAGERATTORNEY_H

#include "TextureManager.h"

class TextureManagerAttorney
{
	friend class RumEngine;
private:

	/// \brief Passthrough for Engine to delete Textures.
	static void Delete() { TextureManager::Delete(); }
};




#endif // !TEXTUREMANAGERATTORNEY_H
