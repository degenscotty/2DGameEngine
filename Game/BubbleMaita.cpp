#include "BubbleMaita.h"
#include "Bubble.h"

BubbleMaita::BubbleMaita(Bubble* pBubble)
	: BubbleState(pBubble)
{
	
}

void BubbleMaita::Update()
{
	
}

void BubbleMaita::Swap()
{
	
}

void BubbleMaita::OnEnter()
{
	m_pBubble->SetAnimationClip(3);
	m_pBubble->SetActive(false);
}

void BubbleMaita::OnExit()
{
	
}