#pragma once
#include "BubbleState.h"

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
	void Swap() override;
	void OnEnter() override;
	void OnExit() override;

public:

};

