#pragma once
#include "../Common/ClientType.h"
#include <iostream>


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
	virtual AccountType GetAccountType() { return AccountType::eNormal; };
	virtual const char* GetFileIOFormat() {
		return "AccountType=%d m_id=%d m_name=%s m_balacne=%d";
	}

	void Serialize(const char* path);

protected:
	virtual void Read(FILE* file);
	virtual void Write(FILE* file);

protected:
	int m_id = 0;
	char* m_name = nullptr;
	int m_balance = 0;
};