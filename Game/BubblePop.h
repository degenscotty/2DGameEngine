#pragma once
#include "BubbleState.h"

class Bubble;

class BubblePop : public BubbleState
{
public:
	BubblePop(Bubble* pBubble);
	~BubblePop() = default;

	BubblePop(const BubblePop& other) = delete;
	BubblePop(BubblePop&& other) noexcept = delete;
	BubblePop& operator=(const BubblePop& other) = delete;
	BubblePop& operator=(BubblePop&& other) noexcept = delete;

	void Update() override;
	void OnEnter() override;
	void OnExit() override;

	void PopBubble() override {};

private:
	
};

