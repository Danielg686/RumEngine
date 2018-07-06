//TerrainManagerAttorney
//Daniel Goodrum May 2018

#ifndef _TerrainManagerAttorney
#define _TerrainManagerAttorney

#include "TerrainManager.h"

class TerrainManagerAttorney
{
	friend class RumEngine;

private:

	static void Delete() { TerrainManager::Delete(); }
};

#endif // !_TerrainManagerAttorney
