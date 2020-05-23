#include "TestScene.h"
#include "FPSComponent.h"
#include "TestPlayer.h"

TestScene::TestScene()
	: Scene(L"TestScene")
	, m_pFPSCounter(nullptr)
{

}

TestScene::~TestScene()
{

}

void TestScene::Initialize()
{
	m_pFPSCounter = new GameObject();
	m_pFPSCounter->AddComponent(new FPSComponent());
	m_pFPSCounter->GetTransform()->Translate(16, 16);

	m_TestPlayer.Initialize();
	
	Add(m_TestPlayer.GetGameObject());
	Add(m_pFPSCounter);
}

void TestScene::Update()
{

}

void TestScene::Render()
{

}


