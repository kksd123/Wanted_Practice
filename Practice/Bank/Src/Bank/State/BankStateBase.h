#pragma once
#include "../BankFsm.h"
#include "../../Fsm/FsmState.h"
//템플릿 클래스라 헤더구현 하라고함
//템플릿은 컴파일 시점에 인스턴스화되기 때문
template<typename StateType, typename StateParam>
class BankStateBase : public FsmState<StateType, StateParam>
{
public:
	explicit BankStateBase(BankFsm* fsm)
		: m_fsm(fsm)
	{}

protected:
	BankFsm* m_fsm;
};

