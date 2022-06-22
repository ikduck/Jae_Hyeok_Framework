#define _CRT_SECURE_NO_WARNINGSS // ��¿� ���� �ߴ� �� �����ؼ� �������
#include "Parent.h"
#include "Child.h"
#include "Bullet.h"
/*
// *** 7. ������ & �Ҹ��� & ���������
			
// *** 8. ���� ���� ���� ����
// *** (��������� �߰� ����)

// *** 9. �����ε� & �������̵�
// �����ε� - ��������ڿ� ���� ���� (���� Ŭ������ ���� �Լ��� ��������������
	�Լ��� �Ű������� ������ ���°� �� �޶������ �����̸����� ��������) (�ڽ��� Ŭ���������� ����)
//�������̵� - ����� �ƴϸ� ����Ҽ� ����  
	�Լ��� �̸� �Ű������� ��� ���ƾ��� , �θ�Ŭ�������� ������� �ڽ�Ŭ�������� ������� ���ϴ� ��.
	�����ε� �� �Լ��� �ڽ�Ŭ�������� �������̵� �Ҽ� ���� -> ���� ����Ҽ� �ְ� ���� ����� �ٸ���.

 �����ε� �������̵��� �������� ��� ȣ���� ���̳��� ����
// �Լ��� �̸��� �����ϰ� ����ϴ� ��� 3���� ���ӽ����̽� ,�����ε� ,�������̵�
	���ӽ����̽��� ������

// *** 10. ������ �����ε�

// *** 11. ������ (����) & ĸ��ȭ
*/

// ���� ������ �߰�1
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
	// ������ �Ҹ��� ��������� ����
	/*
	// ** ����ڰ� ȣ������ �ʾƵ� ������ ȣ���
	// ** �⺻ ������ : �츮�� ȣ������ �ʾƵ� ������ �ʴ°��� ȣ���� , �⺻ �Ҹ��� , �⺻ ��������ڵ� ����
	// ** ������: ������ ���Ŀ� ȣ���
	Object() 
	{
		cout << "������" << endl;
	};
	// ** ���� ������ : ����ڰ� ȣ���ϴ� ������ ȣ���. ����ڰ� ȣ������ ������ ȣ���� �������� (���� ��Ҹ� ������ �ʰ� ȣ�Ⱑ��)
	// ** ���ް��� ������ �ڷ����� ���� ������(�ڵ�)���� ȣ���.
	Object(int _Number)
	{
		cout << "���� ������ : int" << endl;

		// ���� ������ ���Ժ�
		Number = _Number;
	};

	Object(float  _Number)
	{
		cout << "���� ������ : float" << endl;

		Number = (int)_Number;
	};
	// ** �Ҹ��� : Ŭ������ �����Ǳ� ������
	~Object() 
	{
		cout << "�Ҹ���" << endl;
	};
	*/ 

	// ���� ������2
	/*
	Object(const Object& _Obj)
	{
		cout << " ���� ������" << endl;
	}
	*/ 

	// ���� ���� , ���� ���� (�����ؾ���)
	 /*
	Object()
	{
		cout << "������" << endl;
	};
	Object(int _Number) 
	{
		cout << "���� ������" << endl;
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
		cout << "�Ҹ���" << endl;
	};
};
	*/

