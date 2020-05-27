#include "MaitaIdle.h"
#include "Maita.h"

MaitaIdle::MaitaIdle(Maita* pMaita)
	: MaitaState(pMaita)
	, m_pGameTime(GameTime::GetInstance())
	, m_SpawnTimer(0)
	, m_TimeToSeek(2)
{
	
}

void MaitaIdle::Update()
{
	m_SpawnTimer += m_pGameTime->GetElapsedSec();

	if (m_SpawnTimer > m_TimeToSeek)
	{
		m_pEnemyMaita->ChangeState("seeking");
		m_SpawnTimer = 0;
	}
}

void MaitaIdle::Swap()
{
	
}

void MaitaIdle::OnEnter()
{
	m_CommandMap.at("stopmove")->Execute();
	m_pEnemyMaita->SetAnimationClip(0);
}

void MaitaIdle::OnExit()
{
	
}