#pragma once
#include "GameObject.h"
#include "InputManager.h"
#include "SpriteComponent.h"
#include "StateComponent.h"

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
	void Update() const;
	void Render() const;

	void SetAnimationClip(int index) const;
	void ChangeState(const std::string& newState);
	void SetFlipState(const SDL_RendererFlip& flip) const;
	void SetPosition(const glm::vec2& position);

	GameObject* GetGameObject() const;
private:
	InputManager* m_pInputManager;
	GameObject* m_pBobblePlayer;
	SpriteComponent* m_pSpriteComponent;
	StateComponent* m_pStateComponent;
};

