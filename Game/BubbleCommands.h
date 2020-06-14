#pragma once
#include "Commands.h"
#include "Bubble.h"
#include "Fries.h"
#include "Maita.h"
#include "MaitaPlayer.h"
#include "WaterMelon.h"
#include "ZenChan.h"

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

class BubbleRMaitaPlayerC : public Command
{
public:
	explicit BubbleRMaitaPlayerC(Bubble* pBubble)
		: m_pBubble(pBubble)
		, m_pLevelManager(LevelManager::GetInstance())
		, m_pSceneManager(SceneManager::GetInstance())
	{
	}

	void Execute() override
	{
		auto pMaitaPlayer = new MaitaPlayer();
		pMaitaPlayer->Initialize();
		pMaitaPlayer->SetPosition(m_pBubble->GetPosition());
		m_pLevelManager->SetMaitaPlayer(pMaitaPlayer);
		m_pSceneManager->GetActiveScene()->Add(pMaitaPlayer->GetGameObject());
	}

private:
	Bubble* m_pBubble;
	LevelManager* m_pLevelManager;
	SceneManager* m_pSceneManager;
};

class BubbleRZenChanC : public Command
{
public:
	explicit BubbleRZenChanC(Bubble* pBubble)
		: m_pBubble(pBubble)
		, m_pLevelManager(LevelManager::GetInstance())
		, m_pSceneManager(SceneManager::GetInstance())
	{
	}

	void Execute() override
	{
		auto pZenChan = new ZenChan();
		pZenChan->Initialize();
		pZenChan->SetPosition(m_pBubble->GetPosition());
		m_pLevelManager->AddZenChan(pZenChan);
		m_pSceneManager->GetActiveScene()->Add(pZenChan->GetGameObject());
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
		, m_pLevelManager(LevelManager::GetInstance())
		, m_pBubble(pBubble)
	{
	}

	void Execute() override
	{
		Fries* pFries = new Fries();
		pFries->Initialize();
		pFries->SetPosition(m_pBubble->GetPosition());
		m_pLevelManager->AddFries(pFries);
		m_pSceneManager->GetActiveScene()->Add(pFries->GetGameObject());
	}

private:
	SceneManager* m_pSceneManager;
	LevelManager* m_pLevelManager;
	Bubble* m_pBubble;
};

class BubbleSpawnWaterMelonC : public Command
{
public:
	explicit BubbleSpawnWaterMelonC(Bubble* pBubble)
		: m_pSceneManager(SceneManager::GetInstance())
		, m_pLevelManager(LevelManager::GetInstance())
		, m_pBubble(pBubble)
	{
	}

	void Execute() override
	{
		WaterMelon* pWaterMelon = new WaterMelon();
		pWaterMelon->Initialize();
		pWaterMelon->SetPosition(m_pBubble->GetPosition());
		m_pLevelManager->AddWaterMelon(pWaterMelon);
		m_pSceneManager->GetActiveScene()->Add(pWaterMelon->GetGameObject());
	}

private:
	SceneManager* m_pSceneManager;
	LevelManager* m_pLevelManager;
	Bubble* m_pBubble;
};
