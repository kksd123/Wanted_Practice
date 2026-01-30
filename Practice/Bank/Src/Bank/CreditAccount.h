#pragma once
#include "Account.h"

class CreditAccount :public Account
{
public:
	int SetBalance(int _val) override;
	AccountType GetAccountType() override
	{
		return AccountType::eCredit;
	};
};

