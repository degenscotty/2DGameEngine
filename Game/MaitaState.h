#pragma once
#include "State.h"

class MaitaPlayer;

class MaitaState : public State
{
public:
	MaitaState(MaitaPlayer* pMaitaPlayer) : m_pMaitaPlayer(pMaitaPlayer) {}
	~MaitaState() = default;

	MaitaState(const MaitaState& other) = delete;
	MaitaState(MaitaState&& other) noexcept = delete;
	MaitaState& operator=(const MaitaState& other) = delete;
	MaitaState& operator=(MaitaState&& other) noexcept = delete;

	virtual void Update() = 0;
	virtual void OnEnter() = 0;
	virtual void OnExit() = 0;

protected:
	MaitaPlayer* m_pMaitaPlayer;
};

