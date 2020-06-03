#include "BobbleIdle.h"
#include "BobblePlayer.h"

BobbleIdle::BobbleIdle(BobblePlayer* player)
	: BobbleState(player)
{

}

void BobbleIdle::Update()
{

}

void BobbleIdle::OnEnter()
{
	m_pBobblePlayer->SetAnimationClip(0);
}

void BobbleIdle::OnExit()
{

}