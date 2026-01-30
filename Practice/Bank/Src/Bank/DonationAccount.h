#pragma once
#include "Account.h"
class DonationAccount:public Account
{
public:
	int SetBalance(int _val) override;
	inline int GetDonationAmount() { return m_donationAmount; }
	void AddDonationAmount(int val) { m_donationAmount += val; }
	void SetAccount(int _id, const char* _name, int _balance) override;
	AccountType GetAccountType() override 
	{ return AccountType::eDonation; };
	const char* GetFileIOFormat() override
	{ return "AccountType=%d m_id=%d m_name=%s m_balacne=%d m_donationAmount=%d"; };
	void Read(FILE* file) override ;
	void Write(FILE* file) override;

private:
	int m_donationAmount = 0;
};

