#include "ZenChanSeekingAI.h"
#include "LevelManager.h"
#include "ZenChan.h"
#include "BobblePlayer1.h"
#include "utils.h"

ZenChanSeekingAI::ZenChanSeekingAI(ZenChan* pZenChan)
	: ZenChanStateAI(pZenChan)
	, m_pBobblePlayer(nullptr)
	, m_BobblePosition({ 0, 0 })
	, m_ZenChanPosition(pZenChan->GetPosition())
{

}

void ZenChanSeekingAI::Update()
{
	GetBobblePosition();
	m_ZenChanPosition = m_pZenChan->GetPosition();

	if (m_BobblePosition != glm::vec2{ 0, 0 })
	{
		if (utils::Distance(m_ZenChanPosition.x, m_BobblePosition.x) < 32)
		{
			if (m_BobblePosition.y < m_ZenChanPosition.y)
			{
				if (m_pZenChan->GetCanJump())
				{
					m_CommandMap.at("jump")->Execute();
					m_pZenChan->SetJump(false);
				}
				m_pZenChan->ChangeState("idle");
			}
		}
		else if (m_BobblePosition.x > m_ZenChanPosition.x)
		{
			m_CommandMap.at("moveright")->Execute();
		}
		else if (m_BobblePosition.x < m_ZenChanPosition.x)
		{
			m_CommandMap.at("moveleft")->Execute();
		}
	}
}

void ZenChanSeekingAI::GetBobblePosition()
{
	if (!m_pBobblePlayer)
		m_pBobblePlayer = LevelManager::GetInstance()->GetBobblePlayer()->GetGameObject();
	else
	{
		m_BobblePosition = m_pBobblePlayer->GetTransform()->GetPosition();
	}
}

void ZenChanSeekingAI::OnEnter()
{
	m_pZenChan->SetAnimationClip(0);
}

void ZenChanSeekingAI::OnExit()
{

}