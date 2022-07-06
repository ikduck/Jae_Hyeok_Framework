#include "Logo.h"
#include "SceneManager.h"
#include "InputManager.h"

#include "ObjectManager.h"
#include "Player.h"
#include"Enemy.h"
#include "Bullet.h"

#include "ObjectFactory.h"
#include"CursorManager.h"

Logo::Logo() { }

Logo::~Logo() { }

void Logo::Initialize()
{
	ObjectManager::GetInstance()->AddObject(ObjectFactory<Player>::CreateObject());
	// Object* pPlayer = new Player;
	// pPlayer->Initialize();
	// ObjectManager::GetInstance()->AddObject(pPlayer);
	// ObjectManager::GetInstance()->AddObject(ObjectFactory<Enemy>::CreateObject());
	// Object* eEnemy = new Enemy;
	// eEnemy->Initialize();
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
	CursorManager::GetInstance()->WriteBuffer( 0 ,0, 
	(char*) " ", 8

	);
	
}

void Logo::Release()
{
}

//  !*****      ~*@@@@@;,            !!;      ,!!!!!!!!!!~    						  