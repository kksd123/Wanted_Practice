#include "BankWithdrawState.h"

BankStateType BankWithdrawState::GetState() const
{
	return BankStateType::Withdraw;
}

void BankWithdrawState::Enter(const BankStateParam*)
{
    std::cout << "계좌번호를 입력해 주세요" << std::endl;
    int id = 0;
    std::cin >> id;

    Bank* bank = GetFsm()->GetBank();

    if (bank->IsValidAccount(id))
    {
        std::cout << "출금 금액을 입력해주세요" << std::endl;
        int balance;
        std::cin >> balance;
        bank->Withdraw(id, balance);
    }
    else
    {
        std::cout << "계좌번호가 없습니다!" << std::endl;
    }

    std::cout << "BackSpace클릭시 메뉴로 이동합니다.\n";
}

void BankWithdrawState::Step(float dt)
{
    if (GetEngine().GetKeyDown(VK_BACK))
    {
        GetFsm()->ChangeState(BankStateType::Idle, nullptr);
    }
}

void BankWithdrawState::Leave(BankStateType type)
{
    BankStateBase::Leave(type);
}
