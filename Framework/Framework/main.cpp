// *** Framework v9.3 ( DoubleBuffer )
#define _CRT_SECURE_NO_WARNINGS
#include "Headers.h"
#include "MainUpdate.h"

// **** template �� ���Ͽ�
/*
// �����Ұ� ������ �����ϴ°� ����
// template�� ����Ҷ��� �̸��� ���� ����
// template�� ����ϸ� ���������� ����
template<typename T1 , typename T2 >
class Temp
{
public:
	// Ű���� / �ڷ����� �Ѱ��ִ� �Ű�����
	static T1* Func()
	{
		return new T1;
	}
	static T1* Func(int i)
	{
		return new T1(i);
	}	static T1* Func(float f)
	{
		return new T1(f);
	}
};
class A
{
public:
	int Number;
};

class B
{
public:
	int Number;
};

int main(void)
{
	// �Լ��� ����Ҷ��� �Լ� �̸��� ���� �����
	A* a = Temp<A, B>::Func();

	a->Number = 10;
	// ���¸� ��������

	return 0;
}
*/

int main(void)
{
	system("title ������ - ���Ӹ�");		// �ؽ� �±�(#) �������

	system("mode con cols=120 lines=30");

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

// Gof�� ������ ����
// ��� �߻� ������ �� ����ؼ� ��ü����� 
// clone����

// ȭ�� �����Ÿ��� ���ִ¹�  (�������)
/*
	������� ������ 2���� ����ؼ� ����� ���� ���������ʰ� ��ü��
	���ι��� �ӽ� ���� 2�� �� 3���� ����Ͽ� ���� ���۴� ��������ʰ� 
	�ӽù��� 2���� ���� ���ۿ� �ĸ� ���۷� ���
*/