#pragma once
#include "Headers.h"

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
	//SCENEID SceneState;
public:
	void SetScene(int _SceneState);  // SCENEID _SceneState
private:
	SceneManager();

public:
	~SceneManager();

};
