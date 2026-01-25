#include "BankWithdrawState.h"

BankStateType BankWithdrawState::GetState() const
{
	return BankStateType::Withdraw;
}

void BankWithdrawState::Enter(const BankStateParam*)
{
}

void BankWithdrawState::Step(float dt)
{
}

void BankWithdrawState::Leave(BankStateType type)
{
}
