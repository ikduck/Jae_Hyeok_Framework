#include "Bullet.h"
#include "CursorManager.h"

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
	// 오답
	/*
	Vector3 Target = Vector3(60.0f, 15.0f);

	Vector3 Result = Target - TransInfo.Position;
	float Distance = sqrt((Result.x * Result.x) + (Result.y * Result.y));

	// float Width = Target.x - TransInfo.Position.x;
	// float Height = Target.y - TransInfo.Position.y;
	// float Distance = sqrt((Width * Width) + (Height * Height));

	TransInfo.Direction /= Distance;

	TransInfo.Position += TransInfo.Direction; // * 2.0f	
	*/  
	
	Vector3 Target = Vector3(60.0f, 15.0f);

	float Width = Target.x - TransInfo.Position.x;
	float Height = Target.y - TransInfo.Position.y;

	float Distance = sqrt((Width * Width) + (Height * Height));

	TransInfo.Direction = Vector3(Width / Distance, Height / Distance);
	
	TransInfo.Position += TransInfo.Direction;

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

