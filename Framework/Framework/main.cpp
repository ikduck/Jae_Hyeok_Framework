#include "Parent.h"
#include "Child.h"
#include "Bullet.h"

// ctrl +space
// 함수만 별도로 namespace할때
/*
	using std::cout;
	using std::endl;
	using std::cin;
*/ 

// 이론수업 2022_06_21
/*
	위의 클래스의 5가지 특성을 한개한개 따로 외우는 것이아닌
	5가지 모두를 지켜야 클래스를 구성할수있기 때문에 구조를 이해해야함

	// 핵심 키워드
	// *** 1. 정보은닉
	//			접근 범위를 설정하는 키워드
	//			private: 자기 자신만 사용가능
	//			protected: 상속간의 공개되 상태 , 비상속 클래스 사용불가, 외부에서도 사용불가,공동체만
	//			public: 공개된 상태
	// *** 2. 캡슐화
	//			데이터(변수)와 기능(함수)을 묶음으로 사용하는 것.
	// *** 3.  추상화
	//			존재하지 않는 형태를 추상 클래스 라고 한다.
	//			ex) 사람, 학생, 군인 등의 대상이 특정되지 않는 경우(추상적인  경우)   :)
	//			ex) "홍길동은 학생이다." 라면 홍길동이라는 특정 대상이 있으므로, \
					  추상적 형태로 볼수없음
	// *** 4 . 상속
	//			아래에 설명있음
	// *** 5 . 다형성
	//			다양한 형태로 존재할수 있다.
	// *** 6. namespace
	//			별도의 영역을 지정하여 동일 이름의 함수를 사용할수 있도록 함
	// *** 7. 생성자 & 소멸자 & 복사생성자
	//			
	// *** 8. 깊은 복사 얕은 복사
	// *** 9. 오버로딩 & 오버라이딩
	// *** 10. 연산자 오버로딩
	// *** 11. 포인터 (복습)
	// 네이밍
	// 문서 정리는 만듦과 동시에 정리해야함
	// 막히고 다시 만들면 거기서 또 막힘 새로 만드는게 아니라 정리를 하는게 더 자기 자신에게 좋음
	// 정리후 막힌부분 물어보기
*/ 

// namespace
/*
namespace AAA
{
	void Output()
	{
		cout << "홍길동" << endl;
	}
}

using  AAA::Output;

namespace BBB
{
	void Output()
	{
		cout << "임꺽정" << endl;
	}
}

int main(void)
{
	Output();
	BBB::Output();
	
	return 0;
)	
*/ 

// void Parent1::Output() // 네임스페이스로 접근하면 사용가능
// 정리법
// 계층구조 -> 소스파일 관리하듯이 
// 필터 하나에 cpp h다 넣고  

// 상속
// 주의! 데이터가 부모 클래스에 있을때 자식클래스에 만들어주면\
값을 형변환(캐스트)할 수 없으니 부모 클래스에 변수가 만들어져있는지 확인할것!
// 아래와 같은 방식을 사용하는 것이 가장 이상적이다.\
부모 클래스에서는 변수 생성 출력 만하고 자식 클래스에서 초기화를 해주는 형식
/*
class AAA
{
protected :
	string m_str;
public:
	void Output()
	{
		cout << m_str << endl;
	}
};

class BBB : public AAA
{
private:
	// string m_str = "BBB";
public:
	void initlalize() { m_str = "BBB"; }
};

class CCC : public AAA
{
private:
	// string m_str = "CCC";
public:
	void initlalize() { m_str = "CCC"; }
};

// [main 출력]
	BBB b;
	b.initlalize();
	b.Output();
	// ((AAA)b).Output();

	CCC c;
	c.initlalize();
	c.Output();
*/

// const이기 때문에 어짜피 데이터 영역으로빠지기 때문에
// 아래 스택 영역에서 빼놨음
const int ID_Child = 0;
const int ID_Bullet = 1;

int main(void)
{
	// 형태가 부모이기 때문에 0이 우선적으로 출력됨
	/*
	Parent* p;
	p->Initialize();
	p->Output();
	*/

	// 추상화
	/*
	Child c;
	c.Initialize();
	c.Output();
	
	Bullet b;
	b.Initialize();
	b.Output();
	*/

	// 다형성
	Parent* p[2];  //  서버에 올라가면 형태는 절대로 바뀔수가 없음 프로그램 다시 짜야함

	p[ID_Child] = new Child;  //  동적이기 때문에 서버에 올라가도 바꿀수 있음
	p[ID_Bullet] = new Bullet;

	for (int i = 0; i < 2; ++i)
	{
		p[i]->Initialize();
		
	}
	
	while (true)
	{
		system("cls");

		for (int i = 0; i < 2; ++i)
		{
			p[i]->Update();
			p[i]->Output();
		}

	}

	return 0;
}

// 추가적인 설명
/*
	// 접근 할수있는 방법 : .(점) , ->(포인터) , ::(네임스페이스) 그 외로 '람다' 가 있다.
	// 람다는 개인적으로 사용하는 것은 적극 권장하지만 팀으로 할때는 
	// static , const, #define, #include 런타임 이전에 올라감 런타임 후에는 스택 힙 영역만 사용
	// 전처리 지시자 : 코드가 실행되기 전에 미리 정해놓은 문구로 코드를 치환해줌
	// 공부 어떻게 하는지 물어보기
*/ 

// 상속
//1. 생성자 :		자신의 클래스명과 동일하지만 반환이 없는 메서드(함수)
//2. 소멸자 :		

// 공부하는법 
/*
	// 1. 시간관리 디테일하게 : 할수있는 계획으로 설정
	// 2. 계획이행 - 접근이 쉬워야함(짬짬이 다해야됨) 5분~ 10분 짧게 많이 시간에 텀이 있어야함
	// 같은 것을 계속 반복해야 함 짧고 길게 가야함 어디에 있든 상관없이
	// 그 시간대에 화장실에 있어도 볼수있게
	// 기억하는 횟수를 늘려라
	// 뇌에 기억 물질이 기억으로가는 다리를 만들어내는데 자주 기억해 줘야지 그 다리가 두꺼워짐
	// 지금은 암기가 목적이니까
	// 힘들때 이렇게 하고 별로 안힘들면 2시간 3시간 해도됨

	// if 10분 공부면 10분간격으로 계획을 짜고 그 시간이 되면 모든걸 스탑하고 최고의 집중력으로 공부
	최소 3회 이상 총합의 시간이 3시간 이상이 넘을때까지 계속 늘려나가야함 한번할때 20~30분정도
*/
// virtual 은 자식을 직접사용하게 하는것

// 자식의 값을 사용하고 싶을때(업 캐스팅)
	/*
	// 1. 형변환(캐스팅)
	((Child*)p)->Initalize();

	// 2.

	// 오버로딩 오버라이딩 : (프로그래밍 -> 공식만 알면됨)
	*/

// 생성자 소멸자 반복생성자 
// C++에서 오버로딩(++, -- , <<) 오버라이딩 이 생기면서 C++이라는 이름을 가지게됨
// API함수 사용 input개념
// string(문자열)은 안함
