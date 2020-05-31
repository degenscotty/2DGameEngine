#include "MainMenuScene.h"

#include "Level1Scene.h"

MainMenuScene::MainMenuScene()
	: Scene(L"MainMenuScene")
	, m_pInputManager(InputManager::GetInstance())
	, m_Level1Button({ 256, 156 }, "Level1ButtonS.png", "Level1ButtonNS.png")
	, m_ExitButton({ 256, 207 }, "ExitButtonS.png", "ExitButtonNS.png")
{

}

MainMenuScene::~MainMenuScene()
{

}

void MainMenuScene::Initialize()
{
	m_Level1Button.Initialize();
	m_ExitButton.Initialize();
}

void MainMenuScene::Update()
{
	glm::vec2 mousePos = { m_pInputManager->GetMousePos() };
	
	m_Level1Button.Update(mousePos);
	m_ExitButton.Update(mousePos);
	
	if (m_pInputManager->IsMouseButtonPressed(MOUSE_LEFT))
	{
		if (m_Level1Button.OnClick())
		{
			SceneManager::GetInstance()->AddScene(new Level1Scene());
			SceneManager::GetInstance()->SetActiveScene(L"Level1Scene");
		}
		if (m_ExitButton.OnClick())
		{
			m_pInputManager->QuitGame();
		}
	}
}

void MainMenuScene::Render()
{
	m_ExitButton.Render();
	m_Level1Button.Render();
}