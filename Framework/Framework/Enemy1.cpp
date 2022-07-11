#include "Enemy1.h"
#include "NormalBullet.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "Object.h"

Enemy1::Enemy1() { }
Enemy1::~Enemy1() { }

void Enemy1::Initialize()
{
	// ** Bullet의 
	// 데미지.
	Speed = 1.0f;
	Color = 15;
}

int Enemy1::Update(Transform& TransInfo)
{

	if (TransInfo.Position.x <= 0)
		return BUFFER_OVER;

	return 0;
}

void Enemy1::Render()
{
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition().x,
		pObject->GetPosition().y,
		(char*)"Enemy1", Color);
}

void Enemy1::Release()
{

}

