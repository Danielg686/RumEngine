//DrawableManager
//Daniel Goodrum Jan 2018

#ifndef DRAWABLEMANAGER_H
#define DRAWABLEMANAGER_H

#include "AzulCore.h"
#include <list>

class Drawable;

class DrawableManager
{

private:
	using StorageList = std::list<Drawable*>;
	StorageList storageList;

public:
	using DrawableListRef = StorageList::iterator;

	DrawableManager() = default;
	~DrawableManager();
	DrawableManager(const DrawableManager&) = delete;
	DrawableManager& operator = (const DrawableManager&) = delete;

	void ProcessElements();
	
	

	void Register(Drawable* dr, DrawableListRef& ref);
	void Deregister(Drawable* dr, DrawableListRef& ref);




};



#endif // 
