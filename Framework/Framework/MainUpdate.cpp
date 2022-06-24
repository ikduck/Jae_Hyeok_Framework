#include "MainUpdate.h"
#include "SceneManager.h"
#include "InputManager.h"
// cpp에 헤더를 넣는 이유는 필오없는 헤더까지 사용할수있어서

MainUpdate::MainUpdate() : Count(0) { }
MainUpdate::~MainUpdate() { Release(); }

void MainUpdate::Initialize()
{
	// SceneState = LOGO;
	SceneManager::GetInstance()->SetScene(SceneState);
}

void MainUpdate::Update()
{
	InputManager::GetInstance()->Inputkey();

	/*
	++Count;

	if (Count > 10)
	{
		Count = 0;
		SceneState++;

		SceneManager::GetInstance()->SetScene(SceneState);
	}
	*/

}

void MainUpdate::Render()
{
}

void MainUpdate::Release()
{
}


