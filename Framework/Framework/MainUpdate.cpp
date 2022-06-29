#include "MainUpdate.h"
#include "SceneManager.h"
#include "InputManager.h"
// cpp에 헤더를 넣는 이유는 필오없는 헤더까지 사용할수있어서

MainUpdate::MainUpdate()  { }
MainUpdate::~MainUpdate() { Release(); }

void MainUpdate::Initialize()
{

	SceneManager::GetInstance()->SetScene(LOGO);
}

void MainUpdate::Update()
{
	InputManager::GetInstance()->Inputkey();
	SceneManager::GetInstance()->Update();
}

void MainUpdate::Render()
{
	SceneManager::GetInstance()->Render();
}

void MainUpdate::Release()
{
}

