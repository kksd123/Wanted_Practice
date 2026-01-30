#pragma once
#include "../Engine/Engine.h"
#include "Account.h"
#include <iostream>

class BankFsm;
enum AccountType;

#define MAX_ACCOUNTS 100
class Bank
{
public:
	Bank();
	~Bank();

	void StartBank();
	void Update(float dt);
	bool IsValidAccount(int id);
	bool CreateAccount(const char* name, AccountType type);
	void Deposit(int id, unsigned int val);
	void Withdraw(int id, int val);
	void Inquire();

	Wanted::Engine& GetEngine();
	BankFsm& GetFsm();

private:
	void Read(FILE* file);
	void Deserialize(const char* path);
	Account* FindAccount(int id);

private:
	Account* m_accounts[MAX_ACCOUNTS] = {};
	Wanted::Engine* m_engine;
	BankFsm* m_fsm;
};