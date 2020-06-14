#pragma once
#include "BubbleState.h"
#include "GameTime.h"

class Bubble;

class BubbleMaitaPlayer : public BubbleState
{
public:
	BubbleMaitaPlayer(Bubble* pBubble);
	~BubbleMaitaPlayer() = default;

	BubbleMaitaPlayer(const BubbleMaitaPlayer& other) = delete;
	BubbleMaitaPlayer(BubbleMaitaPlayer&& other) noexcept = delete;
	BubbleMaitaPlayer& operator=(const BubbleMaitaPlayer& other) = delete;
	BubbleMaitaPlayer& operator=(BubbleMaitaPlayer&& other) noexcept = delete;

	void Update() override;
	void OnEnter() override;
	void OnExit() override;

	void PopBubble() override;

private:
	GameTime* m_pGameTime;

	float m_BubbleTimer;
	float m_PopTime;
};

