#pragma once
#include "Headers.h"

class CursorManager
{
public:
	// �ܼ��� Ŀ��â�� �ٲ��ִ� �Լ�
	static void SetCurosrPosition(float _x, float _y)
	{
		COORD Pos = { (SHORT)_x, (SHORT)_y };
		SetConsoleCursorPosition(
			GetStdHandle(STD_OUTPUT_HANDLE),  Pos);
		// SetConsoleCursorPosition : �ܼ�â�� ��ǥ 
	}	

	static void Draw(float _x, float _y, string _str)
	{
		SetCurosrPosition(_x, _y);
		cout << _str;
	}
};


