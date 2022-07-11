#pragma once
#include "BulletBridge.h"

class Enemy1 : public BulletBridge
{
public:
	virtual void Initialize()override;
	virtual int Update(Transform& Info)override;
	virtual void Render()override;
	virtual void Release()override;

	Enemy1();
	virtual ~Enemy1();
};