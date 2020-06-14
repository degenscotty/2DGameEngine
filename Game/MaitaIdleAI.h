#pragma once
#include "GameTime.h"
#include "MaitaStateAI.h"

class Maita;

class MaitaIdleAI : public MaitaStateAI
{
public:
	MaitaIdleAI(Maita* pMaita);
	~MaitaIdleAI() = default;

	MaitaIdleAI(const MaitaIdleAI& other) = delete;
	MaitaIdleAI(MaitaIdleAI&& other) noexcept = delete;
	MaitaIdleAI& operator=(const MaitaIdleAI& other) = delete;
	MaitaIdleAI& operator=(MaitaIdleAI&& other) noexcept = delete;

	void Update() override;
	void OnEnter() override;
	void OnExit() override;
	
private:
	GameTime* m_pGameTime;

	float m_SpawnTimer;
	float m_TimeToSeek;
};

