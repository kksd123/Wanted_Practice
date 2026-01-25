#pragma once

class Account;

class Bank
{
	Bank();
	~Bank();

	void StartBank();

private:
	Account* m_accounts[100];
};