// *** Framework_v1.0
#define _CRT_SECURE_NO_WARNINGS
#include "Headers.h"
#include "MainUpdate.h"
// #include <time.h> // 1초단위로 설정됨

// roop 를 도는 기준 (실행되는 순서는 결정되어있다.)

// *** 싱글톤(Singleton)
/*
	1. 장소에 구애없이 막 가져다 쓸수있게 만들어야함
	2. 싱글톤은 관리자의 개념으로 사용하기 때문에 데이터는 한군데에만 있어야함

	so! 싱글톤은 하나만 만들어야하기 때문에 생성자를 private에 넣음
*/

// 싱글톤으로 사용하기
/*
class Singleton // 관리자로 사용함
{
private:
	// static 정적형태
	// 정적과 동적은 반대되는 개념이 아니라 서로다른 기능임
	static Singleton* Instance;
public:
	static Singleton* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new Singleton; // Instance = new Singleton();이 정석이지만 c에서는 생략해도 ()자동으로 추가해줌 
		}
		return Instance;
	}
private:
	int Number;
public:
	int GetNumber() const { return Number; }
	void SetNumber(const int& _Number) { Number = _Number; }
private: 
	Singleton() : Number(0) {}

public: 
	~Singleton() {}

};

Singleton* Singleton::Instance = nullptr;
*/

int main(void)
{
	// 싱글톤으로 만들기
	/*
	Singleton::GetInstance()->SetNumber(10);
	cout << Singleton::GetInstance()->GetNumber() << endl;
	*/
	// 타이머
	/*
	// 과거에 사용하던 방식(32비트) 
	//DWORD dwTime = GetTickCount();

	// 현재시간을 반환하는 함수
	// 1/1000 프로그램을 무한정 사용할 수 없다 그래서 정기 정검을 하는거임 최대한 2~3개월정도. 
	// GetTickCount() 대략 49일
	// GetTickCount64() 5억년? 뉴럴링크 쓰면 5억년 살수있음?
	// 0에서 시작하는게 아니라  GetTickCount64()값을 Time에 넣어줌 (cpu실행 시간) 
	// ULONGLONG Time = GetTickCount64(); 
	 
	 MainUpdate Main;
	 Main.Initialize();
	 
	 //int Count = 0;
	 //char* Array[30];
	 
	for (int y = 0; y < 30; ++y)
	{
		for (int x = 0; x < 30; ++x)
		{
			Array[y][x] = (char*)"*";
		}

	}
	
	// 
	for (int y = 0; y < 30; ++y)
	{
	
		for (int x = 0; x < 30; ++x)
		{
			Array[y][x] = (char*)"*";
		}
		
		Array[y] = (char*)"******************************************************************************************" ;
	}
	
	 
	 while (true)
	 {
	 	// 프레임 제어
	 	// 1초마다 바뀌게 하고싶으면 + 999로 바꿔주면됨
	 	if (Time + 50 < GetTickCount64())
	 	{
	 		Time = GetTickCount64();
	 
	 		// 병목현상이 생김
	 		system("cls");
	 
	 		// cout << Count++ << endl;
	 		
			for (int y = 0; y < 30; ++y)
			{
					for (int x = 0; x < 30; ++x)
					{
						cout << Array[y][x];
					}
					cout << endl;
			}
			
	 		
			for (int y = 0; y < 30; ++y)
			{
				cout << Array[y]<<endl;
			}
			
	 
	 		Main.Update();
	 		Main.Render();
	 
	 	}
	 }
	// Main.Release(); //를 여기가아닌 소멸자에 작성함
	*/


	return 0;
}

// 네임스페이스 : 내부 식별자