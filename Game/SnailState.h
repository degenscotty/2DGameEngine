#pragma once
#include "State.h"

class EnemySnail;

class SnailState : public State
{
public:
	SnailState(EnemySnail* snail) : m_pEnemySnail(snail) {}
	~SnailState() = default;

	SnailState(const SnailState& other) = delete;
	SnailState(SnailState&& other) noexcept = delete;
	SnailState& operator=(const SnailState& other) = delete;
	SnailState& operator=(SnailState&& other) noexcept = delete;

	virtual void Update() = 0;
	virtual void Swap() = 0;
	virtual void OnEnter() = 0;
	virtual void OnExit() = 0;

protected:
	EnemySnail* m_pEnemySnail;
};

