#include "BankCAState.h"

BankStateType BankCAState::GetState() const
{
	return BankStateType::CreateAccount;
}

void BankCAState::Enter(const BankStateParam*)
{
	std::cout << "이름을 입력해 주세요" << std::endl;

	char name[100] = {};
	std::cin >> name;

	std::cout << "만들 계좌 종류를 입력해 주세요" << std::endl;
	std::cout << "1 : 일반" << std::endl;
	std::cout << "2 : 신용" << std::endl;
	std::cout << "3 : 기부" << std::endl;
	int choose = 0;
	std::cin >> choose;

	if (choose > AccountType::None && choose < AccountType::Max)
	{
		Bank* bank = GetFsm()->GetBank();
		bank->CreateAccount(name, static_cast<AccountType>(choose));
	}

	m_waiting = true;
	m_elapsed = 0.0f;

	std::cout << "2초후 또는 BackSpace클릭시 메뉴로 이동합니다.\n";
}

void BankCAState::Step(float dt)
{
	if (m_waiting == false)
		return;

	float clampedDt = dt > 0.1f ? 0.1f : dt;

	m_elapsed += clampedDt;

	if (m_elapsed >= 2.0f || GetEngine().GetKeyDown(VK_BACK))
	{
		m_waiting = false;
		GetFsm()->ChangeState(BankStateType::Idle, nullptr);
	}
}

void BankCAState::Leave(BankStateType type)
{
	BankStateBase::Leave(type);
}
