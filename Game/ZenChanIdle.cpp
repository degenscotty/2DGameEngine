#include "ZenChanIdle.h"
#include "ZenChan.h"

ZenChanIdle::ZenChanIdle(ZenChan* pZenChan)
	: ZenChanState(pZenChan)
	, m_pGameTime(GameTime::GetInstance())
	, m_SpawnTimer(0.0f)
	, m_TimeToSeek(1.2f)
{
	
}

void ZenChanIdle::Update()
{
	m_SpawnTimer += m_pGameTime->GetElapsedSec();

	if (m_SpawnTimer > m_TimeToSeek)
	{
		m_pZenChan->ChangeState("seeking");
		m_SpawnTimer = 0;
	}
}

void ZenChanIdle::OnEnter()
{
	m_SpawnTimer = 0;
	m_CommandMap.at("stopmove")->Execute();
	m_pZenChan->SetAnimationClip(0);
}

void ZenChanIdle::OnExit()
{
	
}