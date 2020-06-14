#include "MaitaIdleAI.h"
#include "Maita.h"

MaitaIdleAI::MaitaIdleAI(Maita* pMaita)
	: MaitaStateAI(pMaita)
	, m_pGameTime(GameTime::GetInstance())
	, m_SpawnTimer(0.0f)
	, m_TimeToSeek(1.2f)
{
	
}

void MaitaIdleAI::Update()
{
	m_SpawnTimer += m_pGameTime->GetElapsedSec();

	if (m_SpawnTimer > m_TimeToSeek)
	{
		m_pMaita->ChangeState("seeking");
		m_SpawnTimer = 0;
	}
}

void MaitaIdleAI::OnEnter()
{
	m_SpawnTimer = 0;
	m_CommandMap.at("stopmove")->Execute();
	m_pMaita->SetAnimationClip(0);
}

void MaitaIdleAI::OnExit()
{
	
}