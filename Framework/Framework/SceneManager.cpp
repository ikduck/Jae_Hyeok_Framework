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
		::Safe_Delete(SceneState);

	switch (_SceneState)
	{
	case SCENEID::LOGO:
		SceneState = new Logo;
		break;

	case SCENEID::MENU:
		SceneState = new Menu;
		break;

	case SCENEID::STAGE:
		SceneState = new Stage;
		break;

	case SCENEID::EXIT:
		exit(NULL);
		break;

	}
	SceneState->Initialize();
}

void SceneManager::Update()
{
	SceneState->Update();
}

void SceneManager::Render()
{
	SceneState->Render();
}

void SceneManager::Release()
{
	::Safe_Delete(SceneState);
}
