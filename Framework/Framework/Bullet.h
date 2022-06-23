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

// 조언 : 내코드말고는 건드리지 말자