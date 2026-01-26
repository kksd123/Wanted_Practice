#pragma once
#include "../Fsm/BcFsm.h"
#include "../Common/ClientType.h"
#include "Bank.h"

class Bank;
struct BankStateParam
{
	
};

class BankFsm : public BcFsm<BankStateType, BankStateParam>
{
public:
	BankFsm(Bank* bank);
	inline Bank* GetBank() const { return m_bank; }

	void Start();
	void Update(float dt);

private:
	Bank* m_bank;
};

