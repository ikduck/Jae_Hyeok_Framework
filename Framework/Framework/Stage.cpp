#include "Stage.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "Player.h"

#include "CursorManager.h"
#include "Bullet.h"
#include "Enemy.h"

Stage::Stage() : pPlayer(nullptr) { }
Stage::~Stage() { Release(); }

void Stage::Initialize()
{
	// *** 1. ��ȯ���°� Object*  && list<Object*>
	// *** 2. Key �� ���޵Ǿ�� ��.
	// list<Object*>* pPlayerList = ObjectManager::GetInstance()->GetObjectList("Player");
	// if (pPlayerList != nullptr)
	// 	pPlayer = pPlayerList->front();

	Object* pEnemyProto = new Enemy;
	pEnemyProto->Initialize();

	for (int i = 0; i < 5; ++i)
	{
		srand(DWORD(GetTickCount64() * (i + 1)));
		Object* pEnemy = pEnemyProto->Clone();
		pEnemy->SetPosition(118.0f, rand() % 30);

		ObjectManager::GetInstance()->AddObject(pEnemy);
		// pEnemyList.push_back(pEnemy);
	}
}

void Stage::Update()
{
	ObjectManager::GetInstance()->Update();

	list<Object*>* pBulletList = ObjectManager::GetInstance()->GetObjectList("��");

	if(pBulletList != nullptr)
	{
		for (list<Object*>::iterator iter = pBulletList->begin();
			  iter != pBulletList->end();)
		{
			if ((*iter)->GetPosition().x >= 100.0f)
			{
				// pBulletList->erase(iter); = for���� ���� �߿� �����Ǽ� ��������
				// iter�� ����
				iter = pBulletList->erase(iter);
			}
			else
				// �����Ұ� ������ ����
				++iter;
		}
	}



}

void Stage::Render()
{
	// ��ǥ ����
	/*
	Vector3 v1 = Vector3(1, 2);
	Vector3 v2 = Vector3(10, 20);

	Vector3 v3 = v1 + v2;

	CursorManager::Draw(v3.x, v3.y, "zzz");
	*/

	ObjectManager::GetInstance()->Render();
}

void Stage::Release()
{	
	::Safe_Delete(pPlayer);
}

// ptp = �������� �ٽ� �����Ҽ� ���� 
// 1�� ȣ��Ʈ 10���� �÷��̾� -> ������ ����Ǹ� �ٽ� ����������
// �������� ���� �������ִ� ���

// ���ϸ��������� ����� ��ü�� �ڿ� ���޾� �����ϰԵ