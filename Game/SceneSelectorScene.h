#pragma once
#include "Scene.h"

#include "Button.h"
#include "InputManager.h"

class SceneSelectorScene final : public Scene
{
public:
	SceneSelectorScene();
	~SceneSelectorScene();

	SceneSelectorScene(const SceneSelectorScene& other) = delete;
	SceneSelectorScene(SceneSelectorScene&& other) = delete;
	SceneSelectorScene& operator=(const SceneSelectorScene& other) = delete;
	SceneSelectorScene& operator=(SceneSelectorScene&& other) = delete;

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

