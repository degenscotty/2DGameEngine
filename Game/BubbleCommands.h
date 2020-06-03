#pragma once
#include "Commands.h"
#include "Bubble.h"
#include "Fries.h"
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

class BubbleRandomDirectionC : public Command
{
public:
	explicit BubbleRandomDirectionC(BubbleComponent* pBubbleComponent)
		: m_pBubbleComponent(pBubbleComponent)
	{
	}

	void Execute() override
	{
		m_pBubbleComponent->ShootBubbleRandom();
	}

private:
	BubbleComponent* m_pBubbleComponent;
};

class BubbleSpawnFriesC : public Command
{
public:
	explicit BubbleSpawnFriesC(Bubble* pBubble)
		: m_pSceneManager(SceneManager::GetInstance())
		, m_pBubble(pBubble)
	{
	}

	void Execute() override
	{
		Fries* pFries = new Fries();
		pFries->Initialize();
		pFries->SetPosition(m_pBubble->GetPosition());
		m_pSceneManager->GetActiveScene()->Add(pFries->GetGameObject());

		delete pFries;
		pFries = nullptr;
	}

private:
	SceneManager* m_pSceneManager;
	Bubble* m_pBubble;
};
