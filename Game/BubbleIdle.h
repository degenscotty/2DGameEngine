#pragma once
#include "BubbleState.h"

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
	void Swap() override;
	void OnEnter() override;
	void OnExit() override;

public:
	
};

