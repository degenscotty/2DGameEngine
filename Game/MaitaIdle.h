#pragma once
#include "MaitaState.h"

class EnemyMaita;

class MaitaIdle : public MaitaState
{
public:
	MaitaIdle(EnemyMaita* snail);
	~MaitaIdle() = default;

	MaitaIdle(const MaitaIdle& other) = delete;
	MaitaIdle(MaitaIdle&& other) noexcept = delete;
	MaitaIdle& operator=(const MaitaIdle& other) = delete;
	MaitaIdle& operator=(MaitaIdle&& other) noexcept = delete;

	void Update() override;
	void Swap() override;
	void OnEnter() override;
	void OnExit() override;
private:
	
};

