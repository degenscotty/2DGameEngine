#include "Application.h"
#include "MainMenuScene.h"

class SandboxApplication : public Application
{
public:
	SandboxApplication()
	{
		SceneManager::GetInstance()->AddScene(new MainMenuScene());
	}

	~SandboxApplication()
	{
	}
};

Application* CreateApplication()
{
	return new SandboxApplication();
}
