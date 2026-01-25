#include "BankInquireState.h"

BankStateType BankInquireState::GetState() const
{
	return BankStateType::Inquire;
}

void BankInquireState::Enter(const BankStateParam*)
{
	std::cout << "전체 계좌 잔액 조회" << std::endl;

	Bank* bank = GetFsm()->GetBank();

	bank->Inquire();

	std::cout << "BackSpace클릭시 메뉴로 이동합니다.\n";
}

void BankInquireState::Step(float dt)
{
	if (GetEngine().GetKeyDown(VK_BACK))
	{
		GetFsm()->ChangeState(BankStateType::Idle, nullptr);
	}
}

void BankInquireState::Leave(BankStateType type)
{
	BankStateBase::Leave(type);
}
