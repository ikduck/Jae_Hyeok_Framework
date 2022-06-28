#include "Logo.h"
#include "SceneManager.h"
#include "InputManager.h"

#include "ObjectManager.h"
#include "Player.h"
#include"Enemy.h"
#include "Bullet.h"

Logo::Logo() : Scene("") { }

Logo::~Logo() { }

void Logo::Initialize()
{
	str = "Logo";
	
	// 로고에서 왜 동적할당 해주고 초기화 하는 걸까?
	Object* pPlayer = new Player;
	pPlayer->Initialize();
	// Object* eEnemy = new Enemy;
	// eEnemy->Initialize();

	ObjectManager::GetInstance()->AddObject(pPlayer);
	// ObjectManager::GetInstance()->AddObject(eEnemy);
}

void Logo::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_ENTER)
	{
		SceneManager::GetInstance()->SetScene(MENU);
	}
}

void Logo::Render()
{
	cout << str << endl;
}

void Logo::Release()
{
}

