#include "LevelScene.h"
#include "FPSComponent.h"

LevelScene::LevelScene(int levelNumber)
	: Scene(L"LevelScene")
	, m_pFPSCounter(nullptr)
	, m_pLevelManager(LevelManager::GetInstance())
	, m_pScoreManager(ScoreManager::GetInstance())
	, m_pPopUpManager(PopUpManager::GetInstance())
	, m_LevelNumber(levelNumber)
{

}

LevelScene::~LevelScene()
{
	LevelManager::DestroyInstance();
	PopUpManager::DestroyInstance();
}

void LevelScene::Initialize()
{
	ScoreManager::GetInstance()->Reset();
	
	m_pFPSCounter = new GameObject();
	m_pFPSCounter->AddComponent(new FPSComponent());
	m_pFPSCounter->GetTransform()->Translate(16, 16);

	m_pLevelManager->Initialize(m_LevelNumber, GameMode::Solo);

	Add(m_pFPSCounter);
}

void LevelScene::Update()
{
	if (!m_pLevelManager->CheckLevel())
	{
		m_pLevelManager->InitializeLevel();
	}
	
	m_pPopUpManager->Update();
	m_pLevelManager->Update();
}

void LevelScene::Render()
{
	m_pScoreManager->Render();
	m_pPopUpManager->Render();
}


