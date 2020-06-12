#pragma once
#include "BobbleState.h"
#include "GameTime.h"

class BobblePlayer;

class BobbleDead : public BobbleState
{
public:
	BobbleDead(BobblePlayer* player);
	~BobbleDead() = default;

	BobbleDead(const BobbleDead& other) = delete;
	BobbleDead(BobbleDead&& other) noexcept = delete;
	BobbleDead& operator=(const BobbleDead& other) = delete;
	BobbleDead& operator=(BobbleDead&& other) noexcept = delete;

	void Update() override;
	void OnEnter() override;
	void OnExit() override;

private:
	GameTime* m_pGameTime;
	
	float m_RespawnTimer;
	float m_RespawnTime;
};

