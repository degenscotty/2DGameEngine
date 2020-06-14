#pragma once
#include "BubbleState.h"
#include "GameTime.h"

class Bubble;

class BubbleMaita : public BubbleState
{
public:
	BubbleMaita(Bubble* pBubble);
	~BubbleMaita() = default;

	BubbleMaita(const BubbleMaita& other) = delete;
	BubbleMaita(BubbleMaita&& other) noexcept = delete;
	BubbleMaita& operator=(const BubbleMaita& other) = delete;
	BubbleMaita& operator=(BubbleMaita&& other) noexcept = delete;

	void Update() override;
	void OnEnter() override;
	void OnExit() override;

	void PopBubble() override;

private:
	GameTime* m_pGameTime;
	
	float m_BubbleTimer;
	float m_PopTime;
};

