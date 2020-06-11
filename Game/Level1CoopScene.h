#pragma once
#include "Scene.h"

class Level1CoopScene final : public Scene
{
public:
	Level1CoopScene();
	~Level1CoopScene();

	Level1CoopScene(const Level1CoopScene& other) = delete;
	Level1CoopScene(Level1CoopScene&& other) = delete;
	Level1CoopScene& operator=(const Level1CoopScene& other) = delete;
	Level1CoopScene& operator=(Level1CoopScene&& other) = delete;

protected:
	void Initialize() override;
	void Update() override;
	void Render() override;
	
private:
};

