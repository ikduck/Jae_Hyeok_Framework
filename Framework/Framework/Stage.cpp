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
	// *** 1. 반환형태가 Object*  && list<Object*>
	// *** 2. Key 가 전달되어야 함.
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

	list<Object*>* pBulletList = ObjectManager::GetInstance()->GetObjectList("＊");

	if(pBulletList != nullptr)
	{
		for (list<Object*>::iterator iter = pBulletList->begin();
			  iter != pBulletList->end();)
		{
			if ((*iter)->GetPosition().x >= 100.0f)
			{
				// pBulletList->erase(iter); = for문이 도는 중에 삭제되서 에러떠서
				// iter에 넣음
				iter = pBulletList->erase(iter);
			}
			else
				// 삭제할게 없으면 진행
				++iter;
		}
	}



}

void Stage::Render()
{
	// 좌표 설정
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

// ptp = 끊어지면 다시 연결할수 없음 
// 1명 호스트 10명의 플레이어 -> 게임이 종료되면 다시 들어갈수가없음
// 서버에서 방을 제공해주는 경우

// 제일마지막으로 출력한 객체의 뒤에 연달아 생성하게됨