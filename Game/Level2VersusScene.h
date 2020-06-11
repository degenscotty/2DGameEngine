#pragma once
#include "Scene.h"

class Level2VersusScene final : public Scene
{
public:
	Level2VersusScene();
	~Level2VersusScene();

	Level2VersusScene(const Level2VersusScene& other) = delete;
	Level2VersusScene(Level2VersusScene&& other) = delete;
	Level2VersusScene& operator=(const Level2VersusScene& other) = delete;
	Level2VersusScene& operator=(Level2VersusScene&& other) = delete;

protected:
	void Initialize() override;
	void Update() override;
	void Render() override;

private:
};

