#include "GameOverScene.h"

GameOverScene::GameOverScene()
	: Scene(L"GameOverScene")
	, m_pBackButtonComponent(nullptr)
{

}

GameOverScene::~GameOverScene()
{

}

void GameOverScene::Initialize()
{
	GameObject* pBackGround = new GameObject();

	pBackGround->AddComponent(new TextureComponent("GameOverBackGround.png"));

	Add(pBackGround);

	auto* backButton = new GameObject();
	m_pBackButtonComponent = new ButtonComponent("BackButtonS.png", "BackButtonNS.png");
	backButton->AddComponent(m_pBackButtonComponent);
	backButton->GetTransform()->Translate(422, 423);

	Add(backButton);
}

void GameOverScene::Update()
{
	if (m_pBackButtonComponent->OnClick())
	{
		SceneManager::GetInstance()->SetActiveScene(L"MainMenuScene");
	}
}

void GameOverScene::Render()
{
}