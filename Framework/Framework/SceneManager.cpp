#include "SceneManager.h"
// #include "Scene.h" // 추상클래스여서 가져와도 의미가 없음
// 아래 세가지를 가져와서 다양하게 사용할것임(다형성)
#include "Logo.h"
#include "Menu.h"
#include "Stage.h"

SceneManager* SceneManager::Instance = nullptr;

SceneManager::SceneManager() : SceneState(nullptr) { }
SceneManager::~SceneManager() { Release(); }

void SceneManager::SetScene(SCENEID _SceneState)
{
	// 값을 이미 가지고 있을때 초기화 해줌
	if (SceneState != nullptr)
	{
		delete SceneState;
		SceneState = nullptr;
	}

	switch (_SceneState)
	{
	case LOGO:
		SceneState = new Logo;
		break;

	case MENU:
		SceneState = new Menu;
		break;

	case STAGE:
		SceneState = new Stage;
		break;

	case EXIT:
		exit(NULL);
		break;

	}
	// 공통적으로 Logo , Menu 를 받던간에 초기화 해줘야해서 뺌
	SceneState->Initialize();
}

void SceneManager::Update()
{
	//  받아온 값을 update 해줌
	SceneState->Update();
}

void SceneManager::Render()
{
	// 받아온 값을 Render 해줌
	SceneState->Render();
}

void SceneManager::Release()
{
	delete SceneState;
	SceneState = nullptr;
}
