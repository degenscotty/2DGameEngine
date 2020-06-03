#pragma once
#include <glm.hpp>

#include "BubbleState.h"
#include "GameTime.h"

class Bubble;

class BubbleMaitaDead : public BubbleState
{
public:
	BubbleMaitaDead(Bubble* pBubble);
	~BubbleMaitaDead() = default;

	BubbleMaitaDead(const BubbleMaitaDead& other) = delete;
	BubbleMaitaDead(BubbleMaitaDead&& other) noexcept = delete;
	BubbleMaitaDead& operator=(const BubbleMaitaDead& other) = delete;
	BubbleMaitaDead& operator=(BubbleMaitaDead&& other) noexcept = delete;

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
