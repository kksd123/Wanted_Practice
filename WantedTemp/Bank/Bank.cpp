#include "Bank.h"

Bank::Bank()
{
	m_accounts = nullptr;
}

Bank::~Bank()
{
	delete m_accounts;
	m_accounts = nullptr;
}
