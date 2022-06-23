#pragma once
#include "Parent.h"

class Child : public Parent
{
protected:
public:
	virtual void Initialize();
	virtual void Update();
	virtual void Output();
	// int Get() ;

};
