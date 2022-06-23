#pragma once
#include "Headers.h"

class SceneManager // 관리자로 사용함
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
	// 1. 씬은 많이 호출되지않음
	// 2. 씬이 바뀐다는 것은 로직이 다 끝난후 넘어가기 때문에
	// 인라인으로 만들 필요가없음
	void SetScene(SCENEID _SceneState);
private:
	SceneManager();

public:
	~SceneManager();

};

// 게임 만들때 로고 + 게임시작버튼 + 옵션 등을 만들고 나서 인게임으로 들어가기때문에 SceneManger로 Scene관리를 철저히 해주자