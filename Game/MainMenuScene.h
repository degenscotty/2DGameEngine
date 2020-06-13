#pragma once
#include "ButtonComponent.h"
#include "Scene.h"

#include "InputManager.h"

class MainMenuScene final : public Scene
{
public:
	MainMenuScene();
	~MainMenuScene();

	MainMenuScene(const MainMenuScene& other) = delete;
	MainMenuScene(MainMenuScene&& other) = delete;
	MainMenuScene& operator=(const MainMenuScene& other) = delete;
	MainMenuScene& operator=(MainMenuScene&& other) = delete;

protected:
	void Initialize() override;
	void Update() override;
	void Render() override;

private:
	InputManager* m_pInputManager;
	
	ButtonComponent* m_pPlayButtonComponent;
	ButtonComponent* m_pVersusButtonComponent;
	ButtonComponent* m_pCoopButtonComponent;
	ButtonComponent* m_pExitButtonComponent;
};

