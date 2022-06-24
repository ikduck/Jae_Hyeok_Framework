#pragma once
#include "Headers.h"

class InputManager
{
private:
	static InputManager* Instance;
	InputManager();

	// m_ ¸â¹öº¯¼öÀÇ dw Dword m_dwKey;
	DWORD Key;
public:
	static InputManager* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new InputManager;
		}
		return Instance;
	}

	void Inputkey();

	~InputManager();

};

