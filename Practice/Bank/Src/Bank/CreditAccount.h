#pragma once
#include "Account.h"

class CreditAccount :public Account
{
	int SetBalance(int _val) override;
};

