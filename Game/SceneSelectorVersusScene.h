#pragma once
#include "Scene.h"

#include "ButtonComponent.h"

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
	ButtonComponent* m_pLevel1ButtonComponent;
	ButtonComponent* m_pLevel2ButtonComponent;
	ButtonComponent* m_pLevel3ButtonComponent;
	ButtonComponent* m_pBackButtonComponent;
};

