#pragma once


class MainUpdate
{
private:
	int Count;
	//SCENEID state;
	int SceneState;
public:
	void Initialize();
	void Update();
	void Render();
	void Release();

	MainUpdate();
	~MainUpdate();
};

