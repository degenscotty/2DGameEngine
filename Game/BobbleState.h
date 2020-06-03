#pragma once
#include "State.h"

class BobblePlayer;

class BobbleState : public State
{
public:
	BobbleState(BobblePlayer* player) : m_pBobblePlayer(player) {}
	~BobbleState() = default;

	BobbleState(const BobbleState& other) = delete;
	BobbleState(BobbleState&& other) noexcept = delete;
	BobbleState& operator=(const BobbleState& other) = delete;
	BobbleState& operator=(BobbleState&& other) noexcept = delete;

	virtual void Update() = 0;
	virtual void OnEnter() = 0;
	virtual void OnExit() = 0;

protected:
	BobblePlayer* m_pBobblePlayer;
};