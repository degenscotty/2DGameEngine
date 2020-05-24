#pragma once
#include <map>

#include "BobbleState.h"
#include "GameObject.h"
#include "InputManager.h"
#include "SpriteComponent.h"

class BobblePlayer
{
public:
	BobblePlayer();
	~BobblePlayer();

	BobblePlayer(const BobblePlayer& other) = delete;
	BobblePlayer(BobblePlayer&& other) = delete;
	BobblePlayer& operator=(const BobblePlayer& other) = delete;
	BobblePlayer& operator=(BobblePlayer&& other) = delete;

	void Initialize();
	void Update();
	void Render();

	void SetAnimationClip(int index);
	void ChangeState(const std::string& newState);

	GameObject* GetGameObject();
private:
	InputManager* m_pInputManager;
	GameObject* m_pBobblePlayer;
	SpriteComponent* m_pSpriteComponent;

	std::map<std::string, BobbleState*> m_pStateMap;
	BobbleState* m_pState;
};

