#pragma once
#include "Scene.h"
#include "LevelManager.h"
#include "PopUpManager.h"
#include "ScoreManager.h"

class LevelVersusScene final : public Scene
{
public:
	LevelVersusScene(int levelNumber);
	~LevelVersusScene();

	LevelVersusScene(const LevelVersusScene& other) = delete;
	LevelVersusScene(LevelVersusScene&& other) = delete;
	LevelVersusScene& operator=(const LevelVersusScene& other) = delete;
	LevelVersusScene& operator=(LevelVersusScene&& other) = delete;

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

