#include "TestScene.h"
#include "FPSComponent.h"
#include "BobblePlayer.h"

TestScene::TestScene()
	: Scene(L"TestScene")
	, m_pBobblePlayer(nullptr)
	, m_pFPSCounter(nullptr)
	, m_pLevelManager(LevelManager::GetInstance())
{

}

TestScene::~TestScene()
{
	LevelManager::DestroyInstance();
}

void TestScene::Initialize()
{
	m_pFPSCounter = new GameObject();
	m_pFPSCounter->AddComponent(new FPSComponent());
	m_pFPSCounter->GetTransform()->Translate(16, 16);

	m_pLevelManager->Initialize();
	m_pLevelManager->InitializeLevel();

	m_pBobblePlayer = m_pLevelManager->GetBobblePlayer();

	Add(m_pFPSCounter);
}

void TestScene::Update()
{
	m_pBobblePlayer->Update();
}

void TestScene::Render()
{

}


