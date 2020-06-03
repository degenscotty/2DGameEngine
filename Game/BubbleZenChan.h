#pragma once
#include "BubbleState.h"

class Bubble;

class BubbleZenChan : public BubbleState
{
public:
	BubbleZenChan(Bubble* pBubble);
	~BubbleZenChan() = default;

	BubbleZenChan(const BubbleZenChan& other) = delete;
	BubbleZenChan(BubbleZenChan&& other) noexcept = delete;
	BubbleZenChan& operator=(const BubbleZenChan& other) = delete;
	BubbleZenChan& operator=(BubbleZenChan&& other) noexcept = delete;

	void Update() override;
	void OnEnter() override;
	void OnExit() override;

	void PopBubble() override;

public:

};

