#include "SceneManager.h"
// #include "Scene.h" // �߻�Ŭ�������� �����͵� �ǹ̰� ����
// �Ʒ� �������� �����ͼ� �پ��ϰ� ����Ұ���(������)
#include "Logo.h"
#include "Menu.h"
#include "Stage.h"

SceneManager* SceneManager::Instance = nullptr;

SceneManager::SceneManager() : SceneState(nullptr) { }
SceneManager::~SceneManager() { Release(); }

void SceneManager::SetScene(SCENEID _SceneState)
{
	// ���� �̹� ������ ������ �ʱ�ȭ ����
	if (SceneState != nullptr)
	{
		delete SceneState;
		SceneState = nullptr;
	}

	switch (_SceneState)
	{
	case LOGO:
		SceneState = new Logo;
		break;

	case MENU:
		SceneState = new Menu;
		break;

	case STAGE:
		SceneState = new Stage;
		break;

	case EXIT:
		exit(NULL);
		break;

	}
	// ���������� Logo , Menu �� �޴����� �ʱ�ȭ ������ؼ� ��
	SceneState->Initialize();
}

void SceneManager::Update()
{
	//  �޾ƿ� ���� update ����
	SceneState->Update();
}

void SceneManager::Render()
{
	// �޾ƿ� ���� Render ����
	SceneState->Render();
}

void SceneManager::Release()
{
	delete SceneState;
	SceneState = nullptr;
}
