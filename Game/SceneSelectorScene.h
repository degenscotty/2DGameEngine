#pragma once
#include "Scene.h"

#include "ButtonComponent.h"


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
	ButtonComponent* m_pLevel1ButtonComponent;
	ButtonComponent* m_pLevel2ButtonComponent;
	ButtonComponent* m_pLevel3ButtonComponent;
	ButtonComponent* m_pBackButtonComponent;
};

