//Updatable Manager
//Daniel Goodrum Jan 2018

#ifndef UPDATABLEMANAGER_H
#define UPDATABLEMANAGER_H

#include "AzulCore.h"
#include <list>

class Updatable;

class UpdatableManager
{

private:
	using StorageList = std::list<Updatable*>;
	StorageList storageList;

public:
	using UpdatableListRef = StorageList::iterator;

	UpdatableManager() = default;
	~UpdatableManager();
	UpdatableManager(const UpdatableManager&) = delete;
	UpdatableManager& operator = (const UpdatableManager&) = delete;

	void ProcessElements();

	void Register(Updatable* up, UpdatableListRef& ref);
	void Degregister(Updatable* up, UpdatableListRef& ref);






};



#endif // !UPDATABLEMANAGER_H
