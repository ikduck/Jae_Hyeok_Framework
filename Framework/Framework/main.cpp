#define _CRT_SECURE_NO_WARNINGSS // 출력에 에러 뜨는 거 복사해서 넣으면됨
#include "Parent.h"
#include "Child.h"
#include "Bullet.h"
/*
// *** 7. 생성자 & 소멸자 & 복사생성자
			
// *** 8. 깊은 복사 얕은 복사
// *** (복사생성자 추가 설명)

// *** 9. 오버로딩 & 오버라이딩
// 오버로딩 - 복사생성자와 같은 형태 (같은 클래스에 같은 함수를 생성가능하지만
	함수의 매개변수의 갯수와 형태가 다 달라야지만 같은이름으로 생성가능) (자신의 클래스에서만 가능)
//오버라이딩 - 상속이 아니면 사용할수 없음  
	함수의 이름 매개변수가 모두 같아야함 , 부모클래스에서 사용할지 자식클래스에서 사용할지 정하는 것.
	오버로딩 된 함수를 자식클래스에서 오버라이딩 할수 있음 -> 같이 사용할수 있고 서로 기능이 다르다.

 오버로딩 오버라이딩의 차이점은 어떻게 호출할 것이냐의 차이
// 함수의 이름을 동일하게 사용하는 방법 3가지 네임스페이스 ,오버로딩 ,오버라이딩
	네임스페이스로 접근함

// *** 10. 연산자 오버로딩

// *** 11. 포인터 (복습) & 캡슐화
*/

// 복사 생성자 추가1
/*
struct tagInfo
{
	int Number;
};

class Object
{
private:
protected:
	 tagInfo m_Info;
public:
	int Number ;
	char* Name;
public:
	virtual Object* Clone() = 0; 

public:
	// 생성자 소멸자 복사생성자 기초
	/*
	// ** 사용자가 호출하지 않아도 스스로 호출됨
	// ** 기본 생성자 : 우리가 호출하지 않아도 보이지 않는곳에 호출함 , 기본 소멸자 , 기본 복사생성자도 있음
	// ** 생성자: 생성된 직후에 호출됨
	Object() 
	{
		cout << "생성자" << endl;
	};
	// ** 복사 생성자 : 사용자가 호출하는 시점에 호출됨. 사용자가 호출하지 않으면 호출이 되지않음 (때와 장소를 가리지 않고 호출가능)
	// ** 전달값의 개수와 자료형에 따라서 선택적(자동)으로 호출됨.
	Object(int _Number)
	{
		cout << "복사 생성자 : int" << endl;

		// 깊은 복사의 도입부
		Number = _Number;
	};

	Object(float  _Number)
	{
		cout << "복사 생성자 : float" << endl;

		Number = (int)_Number;
	};
	// ** 소멸자 : 클래스가 삭제되기 직전에
	~Object() 
	{
		cout << "소멸자" << endl;
	};
	*/ 

	// 복사 생성자2
	/*
	Object(const Object& _Obj)
	{
		cout << " 복사 생성자" << endl;
	}
	*/ 

	// 깊은 복사 , 얕은 복사 (수정해야함)
	 /*
	Object()
	{
		cout << "생성자" << endl;
	};
	Object(int _Number) 
	{
		cout << "복사 생성자" << endl;
		Number = _Number;
	};
	 Object(Object* _Obj) 
	 {
	 	// Name = new char[strlen](_Obj)->Name;
		 Number = _Obj->Number;
	 }

	Object(tagInfo _Info) : m_Info(_Info) {	}

	~Object()
	{
		cout << "소멸자" << endl;
	};
};
	*/

// 오버로딩 & 오버라이딩
/*
// 오버로딩
// 매개변수의 형태와 개수에 따라서 호출되는 함수가 달라짐
class Object
{
public:
	virtual void Output()
	{
		cout << "Object : " << endl;
	}
	
	virtual void Output(string _str)
	{
		cout << "Object : " << _str << endl;
	}
	};
}
// 오버라이딩 : 상속간에서의
// virtual - override 써야함
class AAA : public Object
{
public:
	void Output() override
	{
		cout << "AAA : " << endl;
	}

	void Output(string _str)
	{
		cout << "AAA : " << _str << endl;
	}
	*/

// 복사생성자 추가 1
/*
class Player : public Object
{
public:
	virtual Object* Clone() override{	return new Player(*this); }
	
	void Output() { cout << m_Info.Number << endl; }

	Player() {}
	Player(tagInfo _Info) : Object(_Info) { };
	~Player() {}

};
*/

// 예제1
// Object* GetObject(string _Key);
// map<string, Object*> PortotypeObject;

// *** 10. 연산자 오버로딩 operator
struct tagInfo
{
	int Number;

	tagInfo() {}
	tagInfo(int _Number) : Number(_Number) {}
	~tagInfo() {}
};

