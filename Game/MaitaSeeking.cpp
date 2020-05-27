#include "MaitaSeeking.h"

#include "LevelManager.h"

MaitaSeeking::MaitaSeeking(Maita* pMaita)
	: MaitaState(pMaita)
	, m_pBobblePlayer(nullptr)
	, m_BobblePosition({0, 0})
	, m_MaitaPosition(pMaita->GetPosition())
{
	
}

void MaitaSeeking::Update()
{
	GetBobblePosition();
	m_MaitaPosition = m_pEnemyMaita->GetPosition();
	
	if (m_BobblePosition != glm::vec2{0, 0} )
	{
		if (utils::Distance(m_MaitaPosition.x, m_BobblePosition.x) < 48)
		{
			m_pEnemyMaita->ChangeState("idle");
		}
		else if (m_BobblePosition.x > m_MaitaPosition.x)
		{
			m_CommandMap.at("moveright")->Execute();
		}
		else if (m_BobblePosition.x < m_MaitaPosition.x)
		{
			m_CommandMap.at("moveleft")->Execute();
		}
	}
}

void MaitaSeeking::GetBobblePosition()
{
	if (!m_pBobblePlayer)
		m_pBobblePlayer = LevelManager::GetInstance()->GetBobblePlayer()->GetGameObject();
	else
	{
		m_BobblePosition = m_pBobblePlayer->GetTransform()->GetPosition();
	}
}

void MaitaSeeking::Swap()
{
	
}

void MaitaSeeking::OnEnter()
{
	m_pEnemyMaita->SetAnimationClip(0);
}

void MaitaSeeking::OnExit()
{
	
}