// �����ε� & �������̵�
/*
// �����ε�
// �Ű������� ���¿� ������ ���� ȣ��Ǵ� �Լ��� �޶���
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
// �������̵� : ��Ӱ�������
// virtual - override �����
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

// ��������� �߰� 1
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

// ����1
// Object* GetObject(string _Key);
// map<string, Object*> PortotypeObject;

// *** 10. ������ �����ε� operator
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
	// Object�� ����Ҷ� = ����� �߰�
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
	// {} �� �Ⱦ��� ���Ǹ� �������
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
	// ������ ���� ������ ����
	/*	
	// ������ :������ ���Ŀ� �����ڰ� ȣ���
	// Object o;  // Object o = Object(); �ڿ� = Object();�� �����ص� �ڵ����� ������

	// ���� ������  
	Object o = Object(3.141592f);

	cout << "Hello World!!" << endl;
	*/

	// ���� ���� , ���� ���� (�����ؾ���)
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

	// ��������� �߰�1
	/*
	// ���� �����ڸ� �� �����ϰ� ����ϱ� ���ؼ� ���
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
	
	// ����1
	/*
	tagInfo  Info;

	Info.Number = 10;
	PortotypeObject["Player"] = new Player(Info);

	// Clone �� �Ƚ��ָ� ���� ������
	// Object* pPlayer = GetObject("Player")->Clone();
	// ���� ���� ���� �������� ���� ����
	// �׻� ���� ó���� �������

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

// ����1
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

// �߰����� ����
/*
	// ���� �Ҽ��ִ� ��� : .(��) , ->(������) , ::(���ӽ����̽�) �� �ܷ� '����' �� �ִ�.
	// ���ٴ� ���������� ����ϴ� ���� ���� ���������� ������ �Ҷ��� 
	// static , const, #define, #include ��Ÿ�� ������ �ö� ��Ÿ�� �Ŀ��� ���� �� ������ ���
	// ��ó�� ������ : �ڵ尡 ����Ǳ� ���� �̸� ���س��� ������ �ڵ带 ġȯ����
	// ���� ��� �ϴ��� �����
*/ 

// ���
//1. ������ :		�ڽ��� Ŭ������� ���������� ��ȯ�� ���� �޼���(�Լ�)
//2. �Ҹ��� :		

// �����ϴ¹� 
/*
	// 1. �ð����� �������ϰ� : �Ҽ��ִ� ��ȹ���� ����
	// 2. ��ȹ���� - ������ ��������(««�� ���ؾߵ�) 5��~ 10�� ª�� ���� �ð��� ���� �־����
	// ���� ���� ��� �ݺ��ؾ� �� ª�� ��� ������ ��� �ֵ� �������
	// �� �ð��뿡 ȭ��ǿ� �־ �����ְ�
	// ����ϴ� Ƚ���� �÷���
	// ���� ��� ������ ������ΰ��� �ٸ��� �����µ� ���� ����� ����� �� �ٸ��� �β�����
	// ������ �ϱⰡ �����̴ϱ�
	// ���鶧 �̷��� �ϰ� ���� ������� 2�ð� 3�ð� �ص���

	// if 10�� ���θ� 10�а������� ��ȹ�� ¥�� �� �ð��� �Ǹ� ���� ��ž�ϰ� �ְ��� ���߷����� ����
	�ּ� 3ȸ �̻� ������ �ð��� 3�ð� �̻��� ���������� ��� �÷��������� �ѹ��Ҷ� 20~30������
*/
// virtual �� �ڽ��� ��������ϰ� �ϴ°�

// �ڽ��� ���� ����ϰ� ������(�� ĳ����)
	/*
	// 1. ����ȯ(ĳ����)
	((Child*)p)->Initalize();

	// 2.

	// �����ε� �������̵� : (���α׷��� -> ���ĸ� �˸��)
	*/

// ������ �Ҹ��� �ݺ������� 
// C++���� �����ε�(++, -- , <<) �������̵� �� ����鼭 C++�̶�� �̸��� �����Ե�
// API�Լ� ��� input����
// string(���ڿ�)�� ����

// ctrl +space
// �Լ��� ������ namespace�Ҷ�
/*
	using std::cout;
	using std::endl;
	using std::cin;
*/

// �̷м��� 2022_06_21
/*
	���� Ŭ������ 5���� Ư���� �Ѱ��Ѱ� ���� �ܿ�� ���̾ƴ�
	5���� ��θ� ���Ѿ� Ŭ������ �����Ҽ��ֱ� ������ ������ �����ؾ���

	// �ٽ� Ű����
	// *** 1. ��������
	//			���� ������ �����ϴ� Ű����
	//			private: �ڱ� �ڽŸ� ��밡��
	//			protected: ��Ӱ��� ������ ���� , ���� Ŭ���� ���Ұ�, �ܺο����� ���Ұ�,����ü��
	//			public: ������ ����
	// *** 2. ĸ��ȭ
	//			������(����)�� ���(�Լ�)�� �������� ����ϴ� ��.
	// *** 3.  �߻�ȭ
	//			�������� �ʴ� ���¸� �߻� Ŭ���� ��� �Ѵ�.
	//			ex) ���, �л�, ���� ���� ����� Ư������ �ʴ� ���(�߻�����  ���)   :)
	//			ex) "ȫ�浿�� �л��̴�." ��� ȫ�浿�̶�� Ư�� ����� �����Ƿ�, \
					  �߻��� ���·� ��������
	// *** 4 . ���
	//			�Ʒ��� ��������
	// *** 5 . ������
	//			�پ��� ���·� �����Ҽ� �ִ�.
	// *** 6. namespace
	//			������ ������ �����Ͽ� ���� �̸��� �Լ��� ����Ҽ� �ֵ��� ��
	// *** 7. ������ & �Ҹ��� & ���������
	//
	// *** 8. ���� ���� ���� ����
	// *** 9. �����ε� & �������̵�
	// *** 10. ������ �����ε�
	// *** 11. ������ (����)
	// ���̹�
	// ���� ������ ����� ���ÿ� �����ؾ���
	// ������ �ٽ� ����� �ű⼭ �� ���� ���� ����°� �ƴ϶� ������ �ϴ°� �� �ڱ� �ڽſ��� ����
	// ������ �����κ� �����
*/

// namespace
/*
namespace AAA
{
	void Output()
	{
		cout << "ȫ�浿" << endl;
	}
}

using  AAA::Output;

namespace BBB
{
	void Output()
	{
		cout << "�Ӳ���" << endl;
	}
}

int main(void)
{
	Output();
	BBB::Output();

	return 0;
)
*/

// void Parent1::Output() // ���ӽ����̽��� �����ϸ� ��밡��
// ������
// �������� -> �ҽ����� �����ϵ��� 
// ���� �ϳ��� cpp h�� �ְ�  

// ���
/*
// ����! �����Ͱ� �θ� Ŭ������ ������ �ڽ�Ŭ������ ������ָ�\
���� ����ȯ(ĳ��Ʈ)�� �� ������ �θ� Ŭ������ ������ ��������ִ��� Ȯ���Ұ�!
// �Ʒ��� ���� ����� ����ϴ� ���� ���� �̻����̴�.\
�θ� Ŭ���������� ���� ���� ��� ���ϰ� �ڽ� Ŭ�������� �ʱ�ȭ�� ���ִ� ����
*/
// ��� �ڵ�
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

// [main ���]
	BBB b;
	b.initlalize();
	b.Output();
	// ((AAA)b).Output();

	CCC c;
	c.initlalize();
	c.Output();
*/

// �ڵ�
/*
#include "Parent.h"
#include "Child.h"
#include "Bullet.h"

// const�̱� ������ ��¥�� ������ �������κ����� ������
// �Ʒ� ���� �������� ������
const int ID_Child = 0;
const int ID_Bullet = 1;

int main(void)
{
	// ���°� �θ��̱� ������ 0�� �켱������ ��µ�
	// Parent* p;
	// p->Initialize();
	// p->Output();

	// �߻�ȭ
	
	// Child c;
	// c.Initialize();
	// c.Output();

	// Bullet b;
	// b.Initialize();
	// b.Output();

	// ������
Parent* p[2];  //  ������ �ö󰡸� ���´� ����� �ٲ���� ���� ���α׷� �ٽ� ¥����

p[ID_Child] = new Child;  //  �����̱� ������ ������ �ö󰡵� �ٲܼ� ����
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

// ����� ����
/*
// �̱��� ���� : ��ü�� �ν��Ͻ��� ���� 1���� �����Ǵ� ����
// ���α׷��� ��������� ���ÿ� ������ �ִ� ��쿡�� ���������� \
�� �����̳� �����Ϳ����� �ִ� �͵��� ���α׷��Ӱ� �������� ������ ������

// ������ ������ ����
// ��ǻ�͸� ���� ������ �����뿡�� ������ ���α׷��� �ǻ츱�� ����(������ �αװ� ���Ƽ� �װɷ� ����)��\
 ��ǻ�͸� �����ϰԵǸ� �����Ҽ� ����

// this �����ʹ� ��� �Լ��� ȣ��� ��ü�� �ּҸ� ����Ű�� ������ �����ʹ�.
*/



#pragma endregion



