#pragma once
#include "Scene.h"

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
	int m_LevelNumber;
};

