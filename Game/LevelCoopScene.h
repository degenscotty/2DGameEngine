#pragma once
#include "Scene.h"

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
	int m_LevelNumber;
};

