#include "Player.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "Bridge.h"
#include "PlayerChar1.h"
#include "ObjectManager.h"

Player::Player() { }
Player::Player(Transform _TransInfo) : Object(_TransInfo) { }
Player::~Player() { Release(); }

Object* Player::Initialize(string _Key)
{
	strKey = _Key;

	TransInfo.Position = Vector3(20.0f, 15.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(6.0f, 6.0f);
	TransInfo.Direction = Vector3(0.0f, 0.0f);

	return this;
}

int Player::Update()
{
	if (pBridge)
		pBridge->Update(TransInfo);

	return 0;
}

void Player::Render()
{
	if (pBridge)
		pBridge->Render();
}

void Player::Release()
{
	::Safe_Delete(pBridge);
}




// 피타고라스 + 외적 내적
// 
// 이때까지는 Bullet에 속성없이 그냥 키 값으로만 넘겻는데
// CreateBullet에서 속성을 주고 넘겨줌