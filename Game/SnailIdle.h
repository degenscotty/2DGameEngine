#pragma once
#include "SnailState.h"

class EnemySnail;

class SnailIdle : public SnailState
{
public:
	SnailIdle(EnemySnail* snail);
	~SnailIdle() = default;

	SnailIdle(const SnailIdle& other) = delete;
	SnailIdle(SnailIdle&& other) noexcept = delete;
	SnailIdle& operator=(const SnailIdle& other) = delete;
	SnailIdle& operator=(SnailIdle&& other) noexcept = delete;

	void Update() override;
	void Swap() override;
	void OnEnter() override;
	void OnExit() override;
private:
	
};

