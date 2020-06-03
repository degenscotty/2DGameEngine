#include "BubblePop.h"
#include "Bubble.h"

BubblePop::BubblePop(Bubble* pBubble)
	: BubbleState(pBubble)
{
	
}

void BubblePop::Update()
{
	
}

void BubblePop::OnEnter()
{
	m_pBubble->SetAnimationClip(2);
}

void BubblePop::OnExit()
{
	
}