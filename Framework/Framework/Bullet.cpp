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
	TransInfo.Scale = Vector3(2.0f, 2.0f);
	TransInfo.Direction = Vector3(0.0f, 0.0f);
}

int Bullet::Update()
{	
	TransInfo.Direction = MathManager::GetDirection(
		TransInfo.Position, Vector3(60.0f, 15.0f));

	TransInfo.Position += TransInfo.Direction;

	float Distance = MathManager::GetDistance(
		TransInfo.Position, Vector3(60.0f, 15.0f));

	if (Distance < 4)
		return 2; 

	return 0;
}

void Bullet::Render()
{
	CursorManager::GetInstance()->WriteBuffer(
		TransInfo.Position, (char*)"BULLET");
}

void Bullet::Release()
{
}

