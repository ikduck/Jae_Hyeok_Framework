#include "Bullet.h"
#include "CursorManager.h"

Bullet::Bullet() { }
Bullet::Bullet(Transform _TransInfo) : Object(_TransInfo) { }
Bullet::~Bullet() { }

void Bullet::Initialize()
{
	strKey = "Bullet"; // �����;ƴ� 2����Ʈ¥�� Ư��������

	Buffer[0] = (char*)"Ÿ";
	Buffer[1] = (char*)"��";

	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(2.0f, 2.0f);
	TransInfo.Direction = Vector3(0.0f, 0.0f);

	Vector3 Target = Vector3(60.0f, 15.0f);

	Vector3 Result = Target - TransInfo.Position;	// ���� �� -> ��ǥ���� ��ġ - ���� ��ġ 

	// 1�� �������� ������ x �� y�� ���� 1���� �۰� ����������
	// sqrt ������
	float Distance = sqrt((Result.x * Result.x) + (Result.y * Result.y));

	TransInfo.Direction /= Distance;
}

int Bullet::Update()
{
	TransInfo.Position += TransInfo.Direction; // * 2.0f	

	return 0;
}

void Bullet::Render()
{
	for (int i = 0; i < MAX_SIZE; ++i)
	{
		CursorManager::Draw(
			TransInfo.Position.x - (TransInfo.Scale.x * 0.5f),
			TransInfo.Position.y - (TransInfo.Scale.y * 0.5f) + i,
			Buffer[i]);
	}
}

void Bullet::Release()
{
}

