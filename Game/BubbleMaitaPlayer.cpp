#include "BubbleMaitaPlayer.h"

#include "Bubble.h"
#include "PopUpManager.h"

BubbleMaitaPlayer::BubbleMaitaPlayer(Bubble* pBubble)
	: BubbleState(pBubble)
	, m_pGameTime(GameTime::GetInstance())
	, m_BubbleTimer(0.0f)
	, m_PopTime(4.0f)
{

}

void BubbleMaitaPlayer::Update()
{
	m_BubbleTimer += m_pGameTime->GetElapsedSec();

	if (m_BubbleTimer >= m_PopTime)
	{
		m_BubbleTimer = 0;
		m_CommandMap.at("releaseMaitaPlayer")->Execute();
		m_pBubble->ChangeState("bubblePop");
	}
}

void BubbleMaitaPlayer::PopBubble()
{
	PopUpManager::GetInstance()->AddPopUp("1000", m_pBubble->GetPosition(), { 41, 133, 224 });
	m_pBubble->ChangeState("bubbleMaitaDead");
}

void BubbleMaitaPlayer::OnEnter()
{
	m_pBubble->SetAnimationClip(4);
}

void BubbleMaitaPlayer::OnExit()
{

}