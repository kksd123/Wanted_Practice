#pragma once
#include "BankStateBase.h"
#include <chrono> // 시간 처리를 위해

class BankCAState : public BankStateBase<BankStateType, BankStateParam>
{
public:
	BankCAState(BankFsm* fsm)
		:BankStateBase(fsm)
	{
	}

	BankStateType GetState() const override;
	void Enter(const BankStateParam*) override;
	void Step(float dt) override;
	void Leave(BankStateType type) override;
};

