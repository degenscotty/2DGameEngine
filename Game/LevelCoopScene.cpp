#include "LevelCoopScene.h"

#include "FPSComponent.h"

LevelCoopScene::LevelCoopScene(int levelNumber)
	: Scene(L"LevelCoopScene")
	, m_pFPSCounter(nullptr)
	, m_pLevelManager(LevelManager::GetInstance())
	, m_pScoreManager(ScoreManager::GetInstance())
	, m_pPopUpManager(PopUpManager::GetInstance())
	, m_LevelNumber(levelNumber)
{

}
LevelCoopScene::~LevelCoopScene()
{
	LevelManager::DestroyInstance();
	PopUpManager::DestroyInstance();
}

void LevelCoopScene::Initialize()
{
	m_pFPSCounter = new GameObject();
	m_pFPSCounter->AddComponent(new FPSComponent());
	m_pFPSCounter->GetTransform()->Translate(16, 16);

	m_pLevelManager->Initialize(m_LevelNumber, GameMode::Coop);

	Add(m_pFPSCounter);
}

void LevelCoopScene::Update()
{
	if (!m_pLevelManager->CheckLevel())
	{
		m_pLevelManager->InitializeLevel();
	}

	m_pPopUpManager->Update();
	m_pLevelManager->Update();
}

void LevelCoopScene::Render()
{
	m_pScoreManager->Render();
	m_pPopUpManager->Render();
}