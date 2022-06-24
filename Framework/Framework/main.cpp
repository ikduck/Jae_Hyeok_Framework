// *** Framework_v2.4
#define _CRT_SECURE_NO_WARNINGS
#include "Headers.h"
#include "MainUpdate.h"

int main(void)
{
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

	return 0;
}

// 상속 추상성 다형성 을 사용해서 객체만들기 