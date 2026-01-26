#pragma once
#include <string.h>

class Account
{
public:
	Account() = default;
	Account(int _id, const char* _name, int _balance);
	Account(const Account& account);
	virtual ~Account();
	virtual void SetAccount(int _id, const char* _name, int _balance);

public:
	inline int GetId() { return m_id; };
	inline const char* GetName() { return m_name; };
	inline int GetBalance() { return m_balance; };
	virtual int SetBalance(int _val);

protected:
	int m_id = 0;
	char* m_name = nullptr;
	int m_balance = 0;
};