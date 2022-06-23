#include "MainUpdate.h"
#include "SceneManager.h"

MainUpdate::MainUpdate()  : Count(0) { }

MainUpdate::~MainUpdate() { Release(); }

void MainUpdate::Initialize()
{
	state = LOGO;
	SceneManager::GetInstance()->SetScene(LOGO);
}

void MainUpdate::Update()
{
	++Count;

	if (Count <= 100)
	{
		Count = 0;
	}
}

void MainUpdate::Render()
{
}

void MainUpdate::Release()
{
}


