#include "BankCAState.h"

BankStateType BankCAState::GetState() const
{
	return BankStateType::CreateAccount;
}

void BankCAState::Enter(const BankStateParam*)
{
}

void BankCAState::Step(float dt)
{
}

void BankCAState::Leave(BankStateType type)
{
}
