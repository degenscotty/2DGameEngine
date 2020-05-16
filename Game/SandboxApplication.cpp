#include "Application.h"
#include "TestScene.h"

class SandboxApplication : public Application
{
public:
	SandboxApplication()
	{
		Scene* testScene{ new TestScene() };
		SceneManager::GetInstance()->AddScene(testScene);
	}

	~SandboxApplication()
	{
	}
};

Application* CreateApplication()
{
	return new SandboxApplication();
}
