#include "ObjectPool.h"
#include "Object.h"
#include "CursorManager.h"
#include "CollisionManager.h"
ObjectPool* ObjectPool::Instance = nullptr;
map<string, list<Object*>> ObjectPool::EnableList;
ObjectPool::ObjectPool() { }
ObjectPool::~ObjectPool()  { }

/*
void ObjectPool::AddObject(string _Key, list<Object*> _List)
{
	EnableList.insert(make_pair(_Key, _List));
}

void ObjectPool::AddObject(Object* _Object)
{
	map<string, list<Object*>>::iterator iter = EnableList.find(_Object->GetKey());

	iter->second.push_back(_Object);
}
*/ 

void ObjectPool::Update()
{
	for (map<string, list<Object*>>::iterator iter = EnableList.begin();
		iter != EnableList.end(); ++iter)
	{
		for (list<Object*>::iterator iter2 = iter->second.begin();
			iter2 != iter->second.end(); )
		{
			int result = (*iter2)->Update();

			switch (result)
			{
			case BUFFER_OVER:
			{
				map<string, list<Object*>>::iterator Disableiter = DisableList.find((*iter2)->GetKey());

				if (iter == DisableList.end())
				{
					list<Object*> TempList;
					TempList.push_back((*iter2));
					DisableList.insert(make_pair((*iter2)->GetKey(), TempList));
				}
				else
					Disableiter->second.push_back((*iter2));
					
				(*iter).second.erase(iter2);
			}
			case 2:
				CursorManager::GetInstance()->WriteBuffer(50.0f, 1.0f, (char*)"�浹�Դϴ�");
				
				break;

			default:
				++iter2;
			}
		}
	}
}