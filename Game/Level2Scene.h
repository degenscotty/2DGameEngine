#pragma once
#include "Scene.h"
#include "BobblePlayer.h"
#include "LevelManager.h"
#include "PopUpManager.h"
#include "ScoreManager.h"

class Level2Scene final : public Scene
{
public:
	Level2Scene();
	~Level2Scene();

	Level2Scene(const Level2Scene& other) = delete;
	Level2Scene(Level2Scene&& other) = delete;
	Level2Scene& operator=(const Level2Scene& other) = delete;
	Level2Scene& operator=(Level2Scene&& other) = delete;

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
};

