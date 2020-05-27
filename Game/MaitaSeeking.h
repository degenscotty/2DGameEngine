#pragma once
#include "GameObject.h"
#include "MaitaState.h"
#include "utils.h"

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
	void Swap() override;
	void OnEnter() override;
	void OnExit() override;

	void GetBobblePosition();

private:
	GameObject* m_pBobblePlayer;

	glm::vec2 m_MaitaPosition;
	glm::vec2 m_BobblePosition;
};

