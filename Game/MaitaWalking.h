#pragma once
#include "MaitaState.h"

class MaitaPlayer;

class MaitaWalking final : public MaitaState
{
public:
	MaitaWalking(MaitaPlayer* pMaitaPlayer);
	~MaitaWalking() = default;

	MaitaWalking(const MaitaWalking& other) = delete;
	MaitaWalking(MaitaWalking&& other) noexcept = delete;
	MaitaWalking& operator=(const MaitaWalking& other) = delete;
	MaitaWalking& operator=(MaitaWalking&& other) noexcept = delete;

	void Update() override;
	void OnEnter() override;
	void OnExit() override;
	
private:
	
};

