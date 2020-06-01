#include "BubbleZenChan.h"
#include "Bubble.h"

BubbleZenChan::BubbleZenChan(Bubble* pBubble)
	: BubbleState(pBubble)
{
	
}

void BubbleZenChan::Update()
{
	
}

void BubbleZenChan::Swap()
{
	
}

void BubbleZenChan::OnEnter()
{
	m_pBubble->SetAnimationClip(2);
}

void BubbleZenChan::OnExit()
{
	
}