#include "MainUpdate.h"
#include "SceneManager.h"
#include "InputManager.h"
// cpp에 헤더를 넣는 이유는 필오없는 헤더까지 사용할수있어서

MainUpdate::MainUpdate()  { }
MainUpdate::~MainUpdate() { Release(); }

void MainUpdate::Initialize()
{
	// SceneState = LOGO;
	SceneManager::GetInstance()->SetScene(LOGO);
}

void MainUpdate::Update()
{
	/*
	++Count;
	
	if (Count > 10)
	{
		Count = 0;
		SceneState++;
	
		SceneManager::GetInstance()->SetScene(SceneState);
	}
	*/

	InputManager::GetInstance()->Inputkey();
	SceneManager::GetInstance()->Update();
}

void MainUpdate::Render()
{
	SceneManager::GetInstance()->Render();
}

void MainUpdate::Release()
{
	// 동적할당을 하지 않아서 지울 것이 없음
}

// 핸들 
// (마우스 좌표 = 윈도우 좌표)
// 아스키 아트