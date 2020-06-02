#include "BubbleMaita.h"
#include "Bubble.h"
#include "PopUpManager.h"

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

void BubbleMaita::PopBubble()
{
	PopUpManager::GetInstance()->AddPopUp("1000", m_pBubble->GetPosition());
	m_CommandMap.at("bubbleMaita")->Execute();

	m_pBubble->ChangeState("bubblePop");
}

void BubbleMaita::OnEnter()
{
	m_pBubble->SetAnimationClip(3);
}

void BubbleMaita::OnExit()
{
	
}