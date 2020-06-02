#include "BubblePop.h"
#include "Bubble.h"

BubblePop::BubblePop(Bubble* pBubble)
	: BubbleState(pBubble)
{
	
}

void BubblePop::Update()
{
	
}

void BubblePop::Swap()
{
	
}

void BubblePop::OnEnter()
{
	m_pBubble->SetAnimationClip(1);
}

void BubblePop::OnExit()
{
	
}