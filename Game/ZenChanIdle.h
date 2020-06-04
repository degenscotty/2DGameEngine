#pragma once
#include "GameTime.h"
#include "ZenChanState.h"

class ZenChan;

class ZenChanIdle : public ZenChanState
{
public:
	ZenChanIdle(ZenChan* pZenChan);
	~ZenChanIdle() = default;

	ZenChanIdle(const ZenChanIdle& other) = delete;
	ZenChanIdle(ZenChanIdle&& other) noexcept = delete;
	ZenChanIdle& operator=(const ZenChanIdle& other) = delete;
	ZenChanIdle& operator=(ZenChanIdle&& other) noexcept = delete;

	void Update() override;
	void OnEnter() override;
	void OnExit() override;
	
private:
	GameTime* m_pGameTime;

	float m_SpawnTimer;
	float m_TimeToSeek;
};

