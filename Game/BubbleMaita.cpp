#include "BubbleMaita.h"
#include "Bubble.h"
#include "PopUpManager.h"
#include "ScoreManager.h"

BubbleMaita::BubbleMaita(Bubble* pBubble)
	: BubbleState(pBubble)
	, m_pGameTime(GameTime::GetInstance())
	, m_BubbleTimer(0.0f)
	, m_PopTime(4.0f)
{

}

void BubbleMaita::Update()
{
	m_BubbleTimer += m_pGameTime->GetElapsedSec();

	if (m_BubbleTimer >= m_PopTime)
	{
		m_BubbleTimer = 0;
		m_CommandMap.at("releaseMaita")->Execute();
		m_pBubble->ChangeState("bubblePop");
	}
}

void BubbleMaita::PopBubble()
{
	PopUpManager::GetInstance()->AddPopUp("1000", m_pBubble->GetPosition(), {41, 133, 224});
	ScoreManager::GetInstance()->AddScore(1000);
	m_pBubble->ChangeState("bubbleMaitaDead");
}

void BubbleMaita::OnEnter()
{
	m_pBubble->SetAnimationClip(4);
}

void BubbleMaita::OnExit()
{

}