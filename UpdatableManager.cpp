#include "UpdatableManager.h"
#include "Updatable.h"
#include "UpdatableAttorney.h"

UpdatableManager::~UpdatableManager()
{
	DebugMsg::out("UpdatableManager class destructor called\n");
	//for (StorageList::const_iterator it = storageList.begin(); it != storageList.end(); it++)
	//{
	//	delete *it;
	//}
}

void UpdatableManager::ProcessElements()
{
	for (StorageList::const_iterator it = storageList.begin(); it != storageList.end(); it++)
	{
		UpdatableAttorney::GameLoop::Update(*it);
		//(*it)->Update();
	}
}

void UpdatableManager::Register(Updatable * up, UpdatableListRef & ref)
{
	ref = storageList.insert(storageList.end(), up);
}

void UpdatableManager::Degregister(Updatable * up, UpdatableListRef& ref)
{
	(void*)up;
	storageList.erase(ref);
	//TODO
}
