#include "InputManager.h"

// static으로 사용할때는 전역선언 해줘야함 
InputManager* InputManager::Instance = nullptr;

InputManager::InputManager() : Key(0) { }
InputManager::~InputManager() { }

void InputManager::Inputkey()
{
	Key = 0;

	if ((GetAsyncKeyState(VK_UP)) || GetAsyncKeyState('W') )
		Key |= KEY_UP;

	if ((GetAsyncKeyState(VK_DOWN)) || GetAsyncKeyState('S'))
		Key |= KEY_DOWN;

	if ((GetAsyncKeyState(VK_LEFT)) || GetAsyncKeyState('A'))
		Key |= KEY_LEFT;

	if ((GetAsyncKeyState(VK_RIGHT)) || GetAsyncKeyState('D'))
		Key |= KEY_RIGHT;

	if (GetAsyncKeyState(VK_SPACE))
		Key |= KEY_SPACE;

	if (GetAsyncKeyState(VK_RETURN))
		Key |= KEY_ENTER;

	if (GetAsyncKeyState(VK_LCONTROL))
		Key |= KEY_LCTRL;

	// if (GetAsyncKeyState(VK_RCONTROL))
	// 	Key |= KEY_RCTRL;

	if (GetAsyncKeyState(VK_LMENU))
		Key |= KEY_LALT;

	// if (GetAsyncKeyState(VK_RMENU))
	// 	Key |= KEY_RALT;

	// 미국식 키보드 와 한국식 키보드의 입력이 달라서 RIGHT_CONTRL ,ALT가 안됨

	// GetAsyncKeyState() : 키입력을 받아오는 함수
	// Virtual Key _ Up = VK_UP
	/*
	if (GetAsyncKeyState(VK_UP))
		cout << "KEY_UP" << endl;

	if (GetAsyncKeyState(VK_DOWN))
		cout << "KEY_DOWN" << endl;

	if (GetAsyncKeyState(VK_LEFT))
		cout << "KEY_LEFT" << endl;

	if (GetAsyncKeyState(VK_RIGHT))
		cout << "KEY_RIGHT" << endl;

	if (GetAsyncKeyState(VK_SPACE))
		cout << "KEY_SPACE" << endl;

	if (GetAsyncKeyState(VK_RETURN))
		cout << "KEY_RETURN" << endl;

	if (GetAsyncKeyState(VK_CONTROL))
		cout << "KEY_CONTROL" << endl;

	if (GetAsyncKeyState(VK_MENU))
		cout << "KEY_MENU" << endl;
		*/
}
