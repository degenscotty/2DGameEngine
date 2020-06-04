#include "BubbleZenChanDead.h"
#include "Bubble.h"
#include "utils.h"

BubbleZenChanDead::BubbleZenChanDead(Bubble* pBubble)
	: BubbleState(pBubble)
	, m_pGameTime(GameTime::GetInstance())
	, m_StartPosition({ 0, 0 })
	, m_ShootTimer(0.5f)
	, m_ShootTime(0.6f)
	, m_ShootCount(0)
	, m_MaxShootCount(4)
{

}

void BubbleZenChanDead::Update()
{
	if (m_StartPosition == glm::vec2{ 0, 0 })
		m_StartPosition = m_pBubble->GetPosition();

	m_ShootTimer += m_pGameTime->GetElapsedSec();

	if (m_ShootTimer >= m_ShootTime)
	{
		if (m_ShootCount >= m_MaxShootCount)
		{
			auto bubblePosition = m_pBubble->GetPosition();

			m_pBubble->MoveToPopPosition(m_StartPosition);

			if (utils::Distance(m_StartPosition, bubblePosition) < 1)
			{
				m_CommandMap.at("spawnWaterMelon")->Execute();
				m_pBubble->ChangeState("bubblePop");
			}
		}
		else
		{
			m_ShootTimer = 0.0f;
			++m_ShootCount;
			m_CommandMap.at("shootRandom")->Execute();
		}
	}
}

void BubbleZenChanDead::OnEnter()
{
	m_pBubble->SetAnimationClip(6);
}

void BubbleZenChanDead::OnExit()
{

}
