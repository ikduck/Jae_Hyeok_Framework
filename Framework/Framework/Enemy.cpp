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
 	TransInfo.Scale = Vector3((float)strlen(Buffer[0]),(float)MAX_SIZE);
	Color = 12;
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
	for(int  i = 0 ; i < 2; ++i)
	{
	CursorManager::GetInstance()->WriteBuffer(
		TransInfo.Position.x,
		TransInfo.Position.y+ i ,
		Buffer[i], Color);
	}
}

void Enemy::Release()
{
}

// 삭제방법은 여러가지가 있음 - stage에서 지울수도있고 