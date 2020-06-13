#pragma once
#include "Scene.h"
#include "BobblePlayer.h"
#include "LevelManager.h"
#include "PopUpManager.h"
#include "ScoreManager.h"

class LevelScene final : public Scene
{
public:
	LevelScene(int levelNumber);
	~LevelScene();

	LevelScene(const LevelScene& other) = delete;
	LevelScene(LevelScene&& other) = delete;
	LevelScene& operator=(const LevelScene& other) = delete;
	LevelScene& operator=(LevelScene&& other) = delete;

protected:
	void Initialize() override;
	void Update() override;
	void Render() override;

private:
	BobblePlayer* m_pBobblePlayer;
	GameObject* m_pFPSCounter;
	LevelManager* m_pLevelManager;
	ScoreManager* m_pScoreManager;
	PopUpManager* m_pPopUpManager;

	int m_LevelNumber;
};

