#pragma once
#include "Headers.h"

class Object;
class ObjectManager
{
private:
	static ObjectManager* Instance;
	ObjectManager();
	map<string, list<Object*>> ObjectList;  //list 선언
public:
	static ObjectManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new ObjectManager;

		return Instance;
	}

	void AddObject(Object* Object);
	list<Object*>* GetObjectList(string _Key);
	void Update();
	void Render();

	~ObjectManager();
};
// 1번 홀수 2문제 앞장