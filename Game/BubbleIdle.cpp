#include "BubbleIdle.h"
#include "Bubble.h"

BubbleIdle::BubbleIdle(Bubble* pBubble)
	: BubbleState(pBubble)
	, m_BubbleTimer(0.0f)
	, m_PopTime(4.0f)
	, m_pGameTime(GameTime::GetInstance())
{
	
}

void BubbleIdle::Update()
{
	m_BubbleTimer += m_pGameTime->GetElapsedSec();

	if (m_BubbleTimer >= m_PopTime)
	{
		m_BubbleTimer = 0;
		m_pBubble->ChangeState("bubblePop");
	}
}

void BubbleIdle::PopBubble()
{
	m_pBubble->ChangeState("bubblePop");
}

void BubbleIdle::OnEnter()
{
}

void BubbleIdle::OnExit()
{
	
}