class Object
{
private:
	tagInfo Info;
	// int Number;
public:
	// Object를 사용할때 = 기능을 추가
	Object& operator+=(const Object& _Obj)
	{
		Info.Number += _Obj.Info.Number;
		return *this;
	}

	Object& operator++()
	{
		Info.Number += 1;
		return *this;
	}
	
public:
	// {} 를 안쓰면 정의를 해줘야함
	Object() {}
	Object(tagInfo _Info) : Info(_Info) {}
	~Object() {}

	void Output()
	{
		cout << Info.Number << endl;
	}

};

int main(void)
{
	// 생성자 복사 생성자 기초
	/*	
	// 생성자 :생성된 직후에 생성자가 호출됨
	// Object o;  // Object o = Object(); 뒤에 = Object();를 생략해도 자동으로 생성됨

	// 복사 생성자  
	Object o = Object(3.141592f);

	cout << "Hello World!!" << endl;
	*/

	// 깊은 복사 , 얕은 복사 (수정해야함)
	/*
	Object o1;
	o1.Number = 10;
	o1.Name = (char*)"a" ;

	Object o2  = o1; // Object o2  =  Object(o1)
	o1.Number = 20;
	o1.Name = (char*)"b";

	cout << o2.Number << endl;
	cout << o2.Name << endl;
	*/

	/*
	int i = 10;
	int n(10);
	*/

	// 복사생성자 추가1
	/*
	// 복사 생성자를 더 수월하게 사용하기 위해서 사용
	tagInfo Info;

	AAA a[8];

	for (int i = 0; i < 8; ++i)
	{
		Info.Number = i + 1;
		a[i] = AAA(Info);
	}

	for (int i = 0; i < 8; ++i)
		a[i].Output();
	*/

	// AAA a = AAA(AAA());
	
	// 예제1
	/*
	tagInfo  Info;

	Info.Number = 10;
	PortotypeObject["Player"] = new Player(Info);

	// Clone 을 안써주면 얕은 복사임
	// Object* pPlayer = GetObject("Player")->Clone();
	// 위와 같이 쓰면 에러나면 게임 터짐
	// 항상 예외 처리를 해줘야함

	Object* pProtoObj = GetObject("Player")->Clone();
	Object* pPlayer = nullptr;

	if (pProtoObj != nullptr)
		pPlayer = pProtoObj->Clone();
	*/

	Object o1(tagInfo(10));
	Object o2(o1);

	o2 += o1;

	++o2;

	o2.Output();
	

	return 0;
}

// 예제1
/*
Object* GetObject(string _Key)
{
	map<string, Object*>::iterator iter = PortotypeObject.find(_Key);

	if (iter == PortotypeObject.end())
		return nullptr;
	else
		return iter->second;
}
*/

#pragma region 20220621

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
/*
// 주의! 데이터가 부모 클래스에 있을때 자식클래스에 만들어주면\
값을 형변환(캐스트)할 수 없으니 부모 클래스에 변수가 만들어져있는지 확인할것!
// 아래와 같은 방식을 사용하는 것이 가장 이상적이다.\
부모 클래스에서는 변수 생성 출력 만하고 자식 클래스에서 초기화를 해주는 형식
*/
// 상속 코드
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

// 코드
/*
#include "Parent.h"
#include "Child.h"
#include "Bullet.h"

// const이기 때문에 어짜피 데이터 영역으로빠지기 때문에
// 아래 스택 영역에서 빼놨음
const int ID_Child = 0;
const int ID_Bullet = 1;

int main(void)
{
	// 형태가 부모이기 때문에 0이 우선적으로 출력됨
	// Parent* p;
	// p->Initialize();
	// p->Output();

	// 추상화
	
	// Child c;
	// c.Initialize();
	// c.Output();

	// Bullet b;
	// b.Initialize();
	// b.Output();

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
		p[i]->Update();
	for (int i = 0; i < 2; ++i)
		p[i]->Output();

	if (p[ID_Child]->Get() > 1000)
	{
		break;
	}
}

return 0;
}
*/

#pragma endregion

#pragma region 20220622

// 잡다한 지식
/*
// 싱글톤 패턴 : 객체의 인스턴스가 오직 1개만 생성되는 패턴
// 프로그램이 종료됬을때 스택에 변수가 있는 경우에는 삭제되지만 \
힙 영역이나 데이터영역에 있는 것들은 프로그래머가 지워주지 않으면 유지됨

// 데이터 복구의 영역
// 컴퓨터를 끄기 전에는 휴지통에서 지워진 프로그램도 되살릴수 있지(데이터 로그가 남아서 그걸로 복구)만\
 컴퓨터를 종료하게되면 복구할수 없음

// this 포인터는 멤버 함수가 호출된 객체의 주소를 가리키는 숨겨진 포인터다.
*/



#pragma endregion



