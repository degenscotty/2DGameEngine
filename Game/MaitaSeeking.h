#pragma once
#include "GameObject.h"
#include "LevelManager.h"
#include "MaitaState.h"

class Maita;

class MaitaSeeking : public MaitaState
{
public:
	MaitaSeeking(Maita* pMaita);
	~MaitaSeeking() = default;

	MaitaSeeking(const MaitaSeeking& other) = delete;
	MaitaSeeking(MaitaSeeking&& other) noexcept = delete;
	MaitaSeeking& operator=(const MaitaSeeking& other) = delete;
	MaitaSeeking& operator=(MaitaSeeking&& other) noexcept = delete;

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

