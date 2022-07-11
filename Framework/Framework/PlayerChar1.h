#pragma once
#include "PlayerBridge.h"

class PlayerChar1 : public PlayerBridge
{
public:
	virtual void Initialize()override;
	virtual int Update(Transform& Info)override;
	virtual void Render()override;
	virtual void Release()override;

	PlayerChar1();
	virtual ~PlayerChar1();
};

