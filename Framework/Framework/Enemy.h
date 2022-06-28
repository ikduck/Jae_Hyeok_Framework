#pragma once
#include "Object.h"

class Enemy : public Object
{
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

	 // virtual Enemy Clone()override;
	 // {
	 // 	return new Object(*this);
	 // }

	Enemy();
	Enemy(Transform _TransInfo);
	virtual ~Enemy();
};
