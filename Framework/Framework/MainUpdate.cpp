#include "MainUpdate.h"
#include "SceneManager.h"
#include "InputManager.h"
// cpp�� ����� �ִ� ������ �ʿ����� ������� ����Ҽ��־

MainUpdate::MainUpdate() : Count(0) { }
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
	/*
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_UP)
		cout << "KEY_UP" << endl;

	if (dwKey & KEY_DOWN)
		cout << "KEY_DOWN" << endl;

	if (dwKey & KEY_LEFT)
		cout << "KEY_LEFT" << endl;

	if (dwKey & KEY_RIGHT)
		cout << "KEY_RIGHT" << endl;

	if (dwKey & KEY_SPACE)
		cout << "KEY_SPACE" << endl;

	//	if (dwKey & KEY_ENTER)
		// cout << "KEY_ENTER" << endl;

	if (dwKey & KEY_ENTER)
	{
			SceneManager::GetInstance()->SetScene(LOGO);
	}

	if (dwKey & KEY_LCTRL)
		cout << "KEY_LCTRL" << endl;

	// if (dwKey & KEY_RCTRL)
	// 	cout << "KEY_RCTRL" << endl;

	if (dwKey & KEY_LALT)
		cout << "KEY_LALT" << endl;

	// if (dwKey & KEY_RALT)
	// 	cout << "KEY_RALT" << endl;
	*/

	
}

void MainUpdate::Render()
{
	SceneManager::GetInstance()->Render();
}

void MainUpdate::Release()
{
}


// �ڵ� 
// (���콺 ��ǥ = ������ ��ǥ)
// �ƽ�Ű ��Ʈ