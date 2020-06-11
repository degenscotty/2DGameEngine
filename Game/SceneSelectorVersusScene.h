#pragma once
#include "Scene.h"

#include "Button.h"
#include "InputManager.h"

class SceneSelectorVersusScene final : public Scene
{
public:
	SceneSelectorVersusScene();
	~SceneSelectorVersusScene();

	SceneSelectorVersusScene(const SceneSelectorVersusScene& other) = delete;
	SceneSelectorVersusScene(SceneSelectorVersusScene&& other) = delete;
	SceneSelectorVersusScene& operator=(const SceneSelectorVersusScene& other) = delete;
	SceneSelectorVersusScene& operator=(SceneSelectorVersusScene&& other) = delete;

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

