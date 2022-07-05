#pragma once
#include "Headers.h"

class Object;
class ObjectPool
{
private:
	static ObjectPool* Instance;
	ObjectPool();
	static map<string, list<Object*>> EnableList;
	map<string, list<Object*>> DisableList;

public:
	static ObjectPool* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new ObjectPool;

		return Instance;
	}
		
	// void AddObject(string _Key, list<Object*> _List);
	// void AddObject(Object* _Object);
	static map<string, list<Object*>>* GetEnableList() { return &EnableList; }
	void Update();

	~ObjectPool();
};


// ObjectPool을 만들어서 총알 순환시킴
// 총알을 많이 사용하는 게임은 ObjectPool을 사용해야 최적화가 잘됨 (슈팅,fps)
// 총알이 많지 않은 게임은 ObjectPool을 만들면 비효율적임 (rpg)