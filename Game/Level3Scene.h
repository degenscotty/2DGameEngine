#pragma once
#include "Scene.h"
#include "BobblePlayer.h"
#include "LevelManager.h"
#include "PopUpManager.h"
#include "ScoreManager.h"

class Level3Scene final : public Scene
{
public:
	Level3Scene();
	~Level3Scene();

	Level3Scene(const Level3Scene& other) = delete;
	Level3Scene(Level3Scene&& other) = delete;
	Level3Scene& operator=(const Level3Scene& other) = delete;
	Level3Scene& operator=(Level3Scene&& other) = delete;

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

