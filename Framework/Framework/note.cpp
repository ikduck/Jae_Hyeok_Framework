#include <iostream>
#include <Windows.h> 

using namespace std;

// *** 11. 포인터 (복습) & 캡슐화

// ** 캡슐화 
// 데이터(변수)와 기능(함수)을 하나의 구조(클래스)로 묶는 과정

// ** 추상성 : virtual 

// ** 포인터
// 1. 데이터 , & 주소반환연산자
// 2. 포인터변수 라면 [ 동적할당 ] 할것
// 3. 클래스 & 구조체는 [ . ] (점), [ -> ] (화살표)로 접근
// 4. [ 동적할당 ] 했다면 반드시 [ 할당해제 ] ( 냉장고 문열어놓고 안닫고 가는것과 같음)
// 자바와 C#은 garbage collection이 있어서 할당해제 안해줘도 해제해주지만
// 파이썬과 c,c++에는 없다. (청소부의 유무) 대신 사용자가 원할때 해제해줄수 있음
// 생산과 삭제가 많은 데이터를 소모하는데 이때 garbege collection는 가득차야지 소각을 해서 
// 잠깐의 렉을 유발할수 있음(게임 잘돌아가다가 프레임드랍 & 렉걸리는거)
// 위와 같은 이유때문에 C#과 자바의 장점은 쉽다는 것이고 c,c++은 효율적이고 빠르다.
// 메모리 누수 : 스카이림에 로그 많이남아서 게임 점점 느려지는 것과 같음

// ** 인라인(lnline)
// 인라인 -> 함수가 우선 실행될수 있도록 ★도와줌★
// 클래스 내부에 함수의 기능을 적었을때 자동으로 인라인 함수가됨 : 성능의 효율성을 기대하기 어려움
// ex) 데이터 해제(공간확보)어짜피 마지막에 해야되서 , 데이터 생성 어짜피 처음에 생성되서

// ** const : 상수화 키워드 : 다른 프로그래머들에게 알려주기 위함이며
// 값을 변경하지 말아달라고 적어주는 거임

// ** & 연산자
// 1. 이항연산자일때 (&&) 논리 연산자로 이루어져있어 true false 존재하느냐 안하느냐로 이뤄짐
// 2. 이항연산자일때 & 일때는 비트 연산자 plc와 같은 기능으로 입력신호를 받았을때 동작
// 3. 단항 연산자 앞쪽에 쓰이면 주소반환 연산자로 사용됨
// 4. 래퍼런스 연산자 -> 주소값 그자체를 가져오는것

/*
int main(void)
{
	// 스택 영역        힙 영역
	Parent* pParent = new Child;
	delete pParent;
	// 힙 영역에 선언한 주소를 스택영역에 넘겨준
	// new하고 delete를 하지 않으면 데이터 누수가 일어남

	// pParent->Initialize();

	
	

	return 0;
}
*/

// *** 싱글톤
/*
	1. 장소에 구애없이 막 가져다 쓸수있게 만들어야함
	2. 싱글톤은 관리자의 개념으로 사용하기 때문에 데이터는 한군데에만 있어야함
	so! 싱글톤은 하나만 만들어야하기 때문에 생성자를 private에 넣음
*/

// *** 싱글톤 사용하기
/*
class Singleton
{
private:
	// static 정적형태
	// 정적과 동적은 반대되는 개념이 아니라 서로다른 기능임
	static Singleton* Instance;

	int Number;

	// 싱글톤의 특징 생성자를 private에 넣어서 다중생성을 막음
	Singleton() : Number(0) {}
public:
	static Singleton* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new Singleton;
			// Instance = new Singleton();이 정석이지만 c에서는 생략함
		}
		return Instance;
	}

	int GetNumber() const { return Number; }
	void SetNumber(const int& _Number) { Number = _Number; }

	~Singleton() {}
};


Singleton* Singleton::Instance = nullptr; // 초기화

int main(void)
{
	// 에러가 안뜨면 setNumber(10)을 해라0
	Singleton::GetInstance()->SetNumber(10);
	cout << Singleton::GetInstance()->GetNumber() << endl;


	return 0;
}
*/