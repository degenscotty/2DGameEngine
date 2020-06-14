#pragma once
#include "GameObject.h"
#include "LevelManager.h"
#include "MaitaStateAI.h"

class Maita;

class MaitaSeekingAI : public MaitaStateAI
{
public:
	MaitaSeekingAI(Maita* pMaita);
	~MaitaSeekingAI() = default;

	MaitaSeekingAI(const MaitaSeekingAI& other) = delete;
	MaitaSeekingAI(MaitaSeekingAI&& other) noexcept = delete;
	MaitaSeekingAI& operator=(const MaitaSeekingAI& other) = delete;
	MaitaSeekingAI& operator=(MaitaSeekingAI&& other) noexcept = delete;

	void Update() override;
	void OnEnter() override;
	void OnExit() override;

	void GetBobblePosition();

private:
	LevelManager* m_pLevelManager;
	
	GameObject* m_pBobblePlayer;

	glm::vec2 m_MaitaPosition;
	glm::vec2 m_BobblePosition;
};

