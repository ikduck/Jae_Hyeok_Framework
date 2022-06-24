#include "Player.h"
#include "InputManager.h"

Player::Player()
		: Horizontal(0), Vertical(0) { }
Player::~Player() { }

void Player::Initialize()
{
	Horizontal;
	Vertical;
}

void Player::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();
	
	if (dwKey & KEY_UP)
		Vertical += 1;
	
	if (dwKey & KEY_DOWN)
		Vertical -= 1;
	
	if (dwKey & KEY_LEFT)
		Horizontal -= 1;

	if (dwKey & KEY_RIGHT)
		Horizontal += 1;

	/*
	if (dwKey & KEY_SPACE)
		cout << "KEY_SPACE" << endl;
	
	if (dwKey & KEY_LCTRL)
		cout << "KEY_LCTRL" << endl;
	
	if (dwKey & KEY_LALT)
		cout << "KEY_LALT" << endl;
	*/
}

void Player::Render()
{
	cout << "X : " << Horizontal << endl;
	cout << "Y : " << Vertical << endl;
}

void Player::Release()
{
}

// 게임엔진의 기능을 구현하는 과정 c++