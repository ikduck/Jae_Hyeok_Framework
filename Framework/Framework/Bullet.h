#pragma once
#include "Parent.h"

class Bullet : public Parent
{
public:
	void Initialize();
	virtual void Update();
	void Output();
	// int Get();
};

// ���� : ���ڵ帻��� �ǵ帮�� ����