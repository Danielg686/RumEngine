#include "DrawableManager.h"
#include "Drawable.h"
#include "DrawableAttorney.h"

DrawableManager::~DrawableManager()
{
	DebugMsg::out("DrawableManager class destructor called\n");
	//for (StorageList::const_iterator it = storageList.begin(); it != storageList.end(); it++)
	//{
	//	delete *it;
	//}
}

void DrawableManager::ProcessElements()
{
	for (StorageList::const_iterator it = storageList.begin(); it != storageList.end(); it++)
	{
		DrawableAttorney::GameLoop::Draw(*it);
//		(*it)->Draw();
	}
}

void DrawableManager::Register(Drawable * dr, DrawableListRef& ref)
{
	ref = storageList.insert(storageList.end(), dr);
}

void DrawableManager::Deregister(Drawable * dr, DrawableListRef& ref)
{
	UNREFERENCED_PARAMETER(dr);
	storageList.erase(ref);
}
