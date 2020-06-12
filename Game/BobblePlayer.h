#pragma once
#include "ControllerComponent.h"
#include "GameObject.h"
#include "InputManager.h"
#include "SpriteComponent.h"
#include "StateComponent.h"

class Bubble;

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
	const SDL_RendererFlip& GetFlipState();
	void SetPosition(const glm::vec2& position);
	const glm::vec2& GetPosition();

	GameObject* GetGameObject() const;

	bool CheckDead() { return m_Lives <= 0; }
	void SetIsRespawning(bool respawn) { m_IsRespawning = respawn; }
	bool GetIsRespawning() { return m_IsRespawning; }
	void EnableEnemyCollision();

	void OnTrigger(GameObject* other, bool trigger);
private:
	InputManager* m_pInputManager;
	GameObject* m_pBobblePlayer;
	ControllerComponent* m_pControllerComponent;
	CollisionComponent* m_pCollisionComponent;
	SpriteComponent* m_pSpriteComponent;
	StateComponent* m_pStateComponent;

	int m_Lives;
	bool m_IsRespawning;
};

