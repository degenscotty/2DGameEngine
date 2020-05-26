#pragma once
#include "State.h"

class EnemyMaita;

class MaitaState : public State
{
public:
	MaitaState(EnemyMaita* snail) : m_pEnemyMaita(snail) {}
	~MaitaState() = default;

	MaitaState(const MaitaState& other) = delete;
	MaitaState(MaitaState&& other) noexcept = delete;
	MaitaState& operator=(const MaitaState& other) = delete;
	MaitaState& operator=(MaitaState&& other) noexcept = delete;

	virtual void Update() = 0;
	virtual void Swap() = 0;
	virtual void OnEnter() = 0;
	virtual void OnExit() = 0;

protected:
	EnemyMaita* m_pEnemyMaita;
};

