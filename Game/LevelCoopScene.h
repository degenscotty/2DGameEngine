#pragma once
#include "Scene.h"
#include "LevelManager.h"
#include "PopUpManager.h"
#include "ScoreManager.h"

class LevelCoopScene final : public Scene
{
public:
	LevelCoopScene(int levelNumber);
	~LevelCoopScene();

	LevelCoopScene(const LevelCoopScene& other) = delete;
	LevelCoopScene(LevelCoopScene&& other) = delete;
	LevelCoopScene& operator=(const LevelCoopScene& other) = delete;
	LevelCoopScene& operator=(LevelCoopScene&& other) = delete;

protected:
	void Initialize() override;
	void Update() override;
	void Render() override;
	
private:
	GameObject* m_pFPSCounter;
	LevelManager* m_pLevelManager;
	ScoreManager* m_pScoreManager;
	PopUpManager* m_pPopUpManager;
	
	int m_LevelNumber;
};

