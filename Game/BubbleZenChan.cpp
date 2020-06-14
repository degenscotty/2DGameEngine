#include "BubbleZenChan.h"
#include "Bubble.h"
#include "PopUpManager.h"
#include "ScoreManager.h"

BubbleZenChan::BubbleZenChan(Bubble* pBubble)
	: BubbleState(pBubble)
	, m_pGameTime(GameTime::GetInstance())
	, m_BubbleTimer(0.0f)
	, m_PopTime(4.0f)
{
	
}

void BubbleZenChan::Update()
{
	m_BubbleTimer += m_pGameTime->GetElapsedSec();

	if (m_BubbleTimer >= m_PopTime)
	{
		m_BubbleTimer = 0;
		m_CommandMap.at("releaseZenChan")->Execute();
		m_pBubble->ChangeState("bubblePop");
	}
}

void BubbleZenChan::PopBubble()
{
	PopUpManager::GetInstance()->AddPopUp("1000", m_pBubble->GetPosition(), { 41, 133, 224 });
	ScoreManager::GetInstance()->AddScore(1000);
	m_pBubble->ChangeState("bubbleZenChanDead");

}

void BubbleZenChan::OnEnter()
{
	m_pBubble->SetAnimationClip(3);
}

void BubbleZenChan::OnExit()
{
	
}