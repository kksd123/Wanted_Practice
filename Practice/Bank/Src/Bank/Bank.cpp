#include "Bank.h"
//순환 Include 상황때문에 일단 여기로 빼긴했는데.. 수정방법 고민 필요
#include "BankFsm.h"
#include "CreditAccount.h"
#include "DonationAccount.h"

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

	m_engine->SetShutDownCallback([this]()
		{
			for (int i = 0; i < MAX_ACCOUNTS; ++i)
			{
				if (m_accounts[i] != nullptr)
				{
					m_accounts[i]->Serialize("Accounts.txt");
				}
				else
				{
					break;
				}
			}
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


bool Bank::CreateAccount(const char* name, AccountType type)
{
	for (int i = 0; i < MAX_ACCOUNTS; ++i)
	{
		if (m_accounts[i] == nullptr)
		{
			switch (type)
			{
			case eNormal:
				m_accounts[i] = new Account(i + 312, name, 0);
				break;
			case eCredit:
				m_accounts[i] = new CreditAccount();
				m_accounts[i]->SetAccount(i + 312, name, 0);
				break;
			case eDonation:
				m_accounts[i] = new DonationAccount();
				m_accounts[i]->SetAccount(i + 312, name, 0);
				break;
			default:
				return false;
				break;
			}

			//m_accounts[i + 1] = new Account(m_accounts[i]);
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

		if(dynamic_cast<DonationAccount*>(m_accounts[i]) != nullptr)
		{
			DonationAccount* donAcc = dynamic_cast<DonationAccount*>(m_accounts[i]);
			std::cout << "기부금액:" << donAcc->GetDonationAmount() << std::endl;
		}
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


void Bank::Deserialize(const char* path)
{
	FILE* file = nullptr;
	errno_t error = fopen_s(&file, path, "rt");

	// 예외처리.
	if (!file)
	{
		std::cout << "Failed to open file.\n";
		__debugbreak();
		return;
	}

	Read(file);

	fclose(file);
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
