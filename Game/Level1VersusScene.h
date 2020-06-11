#pragma once
#include "Scene.h"

class Level1VersusScene final : public Scene
{
public:
	Level1VersusScene();
	~Level1VersusScene();

	Level1VersusScene(const Level1VersusScene& other) = delete;
	Level1VersusScene(Level1VersusScene&& other) = delete;
	Level1VersusScene& operator=(const Level1VersusScene& other) = delete;
	Level1VersusScene& operator=(Level1VersusScene&& other) = delete;

protected:
	void Initialize() override;
	void Update() override;
	void Render() override;
	
private:
};

