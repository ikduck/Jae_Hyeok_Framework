#pragma once
#include "Headers.h"

class Object;
class Bridge
{
protected:
	Object* pObject;
public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& Info)PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;

	void SetObject(Object* _Object) { pObject = _Object; }

	Bridge() : pObject(nullptr) {}
	virtual ~Bridge() {}
};