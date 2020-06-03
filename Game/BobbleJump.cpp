#include "BobbleJump.h"
#include "BobblePlayer.h"


BobbleJump::BobbleJump(BobblePlayer* player)
	: BobbleState(player)
{
	
}

void BobbleJump::Update()
{
	
}

void BobbleJump::OnEnter()
{
	m_pBobblePlayer->SetAnimationClip(2);
}

void BobbleJump::OnExit()
{
	
}