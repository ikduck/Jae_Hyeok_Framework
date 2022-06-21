// *** Framework_v0.2
#include <iostream>

using namespace std;

// 이론 수업 2022_06_20
/*
	// *** 1. 정보은닉	: 누구나 수정가능한 형태 (나무위키), 누구나 수정할수 없는 형태 (개인정보) ,승인하에 열람이 가능하다.
	// *** 2. 캡슐화	: 함수와 데이터가 따로되있는 형태 , 자신의 기능을 데이터와 묶여있는 형태 청소기는 청소기로만 사용하는 것 성능은 다를수있지만 다 같은 기능임
	// *** 3. 추상화	: 저기요! 했을때 누굴 불렀을지는 모르지만 누구든지 될수있음
	// *** 4. 상속		: 부모가 사용하는것은 자식이 사용할수 있음, 사용할 수 없는 것도 있음(Private), 가족들만 사용가능(Protected), 모두 사용할수 있음(Public)
	// *** 5. 다형성	: 형태는 다르지만 학생에 포함됨
	
	// 구조체는 public이다. 클래스 private로 사용가능
	
	// if 학원이라는 추상적인 곳에서 여러 학원을 다니는(상속) 학생들이(다형성) 자기만의 걸음으로(캡슐화) 학생 개인정보는 알수없음(정보은닉)   
	
	// Object : 하나의 객체
	// Class  : 하나의 집합(설명서, 지도 개념) ,잘못되면 클래스로 가야함
	
	// 모든 객체는 클래스로 구성되어있지만 클래스는 객체로 이뤄지지 않을수도 있음 * 추상클래스
	
	// 키보드를 예로 들면 버튼 객체 여러개가 모여서 키보드라는 객체를 만듦
*/

// 이론수업 2022_06_21
/*
	위의 클래스의 5가지 특성을 한개한개 따로 외우는 것이아닌
	5가지 모두를 지켜야 클래스를 구성할수있기 때문에 구조를 이해해야함
*/

struct AAA
{
// private: c에서는 불가능 c++에서만 가능
	int Number = 0;
	// 구조체는 기본이 public
};

// 캡슐화 : 내부에서 모든 기능을 해결
class BBB
{
	// m_는 class 자신의 변수라는 뜻
	// 데이터는 private 해줘야함 (정보은닉)
private:
	int m_iNumber;
	// class는 private가 기본임

	// public: 사용할려면 신중하게 써야함(인터넷)
public:				

	void Initialize() { m_iNumber = 0; }

	// ** 데이터를 사용하는 것은 가능하지만 수정은 불가.
	int GetNumber() { return m_iNumber;}

	// ** 데이터를 수정하는 것은 가능하지만 참조는 불가.
	void SetNumber(int _Number) { m_iNumber = _Number; }

	// 겟터와 셋터 (모듈화)
};

class CCC
{
private:
	int m_iNumber;

public:
	void Initialize() { m_iNumber = 100; }

	// ** 데이터를 사용하는 것은 가능하지만 수정은 불가.
	int GetNumber() { return m_iNumber; }

	// ** 데이터를 수정하는 것은 가능하지만 참조는 불가.
	void SetNumber(int _Number) { m_iNumber = _Number; }
};

 void Initialize( int& _Number);

int main(void)
{
	AAA a;
	Initialize(a.Number); // 쓰레기값 -> 0으로 초기화
	cout << a.Number << endl;

	BBB b; // 이형태는 절대로 바뀌지 않음
	// b.Number; 바로 사용할수 없음
	b.Initialize(); // = b.SetNumber(10);
	cout << b.GetNumber() << endl;

	CCC c;
	c.Initialize();
	cout << c.GetNumber() << endl;

	return 0;
}

void Initialize( int& _Number)
{
	_Number =  0;
}

// 잡담
/*
	폴리곤 : 삼각형 버택스? 폴리곤 점 
	가상현실 -> 폴리곤이 버택스만큼 작아졋을때 
	수도권 - 초봉 2600 10년전	
*/

// 공부 어떻게 하는지 물어보기