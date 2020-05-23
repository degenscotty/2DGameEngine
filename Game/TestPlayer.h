#pragma once
#include "GameObject.h"
#include "InputManager.h"

class TestPlayer
{
public:
	TestPlayer();
	~TestPlayer();

	//TestPlayer(const TestPlayer& other) = delete;
	//TestPlayer(TestPlayer&& other) = delete;
	//TestPlayer& operator=(const TestPlayer& other) = delete;
	//TestPlayer& operator=(TestPlayer&& other) = delete;

	void Initialize();
	void Update();
	void Render();

	GameObject* GetGameObject();
private:
	InputManager* m_pInputManager;
	
	GameObject* m_pTestPlayer;
};

