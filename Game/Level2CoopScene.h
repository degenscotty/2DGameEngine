#pragma once
#include "Scene.h"

class Level2CoopScene final : public Scene
{
public:
	Level2CoopScene();
	~Level2CoopScene();

	Level2CoopScene(const Level2CoopScene& other) = delete;
	Level2CoopScene(Level2CoopScene&& other) = delete;
	Level2CoopScene& operator=(const Level2CoopScene& other) = delete;
	Level2CoopScene& operator=(Level2CoopScene&& other) = delete;

protected:
	void Initialize() override;
	void Update() override;
	void Render() override;

private:
};

