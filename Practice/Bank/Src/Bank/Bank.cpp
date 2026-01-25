#include "Bank.h"
//순환 Include 상황때문에 일단 여기로 빼긴했는데.. 수정방법 고민 필요
#include "BankFsm.h"

Bank::Bank()
{
	for (auto& acc : m_accounts)
		acc = nullptr;

	m_engine = new Wanted::Engine();
	m_fsm = new BankFsm(this);

	// 이게 더 나을거같긴함
	// std::fill(std::begin(m_accounts), std::end(m_accounts), nullptr); 
}

Bank::~Bank()
{
	delete m_fsm;
	delete m_engine;
}

void Bank::StartBank()
{
	m_fsm->Start();

	m_engine->SetTickCallback([this](float dt)
		{
			Update(dt);
		});

	m_engine->Run();
}

void Bank::Update(float dt)
{
	m_fsm->Update(dt);
}

bool Bank::IsValidAccount(int id)
{
	for (Account* acc : m_accounts)
	{
		if (acc != nullptr)
		{
			if (acc->GetId() == id)
			{
				return true;
			}
		}
	}

	return false;
}


bool Bank::CreateAccount(const char* name)
{
	for (int i = 0; i < MAX_ACCOUNTS; ++i)
	{
		if (m_accounts[i] == nullptr)
		{
			m_accounts[i] = new Account();
			m_accounts[i]->SetAccount(i + 312, name, 0);
			std::cout << "계좌가 추가되었습니다." << std::endl;
			std::cout << "계좌번호 : " << m_accounts[i]->GetId() << std::endl;
			std::cout << "이    름 : " << m_accounts[i]->GetName() << std::endl;

			return true;
		}
	}

	std::cout << "계좌를 추가할 공간이 없습니다!" << std::endl;

	return false;
}

void Bank::Deposit(int id, unsigned int val)
{
	Account* acc = FindAccount(id);

	int curBalance = acc->SetBalance(val);

	std::cout << "현재잔액 : " << curBalance << std::endl;
}

void Bank::Withdraw(int id, int val)
{
	Account* acc = FindAccount(id);

	int absVal = abs(val);
	int curBalance = acc->SetBalance(-absVal);

	if (curBalance == -1)
	{
		std::cout << "잔액이 부족합니다" << curBalance << std::endl;
		std::cout << "현재잔액 : " << acc->GetBalance() << std::endl;
		std::cout << "요청금액 : " << absVal << std::endl;
	}
	else
	{
		std::cout << "현재잔액 : " << curBalance << std::endl;
	}
}

void Bank::Inquire()
{
	for (int i = 0; i < MAX_ACCOUNTS; ++i)
	{
		if (m_accounts[i] == nullptr)
			continue;

		std::cout << "이   름:" << m_accounts[i]->GetName() << std::endl;
		std::cout << "잔   액:" << m_accounts[i]->GetBalance() << std::endl;
	}
}


Wanted::Engine& Bank::GetEngine()
{
	return *m_engine;
}

BankFsm& Bank::GetFsm()
{
	return *m_fsm;
}

Account* Bank::FindAccount(int id)
{
	for (int i = 0; i < MAX_ACCOUNTS; ++i)
	{
		if (m_accounts[i] != nullptr)
		{
			if (m_accounts[i]->GetId() == id)
			{
				return m_accounts[i];
			}
		}
	}
	return nullptr;
}
