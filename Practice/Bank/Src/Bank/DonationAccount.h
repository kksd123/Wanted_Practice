#pragma once
#include "Account.h"
class DonationAccount:public Account
{
public:
	int SetBalance(int _val) override;
	inline int GetDonationAmount() { return m_donationAmount; }
	void AddDonationAmount(int val) { m_donationAmount += val; }
	void SetAccount(int _id, const char* _name, int _balance) override;
private:
	int m_donationAmount = 0;
};

