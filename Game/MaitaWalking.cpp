#include "MaitaWalking.h"
#include "MaitaPlayer.h"

MaitaWalking::MaitaWalking(MaitaPlayer* pMaitaPlayer)
	: MaitaState(pMaitaPlayer)
{
	
}

void MaitaWalking::Update()
{
	
}

void MaitaWalking::OnEnter()
{
	m_pMaitaPlayer->SetAnimationClip(0);
}

void MaitaWalking::OnExit()
{
	
}