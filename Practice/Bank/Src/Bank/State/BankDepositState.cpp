#include "BankDepositState.h"

BankStateType BankDepositState::GetState() const
{
    return BankStateType::Deposit;
}

void BankDepositState::Enter(const BankStateParam*)
{
}

void BankDepositState::Step(float dt)
{
}

void BankDepositState::Leave(BankStateType type)
{
}
