#include "LevelVersusScene.h"

#include "FPSComponent.h"

LevelVersusScene::LevelVersusScene(int levelNumber)
	: Scene(L"LevelVersusScene")
	, m_pFPSCounter(nullptr)
	, m_pLevelManager(LevelManager::GetInstance())
	, m_pScoreManager(ScoreManager::GetInstance())
	, m_pPopUpManager(PopUpManager::GetInstance())
	, m_LevelNumber(levelNumber)
{

}

LevelVersusScene::~LevelVersusScene()
{
	LevelManager::DestroyInstance();
	PopUpManager::DestroyInstance();
}

void LevelVersusScene::Initialize()
{
	ScoreManager::GetInstance()->Reset();
	
	m_pFPSCounter = new GameObject();
	m_pFPSCounter->AddComponent(new FPSComponent());
	m_pFPSCounter->GetTransform()->Translate(16, 16);

	m_pLevelManager->Initialize(m_LevelNumber, GameMode::Versus);

	Add(m_pFPSCounter);
}

void LevelVersusScene::Update()
{
	if (!m_pLevelManager->CheckLevel())
	{
		m_pLevelManager->InitializeLevel();
	}

	m_pPopUpManager->Update();
	m_pLevelManager->Update();
}

void LevelVersusScene::Render()
{
	m_pScoreManager->Render();
	m_pPopUpManager->Render();
}