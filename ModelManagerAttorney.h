//ModelManagerAttorney
//Daniel Goodrum, Jan 2018

#ifndef MODELMANAGERATTORNEY_H
#define MODELMANAGERATTORNEY_H


#include "ModelManager.h"

class ModelManagerAttorney
{
	friend class RumEngine;

private:

	///		\brief Passthrough for Engine to delete Model Manager.
	static void Delete() { ModelManager::Delete();  }
};

#endif // !MODELMANAGERATTORNEY_H

