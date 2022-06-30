// *** Framework_v7.2  (template <typename T>)
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

	/*
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
	*/
 	return 0;
 }

// Gof의 디자인 패턴
// 상속 추상성 다형성 을 사용해서 객체만들기 
// clone제외