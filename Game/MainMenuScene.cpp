#include "MainMenuScene.h"
#include "ResourceManager.h"
#include "SceneSelectorCoopScene.h"
#include "SceneSelectorScene.h"
#include "SceneSelectorVersusScene.h"

MainMenuScene::MainMenuScene()
	: Scene(L"MainMenuScene")
	, m_pInputManager(InputManager::GetInstance())
	, m_PlayButton({ 256, 300 }, "PlayButtonS.png", "PlayButtonNS.png")
	, m_VersusButton({ 256, 341 }, "VersusButtonS.png", "VersusButtonNS.png")
	, m_CoopButton({ 256, 382 }, "CoopButtonS.png", "CoopButtonNS.png")
	, m_ExitButton({ 422,423 }, "ExitButtonS.png", "ExitButtonNS.png")
	, m_pMainMenuBackGround(nullptr)
{

}

MainMenuScene::~MainMenuScene()
{

}

void MainMenuScene::Initialize()
{
	m_pMainMenuBackGround = ResourceManager::GetInstance()->LoadTexture("MainMenuBackGround.png");
	
	m_PlayButton.Initialize();
	m_VersusButton.Initialize();
	m_CoopButton.Initialize();
	m_ExitButton.Initialize();
}

void MainMenuScene::Update()
{
	glm::vec2 mousePos = { m_pInputManager->GetMousePos() };
	
	m_PlayButton.Update(mousePos);
	m_VersusButton.Update(mousePos);
	m_CoopButton.Update(mousePos);
	m_ExitButton.Update(mousePos);
	
	if (m_pInputManager->IsMouseButtonPressed(MOUSE_LEFT))
	{
		if (m_PlayButton.OnClick())
		{
			SceneManager::GetInstance()->AddScene(new SceneSelectorScene());
			SceneManager::GetInstance()->SetActiveScene(L"SceneSelectorScene");
		}
		if (m_VersusButton.OnClick())
		{
			SceneManager::GetInstance()->AddScene(new SceneSelectorVersusScene());
			SceneManager::GetInstance()->SetActiveScene(L"SceneSelectorVersusScene");
		}
		if (m_CoopButton.OnClick())
		{
			SceneManager::GetInstance()->AddScene(new SceneSelectorCoopScene());
			SceneManager::GetInstance()->SetActiveScene(L"SceneSelectorCoopScene");
		}
		if (m_ExitButton.OnClick())
		{
			m_pInputManager->QuitGame();
		}
	}
}

void MainMenuScene::Render()
{
	Renderer::GetInstance()->RenderTexture(m_pMainMenuBackGround->GetSDLTexture(), 0, 0);
	
	m_ExitButton.Render();
	m_PlayButton.Render();
	m_VersusButton.Render();
	m_CoopButton.Render();
}