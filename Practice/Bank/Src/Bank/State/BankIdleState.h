#pragma once

#include "BankStateBase.h"

class BankIdleState : public BankStateBase<BankStateType, BankStateParam>
{
public:
	BankIdleState(BankFsm* fsm)
		:BankStateBase(fsm)
	{}

	BankStateType GetState() const override;
	void Enter(const BankStateParam*) override;
	void Step(float dt) override;
	void Leave(BankStateType type) override;
};

