#pragma once
#include <glm.hpp>

#include "BubbleState.h"
#include "GameTime.h"

class Bubble;

class BubbleZenChanDead : public BubbleState
{
public:
	BubbleZenChanDead(Bubble* pBubble);
	~BubbleZenChanDead() = default;

	BubbleZenChanDead(const BubbleZenChanDead& other) = delete;
	BubbleZenChanDead(BubbleZenChanDead&& other) noexcept = delete;
	BubbleZenChanDead& operator=(const BubbleZenChanDead& other) = delete;
	BubbleZenChanDead& operator=(BubbleZenChanDead&& other) noexcept = delete;

	void Update() override;
	void OnEnter() override;
	void OnExit() override;

	void PopBubble() override {};
	
private:
	GameTime* m_pGameTime;

	glm::vec2 m_StartPosition;
	
	float m_ShootTimer;
	float m_ShootTime;
	int m_ShootCount;
	int m_MaxShootCount;
};
