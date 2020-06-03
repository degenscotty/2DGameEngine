#include "BubbleZenChan.h"
#include "Bubble.h"

BubbleZenChan::BubbleZenChan(Bubble* pBubble)
	: BubbleState(pBubble)
{
	
}

void BubbleZenChan::Update()
{
	
}

void BubbleZenChan::PopBubble()
{
	
}

void BubbleZenChan::OnEnter()
{
	m_pBubble->SetAnimationClip(3);
}

void BubbleZenChan::OnExit()
{
	
}