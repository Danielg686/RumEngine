//ShaderManagerAttorney
//Daniel Goodrum, Feb 2018

#ifndef SHADERMANAGERATTORNEY_H
#define SHADERMANAGERATTORNEY_H

#include "ShaderManager.h"

class ShaderManagerAttorney
{
	friend class RumEngine;

private:
	///			\brief Passthrough for Engine to delete Shaders.
	static void Delete() { ShaderManager::Delete(); }
};

#endif // !SHADERMANAGERATTORNEY_H
