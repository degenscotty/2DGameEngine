#include "MaitaIdle.h"
#include "Maita.h"

MaitaIdle::MaitaIdle(Maita* pMaita)
	: MaitaState(pMaita)
	, m_pGameTime(GameTime::GetInstance())
	, m_SpawnTimer(0.0f)
	, m_TimeToSeek(1.2f)
{
	
}

void MaitaIdle::Update()
{
	m_SpawnTimer += m_pGameTime->GetElapsedSec();

	if (m_SpawnTimer > m_TimeToSeek)
	{
		m_pMaita->ChangeState("seeking");
		m_SpawnTimer = 0;
	}
}

void MaitaIdle::Swap()
{
	
}

void MaitaIdle::OnEnter()
{
	m_SpawnTimer = 0;
	m_CommandMap.at("stopmove")->Execute();
	m_pMaita->SetAnimationClip(0);
}

void MaitaIdle::OnExit()
{
	
}