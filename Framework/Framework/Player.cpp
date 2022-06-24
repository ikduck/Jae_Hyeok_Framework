#include "Player.h"

Player::Player() { }

Player::~Player() { }

void Player::Initialize()
{
}

void Player::Update()
{
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

void Player::Render()
{
	Message("Player");
}

void Player::Release()
{
}

