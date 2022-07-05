#include "ObjectManager.h"
#include "CollisionManager.h"
#include "Object.h"
#include "ObjectPool.h"

ObjectManager* ObjectManager::Instance = nullptr;
ObjectManager::ObjectManager() 
{
	EnableList = ObjectPool::GetEnableList();
}
ObjectManager::~ObjectManager() { }

void ObjectManager::AddObject(Object* _Object)
{
	// ObjectList
	map<string, list<Object*>>::iterator iter = EnableList->find(_Object->GetKey());

	if (iter == EnableList->end())
	{
		list<Object*> TempList;
		TempList.push_back(_Object);
		// ObjectPool::GetInstance()->AddObject(_Object->GetKey(), TempList);
		EnableList->insert(make_pair(_Object->GetKey(), TempList));
		// ObjectPool::GetInstance()->AddObject(_Object);
	}
	else
		iter->second.push_back(_Object);
		// ObjectPool::GetInstance()->AddObject(_Object);
	

}

list<Object*>* ObjectManager::GetObjectList(string _strKey)
{
	map<string, list<Object*>>::iterator iter = EnableList->find(_strKey);

	if (iter == EnableList->end())
		return nullptr;

	return  &iter->second;
	
}

void ObjectManager::Update()
{
	ObjectPool::GetInstance()->Update();
}

void ObjectManager::Render()
{
	for (map<string, list<Object*>>::iterator iter = EnableList->begin();
		iter != EnableList->end(); ++iter)
	{
		for (list<Object*>::iterator iter2 = iter->second.begin();
			iter2 != iter->second.end(); ++iter2)
			(*iter2)->Render();
	}
}
