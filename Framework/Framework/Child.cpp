#include "Child.h"

void Child::Initialize()
{
	m_Number = 100;
}

void Child::Update()
{
	m_Number += 100;
}

void Child::Output()
{
	 cout << m_Number << endl;
}

// int Child::Get()
// {
// 	return 0;
// }
