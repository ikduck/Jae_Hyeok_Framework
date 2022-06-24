#pragma once
#include "Headers.h"

class InputManager
{
private:
	static InputManager* Instance;
	InputManager();

	// m_ 멤버변수의 dw Dword m_dwKey;
	// Key 값을 가지고 있기 위해서 싱글톤으로 만듦
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

// const 를 사용하지 못할때
// 대입연산자(=)를 사용할때 static을 사용할때
