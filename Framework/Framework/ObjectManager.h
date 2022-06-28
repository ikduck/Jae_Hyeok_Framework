#pragma once
#include "Headers.h"

/*
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
			Instance = new ObjectManager;

		return Instance;
	}
	
	void AddObject(Object* _Object);
	list<Object*>* GetObjectList(string _strKey);
	void Update();
	void Render();

	~ObjectManager();
};
*/

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
			Instance = new ObjectManager;

		return Instance;
	}

	void AddObject(Object* Object);
	list<Object*>* GetObjectList(string _Key);
	void Update();
	void Render();

	~ObjectManager();

};