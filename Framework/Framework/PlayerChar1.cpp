#include "PlayerChar1.h"
#include "InputManager.h"
#include "CursorManager.h"
#include "Bridge.h"
#include "NormalBullet.h"
#include "RedBullet.h"
#include "Object.h"
#include "ObjectManager.h"

PlayerChar1::PlayerChar1() { }
PlayerChar1::~PlayerChar1() { }

void PlayerChar1::Initialize()
{
    Buffer[0] = (char*)"¦«¦«¦«";
    Buffer[1] = (char*)"¦§¦¡¦©";

    Speed = 1.0f;
    Color = 15;
}

int PlayerChar1::Update(Transform& TransInfo)
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
		Bridge* pBridge = new NormalBullet;
		ObjectManager::GetInstance()->AddObject("Bullet", pBridge);
		ObjectManager::GetInstance()->GetObjectList("Bullet")->back()->SetPosition(TransInfo.Position);
	}

    return 0;
}

void PlayerChar1::Render()
{
	for (int i = 0; i < 2; ++i)
	{
		/*
		CursorManager::GetInstance()->WriteBuffer(
			TransInfo.Position.x,
			TransInfo.Position.y + i,
			Buffer[i], 15);
			*/
		CursorManager::GetInstance()->WriteBuffer(
			pObject->GetPosition().x,
			pObject->GetPosition().y + i,
			Buffer[i], Color);
	}
}

void PlayerChar1::Release()
{
}

