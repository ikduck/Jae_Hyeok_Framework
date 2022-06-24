#pragma once
#include "Headers.h"
// #include "Scene.h" �� �������� �������ʴ� ��ɵ� ����Ҽ����־ ȿ���� ������

// ���� ���� Ŭ������ ����(Ʈ��) , ��� , ->�� �Լ��� ���� ,�����Ҵ絵 �ȵ� 
class Scene;
class SceneManager
{
private:

	static SceneManager* Instance;   // ���� ���� �� �� �ʱ�ȭ ������� go cpp
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
	// �ִ� ô���ϰ� �Ⱦ����� �ʱ�ȭ�ؾ���
	Scene* SceneState; 
public:
	void SetScene(SCENEID _SceneState);  // SCENEID _SceneState
	void Update();
	void Render();
	void Release();
private:
	SceneManager();

public:
	~SceneManager();

};
