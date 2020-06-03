#include "BobbleWalking.h"
#include "BobblePlayer.h"

BobbleWalking::BobbleWalking(BobblePlayer* player)
	: BobbleState(player)
{

}

void BobbleWalking::Update()
{

}

void BobbleWalking::OnEnter()
{
	m_pBobblePlayer->SetAnimationClip(1);
}

void BobbleWalking::OnExit()
{

}