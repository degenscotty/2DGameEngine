#pragma once
#include "BubbleState.h"
#include "GameTime.h"

class Bubble;

class BubbleIdle : public BubbleState
{
public:
	BubbleIdle(Bubble* pBubble);
	~BubbleIdle() = default;

	BubbleIdle(const BubbleIdle& other) = delete;
	BubbleIdle(BubbleIdle&& other) noexcept = delete;
	BubbleIdle& operator=(const BubbleIdle& other) = delete;
	BubbleIdle& operator=(BubbleIdle&& other) noexcept = delete;

	void Update() override;
	void OnEnter() override;
	void OnExit() override;

	void PopBubble() override;

private:
	GameTime* m_pGameTime;
	
	float m_BubbleTimer;
	float m_PopTime;
};

