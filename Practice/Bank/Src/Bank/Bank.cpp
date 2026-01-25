#include "Bank.h"

Bank::Bank()
{
	for (int i = 0; i < 100; ++i)
	{
		m_accounts[i] = nullptr;
	}

	// 이게 더 나을거같긴함
	// std::fill(std::begin(m_accounts), std::end(m_accounts), nullptr); 
}

Bank::~Bank()
{
}
