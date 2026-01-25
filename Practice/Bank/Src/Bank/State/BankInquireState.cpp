#include "BankInquireState.h"

BankStateType BankInquireState::GetState() const
{
	return BankStateType::Inquire;
}

void BankInquireState::Enter(const BankStateParam*)
{
}

void BankInquireState::Step(float dt)
{
}

void BankInquireState::Leave(BankStateType type)
{
}
