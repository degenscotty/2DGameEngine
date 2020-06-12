#include "BobbleDead.h"
#include "BobblePlayer.h"
#include "GarbageCollector.h"

BobbleDead::BobbleDead(BobblePlayer* player)
	: BobbleState(player)
	, m_pGameTime(GameTime::GetInstance())
	, m_RespawnTimer(0.0f)
	, m_RespawnTime(2.0f)
{
}

void BobbleDead::Update()
{
	m_RespawnTimer += m_pGameTime->GetElapsedSec();

	if (m_RespawnTimer > m_RespawnTime)
	{
		m_RespawnTimer = 0.0f;
		m_pBobblePlayer->SetPosition({ 32, 400 });
		m_pBobblePlayer->ChangeState("idle");
		m_pBobblePlayer->EnableEnemyCollision();
		m_pBobblePlayer->SetIsRespawning(false);
	}
}

void BobbleDead::OnEnter()
{
	m_pBobblePlayer->SetAnimationClip(4);
}

void BobbleDead::OnExit()
{
	m_pBobblePlayer->SetAnimationClip(0);
}