#include "GameOverScene.h"


#include "GarbageCollector.h"
#include "MainMenuScene.h"
#include "ResourceManager.h"

GameOverScene::GameOverScene()
	: Scene(L"GameOverScene")
	, m_pInputManager(InputManager::GetInstance())
	, m_BackButton({ 422, 423 }, "BackButtonS.png", "BackButtonNS.png")
	, m_pGameOverBackGround(nullptr)
{

}

GameOverScene::~GameOverScene()
{

}

void GameOverScene::Initialize()
{
	m_pGameOverBackGround = ResourceManager::GetInstance()->LoadTexture("GameOverBackGround.png");

	m_BackButton.Initialize();
}

void GameOverScene::Update()
{
	glm::vec2 mousePos = { m_pInputManager->GetMousePos() };

	m_BackButton.Update(mousePos);

	if (m_pInputManager->IsMouseButtonPressed(MOUSE_LEFT))
	{
		if (m_BackButton.OnClick())
		{
			SceneManager::GetInstance()->SetActiveScene(L"MainMenuScene");
		}
	}
}

void GameOverScene::Render()
{
	Renderer::GetInstance()->RenderTexture(m_pGameOverBackGround->GetSDLTexture(), 0, 0);
	m_BackButton.Render();
}