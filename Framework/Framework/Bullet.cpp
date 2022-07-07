#include "Bullet.h"
#include "CursorManager.h"
#include "MathManager.h"
Bullet::Bullet() { }
Bullet::Bullet(Transform _TransInfo) : Object(_TransInfo) { }
Bullet::~Bullet() { }

void Bullet::Initialize()
{
	strKey = "Bullet"; // 포인터아님 2바이트짜리 특수문자임

	Buffer[0] = (char*)"타";
	Buffer[1] = (char*)"ㅇ";

	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3((float)strlen(Buffer[0]), (float)MAX_SIZE);
	TransInfo.Direction = Vector3(0.0f, 0.0f);

	Color = 15;
}

int Bullet::Update()
{	
	TransInfo.Direction = MathManager::GetDirection(
		TransInfo.Position, Vector3(60.0f, 15.0f));

	TransInfo.Position += TransInfo.Direction;

	return 0;
}

void Bullet::Render()
{
	for (int i = 0; i < 2; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(
			TransInfo.Position.x,
			TransInfo.Position.y + i,
			Buffer[i], Color);
	}
}

void Bullet::Release()
{
}

