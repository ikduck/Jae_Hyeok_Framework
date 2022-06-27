#pragma once
#include "Headers.h"

class Object
{
protected:
	Transform TransInfo;
	string strKey;
public:
	virtual void Initialize()PURE;
	virtual void Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
	virtual Object* Clone()PURE;

	string GetKey() const { return strKey; }

	Object();
	Object(Transform _Info);
	virtual ~Object();
};

