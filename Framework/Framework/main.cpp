// *** Framework_v2.1
#define _CRT_SECURE_NO_WARNINGS
#include "Headers.h"
#include "MainUpdate.h"

// *** Input
/*
	
*/

const DWORD KEY_UP			 = 1;
const DWORD KEY_DOWN	 = 2;
const DWORD KEY_LEFT		 = 4;
const DWORD KEY_RIGHT	 = 8;
const DWORD KEY_SPACE	 = 16;
const DWORD KEY_ENTER	 = 32; // = RETURN
const DWORD KEY_CTRL		 = 64;	// CONTROL
const DWORD KEY_ALT		 = 128; // MENU

int main(void)
{
	// count와 time으로 다음 화면으로 이동
	
	MainUpdate Main;
	Main.Initialize();

	ULONGLONG Time = GetTickCount64(); // 1 / 1000

	while (true)
	{
		if (Time + 50 < GetTickCount64())
		{
			Time = GetTickCount64();

			system("cls");

			Main.Update();
			Main.Render();
		}
	}
	

	// 입력한 숫자로 입력키 받아오기(비트이해)
	/*
	DWORD InputKey = 0;
	cout << "입력 : "; cin >> InputKey;

	if (InputKey & KEY_UP)
		cout << "KEY_UP" << endl;

	if (InputKey & KEY_DOWN)
		cout << "KEY_DOWN" << endl;

	if (InputKey & KEY_LEFT)
		cout << "KEY_LEFT" << endl;

	if (InputKey & KEY_RIGHT)
		cout << "KEY_RIGHT" << endl;

	if (InputKey & KEY_SPACE)
		cout << "KEY_SPACE" << endl;

	if (InputKey & KEY_ENTER)
		cout << "KEY_ENTER" << endl;

	if (InputKey & KEY_CTRL)
		cout << "KEY_CTRL" << endl;

	if (InputKey & KEY_ALT)
		cout << "KEY_ALT" << endl;
		*/

	

	return 0;
}