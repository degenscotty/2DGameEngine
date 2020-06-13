#include "SceneSelectorCoopScene.h"

#include "LevelScene.h"

SceneSelectorCoopScene::SceneSelectorCoopScene()
	: Scene(L"SceneSelectorCoopScene")
	, m_pLevel1ButtonComponent(nullptr)
	, m_pLevel2ButtonComponent(nullptr)
	, m_pLevel3ButtonComponent(nullptr)
	, m_pBackButtonComponent(nullptr)
{

}

SceneSelectorCoopScene::~SceneSelectorCoopScene()
{

}

void SceneSelectorCoopScene::Initialize()
{
	auto* mainMenuBackGround = new GameObject();
	mainMenuBackGround->AddComponent(new TextureComponent("CoopSelectorBackGround.png"));
	Add(mainMenuBackGround);

	auto* level1Button = new GameObject();
	m_pLevel1ButtonComponent = new ButtonComponent("Level1ButtonS.png", "Level1ButtonNS.png");
	level1Button->AddComponent(m_pLevel1ButtonComponent);
	level1Button->GetTransform()->Translate(256, 300);

	Add(level1Button);

	auto* level2Button = new GameObject();
	m_pLevel2ButtonComponent = new ButtonComponent("Level2ButtonS.png", "Level2ButtonNS.png");
	level2Button->AddComponent(m_pLevel2ButtonComponent);
	level2Button->GetTransform()->Translate(256, 341);

	Add(level2Button);

	auto* level3Button = new GameObject();
	m_pLevel3ButtonComponent = new ButtonComponent("Level3ButtonS.png", "Level3ButtonNS.png");
	level3Button->AddComponent(m_pLevel3ButtonComponent);
	level3Button->GetTransform()->Translate(256, 382);

	Add(level3Button);

	auto* backButton = new GameObject();
	m_pBackButtonComponent = new ButtonComponent("BackButtonS.png", "BackButtonNS.png");
	backButton->AddComponent(m_pBackButtonComponent);
	backButton->GetTransform()->Translate(422, 423);

	Add(backButton);
}

void SceneSelectorCoopScene::Update()
{
	if (m_pLevel1ButtonComponent->OnClick())
	{
		SceneManager::GetInstance()->AddScene(new LevelScene(1));
		SceneManager::GetInstance()->SetActiveScene(L"LevelScene");
	}
	if (m_pLevel2ButtonComponent->OnClick())
	{
		SceneManager::GetInstance()->AddScene(new LevelScene(2));
		SceneManager::GetInstance()->SetActiveScene(L"LevelScene");
	}
	if (m_pLevel3ButtonComponent->OnClick())
	{
		SceneManager::GetInstance()->AddScene(new LevelScene(3));
		SceneManager::GetInstance()->SetActiveScene(L"LevelScene");
	}
	if (m_pBackButtonComponent->OnClick())
	{
		SceneManager::GetInstance()->SetActiveScene(L"MainMenuScene");
	}
}

void SceneSelectorCoopScene::Render()
{
}