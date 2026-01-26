#include "DonationAccount.h"

int DonationAccount::SetBalance(int _val)
{
	if (_val > 0)
	{
		AddDonationAmount(_val / 100); //1% ±âºÎ
	}
	
	return Account::SetBalance(_val);
}

void DonationAccount::SetAccount(int _id, const char* _name, int _balance)
{
	Account::SetAccount(_id, _name, _balance);
	m_donationAmount = 0;
}
