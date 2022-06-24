#include "InputManager.h"

// static���� ����Ҷ��� �������� ������� 
InputManager* InputManager::Instance = nullptr;

InputManager::InputManager() : Key(0) { }
InputManager::~InputManager() { }

void InputManager::Inputkey()
{
	// GetAsyncKeyState() : Ű�Է��� �޾ƿ��� �Լ�
	// Virtual Key _ Up = VK_UP
	if (GetAsyncKeyState(VK_UP))
		cout << "KEY_UP" << endl;

	if (GetAsyncKeyState(VK_DOWN))
		cout << "VK_DOWN" << endl;

	if (GetAsyncKeyState(VK_LEFT))
		cout << "VK_LEFT" << endl;

	if (GetAsyncKeyState(VK_RIGHT))
		cout << "VK_RIGHT" << endl;

	if (GetAsyncKeyState(VK_SPACE))
		cout << "VK_SPACE" << endl;

	if (GetAsyncKeyState(VK_RETURN))
		cout << "VK_RETURN" << endl;

	if (GetAsyncKeyState(VK_CONTROL))
		cout << "VK_CONTROL" << endl;

	if (GetAsyncKeyState(VK_MENU))
		cout << "VK_MENU" << endl;

}
