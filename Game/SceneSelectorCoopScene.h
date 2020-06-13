#pragma once
#include "Scene.h"

#include "ButtonComponent.h"

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
	ButtonComponent* m_pLevel1ButtonComponent;
	ButtonComponent* m_pLevel2ButtonComponent;
	ButtonComponent* m_pLevel3ButtonComponent;
	ButtonComponent* m_pBackButtonComponent;
};

