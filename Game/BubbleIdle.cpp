#include "BubbleIdle.h"
#include "Bubble.h"

BubbleIdle::BubbleIdle(Bubble* pBubble)
	: BubbleState(pBubble)
{
	
}

void BubbleIdle::Update()
{
	
}

void BubbleIdle::PopBubble()
{
	m_pBubble->ChangeState("bubblePop");
}

void BubbleIdle::Swap()
{
	
}

void BubbleIdle::OnEnter()
{
	m_pBubble->SetAnimationClip(1);
}

void BubbleIdle::OnExit()
{
	
}