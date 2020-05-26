#include "SnailIdle.h"
#include "EnemySnail.h"

SnailIdle::SnailIdle(EnemySnail* snail)
	: SnailState(snail)
{
	
}

void SnailIdle::Update()
{
	
}

void SnailIdle::Swap()
{
	
}

void SnailIdle::OnEnter()
{
	m_pEnemySnail->SetAnimationClip(0);
	m_pEnemySnail->ChangeState("idle");
}

void SnailIdle::OnExit()
{
	
}