#include "MaitaIdle.h"
#include "EnemyMaita.h"

MaitaIdle::MaitaIdle(EnemyMaita* snail)
	: MaitaState(snail)
{
	
}

void MaitaIdle::Update()
{
	
}

void MaitaIdle::Swap()
{
	
}

void MaitaIdle::OnEnter()
{
	m_pEnemyMaita->SetAnimationClip(0);
	m_pEnemyMaita->ChangeState("idle");
}

void MaitaIdle::OnExit()
{
	
}