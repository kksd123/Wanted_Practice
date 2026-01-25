#include "BankIdleState.h"

BankStateType BankIdleState::GetState() const
{
	return BankStateType::Idle;
}

void BankIdleState::Enter(const BankStateParam*)
{
}

void BankIdleState::Step(float dt)
{
}

void BankIdleState::Leave(BankStateType type)
{
}
