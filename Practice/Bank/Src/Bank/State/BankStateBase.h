#pragma once
#include "../BankFsm.h"
#include "../../Fsm/FsmState.h"
#include <iostream>
#include <Windows.h>

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
	BankFsm* GetFsm() const { return m_fsm; }

	void Step(float dt) override;

	Wanted::Engine& GetEngine() const
	{
		return m_fsm->GetBank()->GetEngine();
	}

	void Leave(StateType) override
	{
		system("cls");
	};

protected:
	bool m_waiting = false;
	float m_elapsed = 0.0f;

private:
	BankFsm* m_fsm;
};

template<typename StateType, typename StateParam>
inline void BankStateBase<StateType, StateParam>::Step(float dt)
{
	Wanted::Engine& engine = GetEngine();

	if (engine.GetKeyDown('Q'))
		engine.QuitEngine();
}
