#pragma once
#include "BobbleState.h"

class BobblePlayer;

class BobbleJump: public BobbleState
{
public:
	BobbleJump(BobblePlayer* player);
	~BobbleJump() = default;

	BobbleJump(const BobbleJump& other) = delete;
	BobbleJump(BobbleJump&& other) noexcept = delete;
	BobbleJump& operator=(const BobbleJump& other) = delete;
	BobbleJump& operator=(BobbleJump&& other) noexcept = delete;

	void Update() override;
	void OnEnter() override;
	void OnExit() override;

private:

};

