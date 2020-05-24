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

	auto* pWall = new GameObject();
	pWall->AddComponent(new TextureComponent("TestWall.png"));
	pWall->AddComponent(new CollisionComponent(32, 32));
	pWall->GetTransform()->Translate(200, 384);

	auto* pGround = new GameObject();
	pGround->AddComponent(new TextureComponent("TestGround.png"));
	pGround->AddComponent(new CollisionComponent(512, 32));
	pGround->GetTransform()->Translate(0, 416);
	
	Add(m_TestPlayer.GetGameObject());
	Add(m_pFPSCounter);
	Add(pWall);
	Add(pGround);
}

void TestScene::Update()
{

}

void TestScene::Render()
{

}


