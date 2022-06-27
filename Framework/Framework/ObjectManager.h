#pragma once
#include "Headers.h"

class Object;
class ObjectManager
{
private:
	static ObjectManager* Instance;
	ObjectManager();
	map<string, list<Object*>> ObjectList;
public:
	static ObjectManager* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new ObjectManager;
		}
		return Instance;
	}

	void AddObject(Object* _Object);
	list<Object*>* GetObjectList(string  _strKey);
	void Render();

	~ObjectManager();
};


/*
#include "Headers.h"

class ObjectManager
{
private: 
	static ObjectManager Instance;
	ObjectManager();
	map<string, list<Object*>> ObjectList;
public:
	static ObjectManager

};
*/