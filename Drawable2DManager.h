//Drawable2DManager
//Daniel Goodrum, Mar 2018

#ifndef DRAWABLE2DMANAGER_H
#define DRAWABLE2DMANAGER_H

#include "AzulCore.h"
#include <list>

class Drawable2D;

class Drawable2DManager
{
private:

	using StorageList = std::list<Drawable2D*>;
	StorageList storageList;

public:

	using Drawable2DListRef = StorageList::iterator;

	Drawable2DManager() = default;
	~Drawable2DManager();
	Drawable2DManager(const Drawable2DManager&) = delete;
	Drawable2DManager& operator = (const Drawable2DManager&) = delete;

	void ProcessElements();

	void Register(Drawable2D* dr, Drawable2DListRef& ref);

	void Deregister(Drawable2D* dr, Drawable2DListRef& ref);


};

#endif // !DRAWABLE2DMANAGER_H
