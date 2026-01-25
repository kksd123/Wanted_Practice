#pragma once
#include "../Engine/Engine.h"
#include "Account.h"
#include <iostream>

class BankFsm;

#define MAX_ACCOUNTS 100
class Bank
{
public:
	Bank();
	~Bank();

	void StartBank();
	void Update(float dt);
	bool IsValidAccount(int id);
	bool CreateAccount(const char* name);
	void Deposit(int id, unsigned int val);
	void Withdraw(int id, int val);
	void Inquire();

	Wanted::Engine& GetEngine();
	BankFsm& GetFsm();

private:
	Account* FindAccount(int id);

private:
	Account* m_accounts[MAX_ACCOUNTS] = {};
	Wanted::Engine* m_engine;
	BankFsm* m_fsm;
};