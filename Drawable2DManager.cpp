#include "Drawable2DManager.h"
#include "Drawable2D.h"
#include "DrawableAttorney.h"

Drawable2DManager::~Drawable2DManager()
{
}

void Drawable2DManager::ProcessElements()
{
//	DebugMsg::out("Size of Drawable2D list is %d\n", storageList.size());
	for (StorageList::const_iterator itr = storageList.begin(); itr != storageList.end(); itr++)
	{
		DrawableAttorney::GameLoop2D::Draw2D(*itr);
	}
}

void Drawable2DManager::Register(Drawable2D * dr, Drawable2DListRef & ref)
{
	ref = storageList.insert(storageList.end(), dr);
}

void Drawable2DManager::Deregister(Drawable2D * dr, Drawable2DListRef & ref)
{
	UNREFERENCED_PARAMETER(dr);
	storageList.erase(ref);
}

