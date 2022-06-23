#include "SceneManager.h"

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}
/*
const LOGO = 0;
const MENU = 0;
const STAGE = 0;
const EXIT = 0;
*/
// SCENEID _SceneState
void SceneManager::SetScene()
{
	switch (_SceneState)
	{
	case LOGO:
		cout << "LOGO" << endl;
		break;

	case MENU:
		cout << "MENU" << endl;
		break;

	case STAGE:
		cout << "STAGE" << endl;
		break;

	case EXIT:
		cout << "EXIT" << endl;
		break;

	}
}
