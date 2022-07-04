// *** Framework v9.3 ( DoubleBuffer )
#define _CRT_SECURE_NO_WARNINGS
#include "Headers.h"
#include "MainUpdate.h"

// **** template 에 대하여
/*
// 복잡할거 같으면 사용안하는게 좋음
// template을 사용할때는 이름의 끝에 붙임
// template을 사용하면 복잡해질수 있음
template<typename T1 , typename T2 >
class Temp
{
public:
	// 키워드 / 자료형을 넘겨주는 매개변수
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
	// 함수에 사용할때는 함수 이름의 끝에 사용함
	A* a = Temp<A, B>::Func();

	a->Number = 10;
	// 형태를 전달해줌

	return 0;
}
*/

int main(void)
{
	system("title 김재혁 - 게임명");		// 해쉬 태그(#) 기능을함

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

// Gof의 디자인 패턴
// 상속 추상성 다형성 을 사용해서 객체만들기 
// clone제외

// 화면 깜빡거림을 없애는법  (더블버퍼)
/*
	더블버퍼 페이지 2개를 사용해서 지우는 것을 보여주지않고 교체함
	메인버퍼 임시 버퍼 2개 총 3개를 사용하여 메인 버퍼는 사용하지않고 
	임시버퍼 2개를 전면 버퍼와 후면 버퍼로 사용
*/