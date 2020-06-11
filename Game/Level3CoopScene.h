#pragma once
#include "Scene.h"

class Level3CoopScene final : public Scene
{
public:
	Level3CoopScene();
	~Level3CoopScene();

	Level3CoopScene(const Level3CoopScene& other) = delete;
	Level3CoopScene(Level3CoopScene&& other) = delete;
	Level3CoopScene& operator=(const Level3CoopScene& other) = delete;
	Level3CoopScene& operator=(Level3CoopScene&& other) = delete;

protected:
	void Initialize() override;
	void Update() override;
	void Render() override;

private:
};

