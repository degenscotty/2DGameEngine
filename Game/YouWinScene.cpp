#include "YouWinScene.h"

YouWinScene::YouWinScene()
	: Scene(L"YouWinScene")
	, m_pBackButtonComponent(nullptr)
{

}

YouWinScene::~YouWinScene()
{

}

void YouWinScene::Initialize()
{
	GameObject* pBackGround = new GameObject();
	
	pBackGround->AddComponent(new TextureComponent("YouWinBackGround.png"));
	
	Add(pBackGround);

	GameObject* pBobbleInBubble = new GameObject();

	SpriteComponent* pSpriteComponent = new SpriteComponent("LevelWonAnimation.png", 1, 2, 80);
	pSpriteComponent->AddClip(2, true);
	pBobbleInBubble->AddComponent(pSpriteComponent);
	pBobbleInBubble->GetTransform()->Translate({ (256 - 40),100 });

	Add(pBobbleInBubble);

	auto* backButton = new GameObject();
	m_pBackButtonComponent = new ButtonComponent("BackButtonS.png", "BackButtonNS.png");
	backButton->AddComponent(m_pBackButtonComponent);
	backButton->GetTransform()->Translate(422, 423);

	Add(backButton);
}

void YouWinScene::Update()
{
	if (m_pBackButtonComponent->OnClick())
	{
		SceneManager::GetInstance()->SetActiveScene(L"MainMenuScene");
	}
}

void YouWinScene::Render()
{

}