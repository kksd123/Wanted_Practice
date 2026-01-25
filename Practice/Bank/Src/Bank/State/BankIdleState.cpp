#include "BankIdleState.h"

BankStateType BankIdleState::GetState() const
{
	return BankStateType::Idle;
}

void BankIdleState::Enter(const BankStateParam*)
{
	std::cout << "WantedBank" << std::endl;
	std::cout << "1.°èÁÂ °³¼³" << std::endl;
	std::cout << "2.ÀÔ±Ý" << std::endl;
	std::cout << "3.Ãâ±Ý" << std::endl;
	std::cout << "4.ÀüÃ¼ °í°´ ÀÜ¾× Á¶È¸" << std::endl;
}

void BankIdleState::Step(float dt)
{
	auto& engine = GetEngine();

	if (engine.GetKeyDown('1'))
	{
		GetFsm()->ChangeState(BankStateType::CreateAccount, nullptr);
		return;
	}

	if (engine.GetKeyDown('2'))
	{
		GetFsm()->ChangeState(BankStateType::Deposit, nullptr);
		return;
	}

	if (engine.GetKeyDown('3'))
	{
		GetFsm()->ChangeState(BankStateType::Withdraw, nullptr);
		return;
	}

	if (engine.GetKeyDown('4'))
	{
		GetFsm()->ChangeState(BankStateType::Inquire, nullptr);
		return;
	}
}

void BankIdleState::Leave(BankStateType type)
{
	BankStateBase::Leave(type);
}
