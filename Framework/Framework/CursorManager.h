#pragma once
#include "Headers.h"

class CursorManager
{
public:
	// 콘솔의 커서창을 바꿔주는 함수
	static void SetCurosrPosition(float _x, float _y)
	{
		COORD Pos = { (SHORT)_x, (SHORT)_y };
		SetConsoleCursorPosition(
			GetStdHandle(STD_OUTPUT_HANDLE),  Pos);
		// SetConsoleCursorPosition : 콘솔창의 좌표 
	}	

	static void Draw(float _x, float _y, string _str)
	{
		SetCurosrPosition(_x, _y);
		cout << _str;
	}
};


