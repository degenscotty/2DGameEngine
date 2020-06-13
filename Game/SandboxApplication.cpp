#include "Application.h"
#include "GameOverScene.h"
#include "MainMenuScene.h"
#include "SceneSelectorCoopScene.h"
#include "SceneSelectorScene.h"
#include "SceneSelectorVersusScene.h"
#include "YouWinScene.h"

class SandboxApplication : public Application
{
public:
	SandboxApplication()
	{
		SceneManager::GetInstance()->AddScene(new MainMenuScene());
		SceneManager::GetInstance()->AddScene(new YouWinScene());
		SceneManager::GetInstance()->AddScene(new GameOverScene());
		SceneManager::GetInstance()->AddScene(new SceneSelectorScene());
		SceneManager::GetInstance()->AddScene(new SceneSelectorCoopScene());
		SceneManager::GetInstance()->AddScene(new SceneSelectorVersusScene());
		SceneManager::GetInstance()->SetActiveScene(L"MainMenuScene");
	}

	~SandboxApplication()
	{
	}
};

Application* CreateApplication()
{
	return new SandboxApplication();
}
