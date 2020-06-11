#include "Level3Scene.h"
#include "FPSComponent.h"

Level3Scene::Level3Scene()
	: Scene(L"Level3Scene")
	, m_pBobblePlayer(nullptr)
	, m_pFPSCounter(nullptr)
	, m_pLevelManager(LevelManager::GetInstance())
	, m_pScoreManager(ScoreManager::GetInstance())
	, m_pPopUpManager(PopUpManager::GetInstance())
{

}

Level3Scene::~Level3Scene()
{
	LevelManager::DestroyInstance();
	ScoreManager::DestroyInstance();
	PopUpManager::DestroyInstance();
}

void Level3Scene::Initialize()
{
	m_pFPSCounter = new GameObject();
	m_pFPSCounter->AddComponent(new FPSComponent());
	m_pFPSCounter->GetTransform()->Translate(16, 16);

	m_pLevelManager->Initialize(3);

	Add(m_pFPSCounter);
}

void Level3Scene::Update()
{
	if (!m_pLevelManager->CheckLevel())
	{
		m_pLevelManager->InitializeLevel();
		m_pBobblePlayer = m_pLevelManager->GetBobblePlayer();
	}
	
	m_pPopUpManager->Update();
	m_pLevelManager->Update();
}

void Level3Scene::Render()
{
	m_pScoreManager->Render();
	m_pPopUpManager->Render();
}