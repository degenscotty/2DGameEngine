#pragma once
#include "BobbleState.h"

class BobblePlayer;

class BobbleIdle : public BobbleState
{
public:
	BobbleIdle(BobblePlayer* player);
	~BobbleIdle() = default;

	BobbleIdle(const BobbleIdle& other) = delete;
	BobbleIdle(BobbleIdle&& other) noexcept = delete;
	BobbleIdle& operator=(const BobbleIdle& other) = delete;
	BobbleIdle& operator=(BobbleIdle&& other) noexcept = delete;

	void Update() override;
	void Swap() override;
	void OnEnter() override;
	void OnExit() override;
	
private:
	
};

