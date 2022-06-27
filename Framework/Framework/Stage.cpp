#include "Stage.h"
#include "Player.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "ObjectManager.h"
Stage::Stage() : pPlayer(nullptr){ }

Stage::~Stage() { Release(); }

void Stage::Initialize()
{
	// *** 1. ��ȯ���°� Object*  && list<Object*>
	// *** 2. Key �� ���޵Ǿ�� ��.
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
	// ptp = �������� �ٽ� �����Ҽ� ���� 
	// 1�� ȣ��Ʈ 10���� �÷��̾� -> ������ ����Ǹ� �ٽ� ����������
	// �������� ���� �������ִ� ���
	::Safe_Delete(pPlayer);
}

