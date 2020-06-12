#include "Application.h"
#include "GameOverScene.h"
#include "MainMenuScene.h"
#include "SceneSelectorCoopScene.h"
#include "SceneSelectorScene.h"
#include "SceneSelectorVersusScene.h"

class SandboxApplication : public Application
{
public:
	SandboxApplication()
	{
		SceneManager::GetInstance()->AddScene(new MainMenuScene());
		SceneManager::GetInstance()->AddScene(new SceneSelectorScene());
		SceneManager::GetInstance()->AddScene(new SceneSelectorCoopScene());
		SceneManager::GetInstance()->AddScene(new SceneSelectorVersusScene());
		SceneManager::GetInstance()->AddScene(new GameOverScene());
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
