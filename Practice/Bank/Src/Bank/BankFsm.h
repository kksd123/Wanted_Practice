#pragma once
#include "../Fsm/BcFsm.h"
#include "../Common/ClientType.h"

struct BankStateParam
{
	
};

class BankFsm : public BcFsm<BankStateType, BankStateParam>
{
public:
	BankFsm();
	void Update(float dt);
};

