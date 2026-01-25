#pragma once
#include <cassert> //에러일때 멈추는 Assert 관련 C++ 라이브러리(라고함)
#include <unordered_map> //Dictionary<TKey, TValue> 쓰려고
#include "FsmState.h"

template<typename T>
struct EnumHash //Hash 명시적으로 제공
{
	static_assert(std::is_enum_v<T>); //enum 강제
	//size_t : 8바이트 부호없는 정수 타입 
	//operator() : 함수호출 연산자 오버로딩 이 구조체를 함수처럼 사용할 수 있게 해줌
	//const 구조체 내부값 수정 안한다는 약속
	//noexcept 이 함수는 에러 안던진다는 약속
	size_t operator()(T t) const noexcept 
	{
		//staic_cast: 현재들어오는 (t) enum이 오는걸 size_t 로 바꿔서 줌 
		return static_cast<size_t>(t);
	}
};

template<typename StateType, typename StateParam>//자료형 이름들 선언
class BcFsm
{
	using StateBase = FsmState<StateType, StateParam>;

protected:
	virtual ~BcFsm()
	{
		for (auto& state : m_states)
			delete state.second;
	}

public:
	// 상태 저장
	void AddState(StateBase* state)
	{
		auto key = state->GetState();
		assert(m_states.find(key) == m_states.end());
		m_states[key] = state;
	}

	// 상태 변경
	void ChangeState(StateType next, const StateParam* param)
	{
		if (m_current)
			m_current->Leave(next);

		StateType prev = m_current ? m_current->GetState() : next;
		m_current = m_states.at(next); //[] 쓰려했더니 map은 Key가 없으면 멋대로 만든대서 at으로.. Unreal이면 TMap써야..

		m_current->WillEnter(param, prev);
		m_current->Enter(param);
	}

	void Step(float dt) // 엔진수업때 배운 deltaTime을 적용하려함
	{
		if (m_current)
			m_current->Step(dt);
	}

	// 오브젝트 물리 처리하려면 고정된 처리가 필요해서 넣는건데 이번엔 안씀
	void FixedStep(float fdt)
	{
		if (m_current)
			m_current->FixedStep(fdt);
	}

protected:
	std::unordered_map<StateType, StateBase*, EnumHash<StateType>> m_states; //C# Dictionary<TKey, TValue>랑 같은 기능 찾았더니 unordered_map이라고 해서 이거 사용
	StateBase* m_current = nullptr;
};