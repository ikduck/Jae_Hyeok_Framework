#include "MainUpdate.h"
#include "SceneManager.h"
#include "InputManager.h"
// cpp�� ����� �ִ� ������ �ʿ����� ������� ����Ҽ��־

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
	// �����Ҵ��� ���� �ʾƼ� ���� ���� ����
}

// �ڵ� 
// (���콺 ��ǥ = ������ ��ǥ)
// �ƽ�Ű ��Ʈ