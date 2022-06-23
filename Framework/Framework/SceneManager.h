#pragma once
#include "Headers.h"

class SceneManager // �����ڷ� �����
{
private:

	static SceneManager* Instance;
public:
	static SceneManager* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new SceneManager;
		}
		return Instance;
	}
private:
	SCENEID SceneState;
public:
	// 1. ���� ���� ȣ���������
	// 2. ���� �ٲ�ٴ� ���� ������ �� ������ �Ѿ�� ������
	// �ζ������� ���� �ʿ䰡����
	void SetScene(SCENEID _SceneState);
private:
	SceneManager();

public:
	~SceneManager();

};

// ���� ���鶧 �ΰ� + ���ӽ��۹�ư + �ɼ� ���� ����� ���� �ΰ������� ���⶧���� SceneManger�� Scene������ ö���� ������