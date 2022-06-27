#include "Stage.h"
#include "Player.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "ObjectManager.h"
Stage::Stage() : pPlayer(nullptr){ }

Stage::~Stage() { Release(); }

void Stage::Initialize()
{
	// *** 1. 반환형태가 Object*  && list<Object*>
	// *** 2. Key 가 전달되어야 함.
	list<Object*>* pPlayerList = ObjectManager::GetInstance()->GetObjectList("Player");

	if (pPlayerList != nullptr)
		pPlayer = pPlayerList->front(); // ->Clone()
}

void Stage::Update()
{
	if (pPlayer)
		pPlayer->Update();
}

void Stage::Render()
{
	if(pPlayer)
		pPlayer->Render();

	// ObjectManager::GetInstance()->Render();
}

void Stage::Release()
{	
	// ptp = 끊어지면 다시 연결할수 없음 
	// 1명 호스트 10명의 플레이어 -> 게임이 종료되면 다시 들어갈수가없음
	// 서버에서 방을 제공해주는 경우
	::Safe_Delete(pPlayer);
}

