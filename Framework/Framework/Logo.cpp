#include "Logo.h"
#include "SceneManager.h"
#include "InputManager.h"

Logo::Logo() { }

Logo::~Logo() { }


void Logo::Initialize()
{
}

void Logo::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_ENTER)
	{
		SceneManager::GetInstance()->SetScene(MENU);
	}
}

void Logo::Render()
{
	cout << "LOGO" << endl;

}

void Logo::Release()
{
}

