#include "BobbleJump.h"
#include "BobblePlayer.h"


BobbleJump::BobbleJump(BobblePlayer* player)
	: BobbleState(player)
{
	
}

void BobbleJump::Update()
{
	
}

void BobbleJump::Swap()
{
	
}

void BobbleJump::OnEnter()
{
	m_pBobblePlayer->SetAnimationClip(2);
	m_pBobblePlayer->ChangeState("jumping");
}

void BobbleJump::OnExit()
{
	
}