#include "Level2Scene.h"

#include "FPSComponent.h"

Level2Scene::Level2Scene()
	: Scene(L"Level2Scene")
	, m_pBobblePlayer(nullptr)
	, m_pFPSCounter(nullptr)
	, m_pLevelManager(LevelManager::GetInstance())
	, m_pScoreManager(ScoreManager::GetInstance())
	, m_pPopUpManager(PopUpManager::GetInstance())
{

}

Level2Scene::~Level2Scene()
{
	LevelManager::DestroyInstance();
	ScoreManager::DestroyInstance();
	PopUpManager::DestroyInstance();
}

void Level2Scene::Initialize()
{
	m_pFPSCounter = new GameObject();
	m_pFPSCounter->AddComponent(new FPSComponent());
	m_pFPSCounter->GetTransform()->Translate(16, 16);

	m_pLevelManager->Initialize(2, GameMode::Solo);

	Add(m_pFPSCounter);
}

void Level2Scene::Update()
{
	if (!m_pLevelManager->CheckLevel())
	{
		m_pLevelManager->InitializeLevel();
		m_pBobblePlayer = m_pLevelManager->GetBobblePlayer();
	}
	
	m_pPopUpManager->Update();
	m_pLevelManager->Update();
}

void Level2Scene::Render()
{
	m_pScoreManager->Render();
	m_pPopUpManager->Render();
}
