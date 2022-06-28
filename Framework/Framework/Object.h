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

	// Ű �� ��ȯ
	string GetKey() const { return strKey; }

	// ��ǥ ��ȯ , �Է�
	Vector3 GetPosition() const { return TransInfo.Position; }
	void SetPosition(float _x, float _y) { TransInfo.Position = Vector3(_x, _y); }
	void SetPosition(Vector3 _Position){ TransInfo.Position = _Position; }

	// ũ�� ��ȯ , �Է�
	Vector3 GetSclae() const { return TransInfo.Scale; }
	void SetSclae(float _x, float _y) { TransInfo.Scale = Vector3(_x, _y); }

	Object();
	Object(Transform _TransInfo);
	virtual ~Object();
};

// L value -> ������ ������ �ִ� �� , int i 
// R value -> ������ ���� ��  , 120