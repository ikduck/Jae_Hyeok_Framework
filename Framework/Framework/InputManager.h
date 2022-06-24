#pragma once
#include "Headers.h"

class InputManager
{
private:
	static InputManager* Instance;
	InputManager();

	// m_ ��������� dw Dword m_dwKey;
	// Key ���� ������ �ֱ� ���ؼ� �̱������� ����
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

	DWORD GetKey() const { return Key; }

	void Inputkey(); 

	~InputManager();

};

// const �� ������� ���Ҷ�
// ���Կ�����(=)�� ����Ҷ� static�� ����Ҷ�
