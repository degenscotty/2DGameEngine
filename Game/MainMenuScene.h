#pragma once
#include "Scene.h"

#include "Button.h"
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
	Button m_Level1Button;
	Button m_ExitButton;
};

