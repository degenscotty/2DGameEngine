#pragma once
#include "Scene.h"

#include "Button.h"
#include "InputManager.h"

class SceneSelectorCoopScene final : public Scene
{
public:
	SceneSelectorCoopScene();
	~SceneSelectorCoopScene();

	SceneSelectorCoopScene(const SceneSelectorCoopScene& other) = delete;
	SceneSelectorCoopScene(SceneSelectorCoopScene&& other) = delete;
	SceneSelectorCoopScene& operator=(const SceneSelectorCoopScene& other) = delete;
	SceneSelectorCoopScene& operator=(SceneSelectorCoopScene&& other) = delete;

protected:
	void Initialize() override;
	void Update() override;
	void Render() override;
	
private:
	InputManager* m_pInputManager;

	Button m_BackButton;
	Button m_Level1Button;
	Button m_Level2Button;
	Button m_Level3Button;

	Texture2D* m_pMainMenuBackGround;
};

