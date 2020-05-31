#include "Level1Scene.h"
#include "FPSComponent.h"
#include "BobblePlayer.h"

Level1Scene::Level1Scene()
	: Scene(L"Level1Scene")
	, m_pBobblePlayer(nullptr)
	, m_pFPSCounter(nullptr)
	, m_pLevelManager(LevelManager::GetInstance())
{

}

Level1Scene::~Level1Scene()
{
	LevelManager::DestroyInstance();
}

void Level1Scene::Initialize()
{
	m_pFPSCounter = new GameObject();
	m_pFPSCounter->AddComponent(new FPSComponent());
	m_pFPSCounter->GetTransform()->Translate(16, 16);

	m_pLevelManager->Initialize();

	Add(m_pFPSCounter);
}

void Level1Scene::Update()
{
	if (!m_pLevelManager->CheckLevel())
	{
		m_pLevelManager->InitializeLevel();
		m_pBobblePlayer = m_pLevelManager->GetBobblePlayer();
	}

	m_pBobblePlayer->Update();
}

void Level1Scene::Render()
{

}


