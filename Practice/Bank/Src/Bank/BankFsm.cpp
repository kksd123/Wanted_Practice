#include "BankFsm.h"
#include "BankStates.h"

BankFsm::BankFsm()
{
	AddState(new BankIdleState(this));
	AddState(new BankCAState(this));
	AddState(new BankDepositState(this));
	AddState(new BankWithdrawState(this));
	AddState(new BankInquireState(this));
}

void BankFsm::Update(float dt)
{
}
