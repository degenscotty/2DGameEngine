#pragma once
#include "GameTime.h"
#include "ZenChanStateAI.h"

class ZenChan;

class ZenChanIdleAI : public ZenChanStateAI
{
public:
	ZenChanIdleAI(ZenChan* pZenChan);
	~ZenChanIdleAI() = default;

	ZenChanIdleAI(const ZenChanIdleAI& other) = delete;
	ZenChanIdleAI(ZenChanIdleAI&& other) noexcept = delete;
	ZenChanIdleAI& operator=(const ZenChanIdleAI& other) = delete;
	ZenChanIdleAI& operator=(ZenChanIdleAI&& other) noexcept = delete;

	void Update() override;
	void OnEnter() override;
	void OnExit() override;
	
private:
	GameTime* m_pGameTime;

	float m_SpawnTimer;
	float m_TimeToSeek;
};

