#include "Account.h"

Account::Account(const Account& account)
	:m_id(account.m_id), m_name(account.m_name), m_balance(account.m_balance)
{
}

Account::Account(int _id, const char* _name, int _balance)
{
	SetAccount(_id, _name, _balance);
}

Account::~Account()
{
	if (m_name != nullptr)
	{
		delete[] m_name;
		m_name = nullptr;
	}
}

void Account::SetAccount(int _id, const char* _name, int _balance)
{
	m_id = _id;
	m_balance = _balance;

	if (m_name != nullptr)
	{
		delete[] m_name;
	}

	int len = strlen(_name) + 1;
	m_name = new char[len];

	strcpy_s(m_name, len, _name);
}

int Account::SetBalance(int _val)
{
	int result = m_balance + _val;

	if (result < 0)
	{
		//Error
		return -1;
	}

	m_balance = result;

	return m_balance;
}
