#pragma once
#include "Headers.h"

class Object
{
protected:
	Transform TransInfo;
	string strKey;
public:
	virtual void Initialize()PURE;
	virtual int Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
	virtual Object Clone()PURE;

	// 키 값 반환
	string GetKey() const { return strKey; }

	// 좌표 반환 , 입력
	Vector3 GetPosition() const { return TransInfo.Position; }
	void SetPosition(float _x, float _y) { TransInfo.Position = Vector3(_x, _y); }
	void SetPosition(Vector3 _Position){ TransInfo.Position = _Position; }

	// 크기 반환 , 입력
	Vector3 GetSclae() const { return TransInfo.Scale; }
	void SetSclae(float _x, float _y) { TransInfo.Scale = Vector3(_x, _y); }

	Object();
	Object(Transform _TransInfo);
	virtual ~Object();
};

// L value -> 뭔가를 담을수 있는 것 , int i 
// R value -> 담을수 없는 것  , 120