#pragma once
template<typename StateType, typename StateParam>
class FsmState
{
public: 
	virtual ~FsmState() = default;


	virtual StateType GetState() const = 0;

	virtual void Step(float dt) {}
	virtual void FixedStep(float fdt) {}
	virtual void WillEnter(const StateParam*, StateType prev) {}
	virtual void Enter(const StateParam*) {}
	virtual void Leave(StateType) {}
};