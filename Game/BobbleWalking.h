#pragma once
#include "BobbleState.h"

class BobblePlayer;

class BobbleWalking : public BobbleState
{
public:
	BobbleWalking(BobblePlayer* player);
	~BobbleWalking() = default;

	BobbleWalking(const BobbleWalking& other) = delete;
	BobbleWalking(BobbleWalking&& other) noexcept = delete;
	BobbleWalking& operator=(const BobbleWalking& other) = delete;
	BobbleWalking& operator=(BobbleWalking&& other) noexcept = delete;

	void Update() override;
	void OnEnter() override;
	void OnExit() override;

private:
	
};

