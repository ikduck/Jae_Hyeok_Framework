#pragma once
#include "Headers.h" 

class Parent
{
private:

protected:
	// 데이터는 은닉시키고
	int m_Number;

public:
	// 함수는 공개시킴
	virtual void Initialize() = 0; // virtual 함수의 몸체가 없을때 사용할수 있고
	virtual void Update() = 0;
	virtual void Output() = 0;
	
	// 설띵
	/*
		// 클래스의 외부에서는 사용할수 없다.
		// *** [virtual] = 가상함수
		// *** [=0] : virtual 함수에만 붙일수 있다.
		// *** 함수의 끝에 [=0] 붙이게 되면 [순수 가상 함수] 가 된다.

		// *** [순수 가상 함수]
		// *** virtual 함수가 함수의 몸체(정의)가 없을때 사용한다. 

		// *** virtual 함수를 사용하는 이유?
		// *** 순수 가상함수 사용이유 검색
		//
	*/
};
// 죽음의 다이아몬드 상속구조 지옥도 건들지 않는것이 좋음
// 위 클래스는 추상 클래스가 되서 사용할 수 없음
// 쓸필요가 없으면 virtual =0 으로 순수 가상함수를 만들어 사용하면됨
// 저번에 개인 포폴할때 몬스터 능력치가 안들어 간이유 -> 부모클래스에서 초기화해서
// 브릿지 패턴
