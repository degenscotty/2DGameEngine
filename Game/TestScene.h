#pragma once
#include "Scene.h"
#include "BobblePlayer.h"

class TestScene final : public Scene
{
public:
	TestScene();
	~TestScene();

	TestScene(const TestScene& other) = delete;
	TestScene(TestScene&& other) = delete;
	TestScene& operator=(const TestScene& other) = delete;
	TestScene& operator=(TestScene&& other) = delete;

protected:
	void Initialize() override;
	void Update() override;
	void Render() override;

private:
	BobblePlayer m_BobblePlayer;
	GameObject* m_pFPSCounter;
};

