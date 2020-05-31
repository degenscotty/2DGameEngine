#pragma once
#include "Scene.h"
#include "BobblePlayer.h"
#include "LevelManager.h"

class Level1Scene final : public Scene
{
public:
	Level1Scene();
	~Level1Scene();

	Level1Scene(const Level1Scene& other) = delete;
	Level1Scene(Level1Scene&& other) = delete;
	Level1Scene& operator=(const Level1Scene& other) = delete;
	Level1Scene& operator=(Level1Scene&& other) = delete;

protected:
	void Initialize() override;
	void Update() override;
	void Render() override;

private:
	BobblePlayer* m_pBobblePlayer;
	GameObject* m_pFPSCounter;
	LevelManager* m_pLevelManager;
};

