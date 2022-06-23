// *** Framework_v1.0
#define _CRT_SECURE_NO_WARNINGS
#include "Headers.h"
#include "MainUpdate.h"
// #include <time.h> // 1�ʴ����� ������

// roop �� ���� ���� (����Ǵ� ������ �����Ǿ��ִ�.)

// *** �̱���(Singleton)
/*
	1. ��ҿ� ���־��� �� ������ �����ְ� ��������
	2. �̱����� �������� �������� ����ϱ� ������ �����ʹ� �ѱ������� �־����

	so! �̱����� �ϳ��� �������ϱ� ������ �����ڸ� private�� ����
*/

// �̱������� ����ϱ�
/*
class Singleton // �����ڷ� �����
{
private:
	// static ��������
	// ������ ������ �ݴ�Ǵ� ������ �ƴ϶� ���δٸ� �����
	static Singleton* Instance;
public:
	static Singleton* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new Singleton; // Instance = new Singleton();�� ���������� c������ �����ص� ()�ڵ����� �߰����� 
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
	// �̱������� �����
	/*
	Singleton::GetInstance()->SetNumber(10);
	cout << Singleton::GetInstance()->GetNumber() << endl;
	*/
	// Ÿ�̸�
	/*
	// ���ſ� ����ϴ� ���(32��Ʈ) 
	//DWORD dwTime = GetTickCount();

	// ����ð��� ��ȯ�ϴ� �Լ�
	// 1/1000 ���α׷��� ������ ����� �� ���� �׷��� ���� ������ �ϴ°��� �ִ��� 2~3��������. 
	// GetTickCount() �뷫 49��
	// GetTickCount64() 5���? ������ũ ���� 5��� �������?
	// 0���� �����ϴ°� �ƴ϶�  GetTickCount64()���� Time�� �־��� (cpu���� �ð�) 
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
	 	// ������ ����
	 	// 1�ʸ��� �ٲ�� �ϰ������ + 999�� �ٲ��ָ��
	 	if (Time + 50 < GetTickCount64())
	 	{
	 		Time = GetTickCount64();
	 
	 		// ���������� ����
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
	// Main.Release(); //�� ���Ⱑ�ƴ� �Ҹ��ڿ� �ۼ���
	*/


	return 0;
}

// ���ӽ����̽� : ���� �ĺ���