#include "MainMenuScene.h"
#include "ResourceManager.h"
#include "ScoreManager.h"

MainMenuScene::MainMenuScene()
	: Scene(L"MainMenuScene")
	, m_pInputManager(InputManager::GetInstance())
	, m_pPlayButtonComponent(nullptr)
	, m_pVersusButtonComponent(nullptr)
	, m_pCoopButtonComponent(nullptr)
	, m_pExitButtonComponent(nullptr)
{

}

MainMenuScene::~MainMenuScene()
{
	ScoreManager::DestroyInstance();
}

void MainMenuScene::Initialize()
{
	auto* mainMenuBackGround = new GameObject();
	mainMenuBackGround->AddComponent(new TextureComponent("MainMenuBackGround.png"));
	Add(mainMenuBackGround);

	auto* playButton = new GameObject();
	m_pPlayButtonComponent = new ButtonComponent("PlayButtonS.png", "PlayButtonNS.png");
	playButton->AddComponent(m_pPlayButtonComponent);
	playButton->GetTransform()->Translate(256, 300);

	Add(playButton);

	auto* versusButton = new GameObject();
	m_pVersusButtonComponent = new ButtonComponent("VersusButtonS.png", "VersusButtonNS.png");
	versusButton->AddComponent(m_pVersusButtonComponent);
	versusButton->GetTransform()->Translate(256, 341);

	Add(versusButton);

	auto* coopButton = new GameObject();
	m_pCoopButtonComponent = new ButtonComponent("CoopButtonS.png", "CoopButtonNS.png");
	coopButton->AddComponent(m_pCoopButtonComponent);
	coopButton->GetTransform()->Translate(256, 382);

	Add(coopButton);

	auto* exitButton = new GameObject();
	m_pExitButtonComponent = new ButtonComponent("ExitButtonS.png", "ExitButtonNS.png");
	exitButton->AddComponent(m_pExitButtonComponent);
	exitButton->GetTransform()->Translate(422, 423);

	Add(exitButton);
}

void MainMenuScene::Update()
{
	if (m_pPlayButtonComponent->OnClick())
	{
		SceneManager::GetInstance()->SetActiveScene(L"SceneSelectorScene");
	}
	if (m_pVersusButtonComponent->OnClick())
	{
		SceneManager::GetInstance()->SetActiveScene(L"SceneSelectorVersusScene");
	}
	if (m_pCoopButtonComponent->OnClick())
	{
		SceneManager::GetInstance()->SetActiveScene(L"SceneSelectorCoopScene");
	}
	if (m_pExitButtonComponent->OnClick())
	{
		m_pInputManager->QuitGame();
	}
}

void MainMenuScene::Render()
{
}