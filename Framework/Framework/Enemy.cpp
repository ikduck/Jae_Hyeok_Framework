#include "Enemy.h"
#include "CursorManager.h"

Enemy::Enemy() { }
Enemy::Enemy(Transform _TransInfo) : Object(_TransInfo) { }
Enemy::~Enemy() { }

void Enemy::Initialize()
{
	strKey = "Enemy";

	Buffer[0] = (char*)"호";
	Buffer[1] = (char*)"ㅅ";

	TransInfo.Position = Vector3(0.0f, 15.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f); 
 	TransInfo.Scale = Vector3(2.0f, 2.0f);
}


int Enemy::Update()
{
	// TransInfo.Position.x -= 2;
	
	 if (TransInfo.Position.x <= 0)
	 	return BUFFER_OVER;

	return 0;
}

void Enemy::Render()
{
	CursorManager::GetInstance()->WriteBuffer(
		TransInfo.Position, (char*)"Enemy", 10);
}

void Enemy::Release()
{
}

// 삭제방법은 여러가지가 있음 - stage에서 지울수도있고 