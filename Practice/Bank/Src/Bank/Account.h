#pragma once
#include <string.h>

class Account
{
public:
	Account() = default;
	~Account();

	void SetAccount(int _id, const char* _name, int _balance);

	int GetId() { return m_id; };
	const char* GetName() { return m_name; };
	int GetBalance() { return m_balance; };
	int SetBalance(int _val);

private:
	int m_id = 0;
	char* m_name = nullptr;
	int m_balance = 0;
};