#include "BankFsm.h"
#include "BankStates.h"

BankFsm::BankFsm(Bank* bank)
	:m_bank(bank)
{
	AddState(new BankIdleState(this));
	AddState(new BankCAState(this));
	AddState(new BankDepositState(this));
	AddState(new BankWithdrawState(this));
	AddState(new BankInquireState(this));
}

void BankFsm::Start()
{
	ChangeState(BankStateType::Idle, nullptr);
}

void BankFsm::Update(float dt)
{
	Step(dt);
}
