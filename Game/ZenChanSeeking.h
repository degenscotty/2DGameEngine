#pragma once
#include "GameObject.h"
#include "ZenChanState.h"

class ZenChan;

class ZenChanSeeking : public ZenChanState
{
public:
	ZenChanSeeking(ZenChan* pZenChan);
	~ZenChanSeeking() = default;

	ZenChanSeeking(const ZenChanSeeking& other) = delete;
	ZenChanSeeking(ZenChanSeeking&& other) noexcept = delete;
	ZenChanSeeking& operator=(const ZenChanSeeking& other) = delete;
	ZenChanSeeking& operator=(ZenChanSeeking&& other) noexcept = delete;

	void Update() override;
	void OnEnter() override;
	void OnExit() override;

	void GetBobblePosition();

private:
	GameObject* m_pBobblePlayer;

	glm::vec2 m_ZenChanPosition;
	glm::vec2 m_BobblePosition;
};

