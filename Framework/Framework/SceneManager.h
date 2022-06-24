#pragma once
#include "Headers.h"
// #include "Scene.h" 를 가져오면 원하지않는 기능도 써야할수도있어서 효율이 떨어짐

// 정의 없이 클래스를 만듦(트릭) , 허수 , ->로 함수를 못씀 ,동적할당도 안됨 
class Scene;
class SceneManager
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
	// 있는 척만하고 안쓸거임
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
