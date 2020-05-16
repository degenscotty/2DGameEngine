#include "TestScene.h"

#include "FPSComponent.h"

TestScene::TestScene()
	: Scene(L"TestScene")
	, m_pFPSCounter(nullptr)
	, m_pTestObject(nullptr)
{

}

TestScene::~TestScene()
{

}

void TestScene::Initialize()
{
	m_pFPSCounter = new GameObject();
	m_pTestObject = new GameObject();

	m_pFPSCounter->AddComponent(new FPSComponent());
	m_pFPSCounter->GetTransform()->Translate(16, 16);

	Add(m_pTestObject);
	Add(m_pFPSCounter);
}

void TestScene::Update()
{

}

void TestScene::Render()
{

}


