#pragma once
#include "GameObject.h"
#include "ZenChanStateAI.h"

class ZenChan;

class ZenChanSeekingAI : public ZenChanStateAI
{
public:
	ZenChanSeekingAI(ZenChan* pZenChan);
	~ZenChanSeekingAI() = default;

	ZenChanSeekingAI(const ZenChanSeekingAI& other) = delete;
	ZenChanSeekingAI(ZenChanSeekingAI&& other) noexcept = delete;
	ZenChanSeekingAI& operator=(const ZenChanSeekingAI& other) = delete;
	ZenChanSeekingAI& operator=(ZenChanSeekingAI&& other) noexcept = delete;

	void Update() override;
	void OnEnter() override;
	void OnExit() override;

	void GetBobblePosition();

private:
	GameObject* m_pBobblePlayer;

	glm::vec2 m_ZenChanPosition;
	glm::vec2 m_BobblePosition;
};

