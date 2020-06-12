#include "SceneSelectorCoopScene.h"

#include "Level1Scene.h"
#include "Level2Scene.h"
#include "Level3Scene.h"
#include "MainMenuScene.h"
#include "ResourceManager.h"

SceneSelectorCoopScene::SceneSelectorCoopScene()
	: Scene(L"SceneSelectorCoopScene")
	, m_pInputManager(InputManager::GetInstance())
	, m_BackButton({ 422, 423 }, "BackButtonS.png", "BackButtonNS.png")
	, m_Level1Button({ 256, 300 }, "Level1ButtonS.png", "Level1ButtonNS.png")
	, m_Level2Button({ 256, 341 }, "Level2ButtonS.png", "Level2ButtonNS.png")
	, m_Level3Button({ 256, 382 }, "Level3ButtonS.png", "Level3ButtonNS.png")
	, m_pMainMenuBackGround(nullptr)
{
	
}

SceneSelectorCoopScene::~SceneSelectorCoopScene()
{
	
}

void SceneSelectorCoopScene::Initialize()
{
	m_pMainMenuBackGround = ResourceManager::GetInstance()->LoadTexture("CoopSelectorBackGround.png");

	m_BackButton.Initialize();
	m_Level1Button.Initialize();
	m_Level2Button.Initialize();
	m_Level3Button.Initialize();
}

void SceneSelectorCoopScene::Update()
{
	glm::vec2 mousePos = { m_pInputManager->GetMousePos() };

	m_Level1Button.Update(mousePos);
	m_Level2Button.Update(mousePos);
	m_Level3Button.Update(mousePos);
	m_BackButton.Update(mousePos);

	if (m_pInputManager->IsMouseButtonPressed(MOUSE_LEFT))
	{
		if (m_Level1Button.OnClick())
		{
			SceneManager::GetInstance()->AddScene(new Level1Scene());
			SceneManager::GetInstance()->SetActiveScene(L"Level1Scene");
		}
		if (m_Level2Button.OnClick())
		{
			SceneManager::GetInstance()->AddScene(new Level2Scene());
			SceneManager::GetInstance()->SetActiveScene(L"Level2Scene");
		}
		if (m_Level3Button.OnClick())
		{
			SceneManager::GetInstance()->AddScene(new Level3Scene());
			SceneManager::GetInstance()->SetActiveScene(L"Level3Scene");
		}
		if (m_BackButton.OnClick())
		{
			SceneManager::GetInstance()->SetActiveScene(L"MainMenuScene");
		}
	}
}

void SceneSelectorCoopScene::Render()
{
	Renderer::GetInstance()->RenderTexture(m_pMainMenuBackGround->GetSDLTexture(), 0, 0);

	m_Level1Button.Render();
	m_Level2Button.Render();
	m_Level3Button.Render();
	m_BackButton.Render();
}