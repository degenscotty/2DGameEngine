#pragma once
#include "GameTime.h"
#include "MaitaState.h"

class Maita;

class MaitaIdle : public MaitaState
{
public:
	MaitaIdle(Maita* pMaita);
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
	GameTime* m_pGameTime;

	float m_SpawnTimer;
	float m_TimeToSeek;
};

