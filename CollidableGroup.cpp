//#include "CollidableGroup.h"
//
//template<typename C>
//CollidableGroup<typename C>* CollidableGroup::ptrInstance = nullptr;
//
//
//void CollidableGroup<C>::Register(C * p)
//{
//	this->ColCollection.push_back(p);
//}
//
//
//void CollidableGroup<C>::Deregister(C * p)
//{
//	this->ColCollection.erase(p);
//}
//
//
//const CollidableCollection& CollidableGroup<C>::GetColliderCollection()
//{
//	return this->ColCollection&;
//}
//
//
//void CollidableGroup<C>::privDelete()
//{
//	delete ptrInstance;
//	ptrInstance = nullptr;
//}
