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
}

int Bullet::Update()
{
	TransInfo.Position.x += 2.0f;

	return 0;

}

void Bullet::Render()
{
	for (int i = 0; i < MAX_SIZE; ++i)
	{
		CursorManager::Draw(
			TransInfo.Position.x - (TransInfo.Scale.x * 0.5f),
			TransInfo.Position.y - (TransInfo.Scale.x * 0.5f) + i,
			Buffer[i]);
	}
}

void Bullet::Release()
{
}
