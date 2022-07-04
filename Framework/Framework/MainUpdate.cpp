#include "MainUpdate.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "CursorManager.h"
// cpp�� ����� �ִ� ������ �ʿ����� ������� ����Ҽ��־

MainUpdate::MainUpdate()  { }
MainUpdate::~MainUpdate() { Release(); }

void MainUpdate::Initialize()
{
	CursorManager::GetInstance()->CreateBuffer(ConsoleWidthSize, ConsoleHeightSize);
	
	SceneManager::GetInstance()->SetScene(LOGO);
}

void MainUpdate::Update()
{
	InputManager::GetInstance()->Inputkey();
	SceneManager::GetInstance()->Update();

	CursorManager::GetInstance()->FlippingBuffer();		// ��°� ������ �Լ��ϳ����� ���
}

void MainUpdate::Render()
{
	SceneManager::GetInstance()->Render();
}

void MainUpdate::Release()
{
}

