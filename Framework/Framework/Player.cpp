#include "Player.h"
#include "InputManager.h"
#include "CursorManager.h"
#include "Bullet.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"

Player::Player() { }
Player::Player(Transform _TransInfo) : Object(_TransInfo) { }
Player::~Player() { }

Object* Player::Initialize(string _Key)
{
	strKey = _Key;

	//Buffer[0] = (char*)"──";
	Buffer[0] = (char*)"오";
	Buffer[1] = (char*)"ㅅ";
	
	TransInfo.Position = Vector3(20.0f, 15.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(2.0f, 2.0f);

	Color = 15;

	return this;
}

int Player::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_UP)
		TransInfo.Position.y -= 1;

	if (dwKey & KEY_DOWN)
		TransInfo.Position.y += 1;

	if (dwKey & KEY_LEFT)
		TransInfo.Position.x -= 1;

	if (dwKey & KEY_RIGHT)
		TransInfo.Position.x += 1;
	
	if (dwKey & KEY_SPACE)
	{
		// ObjectManager::GetInstance()->AddObject(ObjectFactory<Bullet>::CreateObject(TransInfo.Position));
		ObjectManager::GetInstance()->AddObject("Bullet");
		ObjectManager::GetInstance()->GetObjectList("Bullet")->back()->SetPosition(TransInfo.Position);
	}

	return 0;
}

void Player::Render()
{
	for (int i = 0; i < 2; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(
			TransInfo.Position.x,
			TransInfo.Position.y + i,
			Buffer[i], Color);
	}
}

void Player::Release()
{

}

// 피타고라스 + 외적 내적
// 