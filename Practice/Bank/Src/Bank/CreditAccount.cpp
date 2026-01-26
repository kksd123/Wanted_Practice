#include "CreditAccount.h"

int CreditAccount::SetBalance(int _val)
{
	if (_val > 0)
	{
		int allBal = m_balance + _val;
		int interest = allBal * 0.01f; //1% 이자

		//넣는 값 + 넣었을때 나오는 총값에 대한 1% 이자
		_val += interest;
	}

	return Account::SetBalance(_val);
}
