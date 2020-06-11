#pragma once
#include "Scene.h"

class Level3VersusScene final : public Scene
{
public:
	Level3VersusScene();
	~Level3VersusScene();

	Level3VersusScene(const Level3VersusScene& other) = delete;
	Level3VersusScene(Level3VersusScene&& other) = delete;
	Level3VersusScene& operator=(const Level3VersusScene& other) = delete;
	Level3VersusScene& operator=(Level3VersusScene&& other) = delete;

protected:
	void Initialize() override;
	void Update() override;
	void Render() override;

private:
};

