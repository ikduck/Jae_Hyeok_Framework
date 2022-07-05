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


// ObjectPool�� ���� �Ѿ� ��ȯ��Ŵ
// �Ѿ��� ���� ����ϴ� ������ ObjectPool�� ����ؾ� ����ȭ�� �ߵ� (����,fps)
// �Ѿ��� ���� ���� ������ ObjectPool�� ����� ��ȿ������ (rpg)