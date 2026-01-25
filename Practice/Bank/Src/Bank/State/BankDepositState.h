#pragma once

#include "BankStateBase.h"
class BankDepositState : public BankStateBase<BankStateType, BankStateParam>
{
public:
	BankDepositState(BankFsm* fsm)
		:BankStateBase(fsm)
	{
	}

	BankStateType GetState() const override;
	void Enter(const BankStateParam*) override;
	void Step(float dt) override;
	void Leave(BankStateType type) override;
};

