#pragma once
#include "Commands.h"
#include "Bubble.h"
#include "Maita.h"

class BubbleRMaitaC : public Command
{
public:
	explicit BubbleRMaitaC(Bubble* pBubble)
		: m_pBubble(pBubble)
		, m_pLevelManager(LevelManager::GetInstance())
		, m_pSceneManager(SceneManager::GetInstance())
	{
	}

	void Execute() override
	{
		auto pMaita = new Maita();
		pMaita->Initialize();
		pMaita->SetPosition(m_pBubble->GetPosition());
		m_pLevelManager->AddMaita(pMaita);
		m_pSceneManager->GetActiveScene()->Add(pMaita->GetGameObject());
	}

private:
	Bubble* m_pBubble;
	LevelManager* m_pLevelManager;
	SceneManager* m_pSceneManager;
};