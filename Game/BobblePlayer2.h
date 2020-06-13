#pragma once
#include "BobblePlayer.h"
#include "ControllerComponent.h"
#include "GameObject.h"
#include "InputManager.h"
#include "StateComponent.h"

class Bubble;

class BobblePlayer2 : public BobblePlayer
{
public:
	BobblePlayer2();
	~BobblePlayer2();

	BobblePlayer2(const BobblePlayer2& other) = delete;
	BobblePlayer2(BobblePlayer2&& other) = delete;
	BobblePlayer2& operator=(const BobblePlayer2& other) = delete;
	BobblePlayer2& operator=(BobblePlayer2&& other) = delete;

	void Initialize() override;
	void Update() const override;
	void Render() const override;

	void SetAnimationClip(int index) const override;
	void ChangeState(const std::string& newState) override;
	void SetFlipState(const SDL_RendererFlip& flip) const override;
	const SDL_RendererFlip& GetFlipState() override;
	void SetPosition(const glm::vec2& position) override;
	const glm::vec2& GetPosition() override;

	GameObject* GetGameObject() const override;

	bool CheckDead() override { return m_Lives <= 0; }
	void SetIsRespawning(bool respawn) override { m_IsRespawning = respawn; }
	bool GetIsRespawning() override { return m_IsRespawning; }
	void EnableEnemyCollision() override;

	int GetPlayerID() { return m_PlayerID; }

	void OnTrigger(GameObject* other, bool trigger) override;
private:
	InputManager* m_pInputManager;
	GameObject* m_pBobblePlayer;
	ControllerComponent* m_pControllerComponent;
	CollisionComponent* m_pCollisionComponent;
	SpriteComponent* m_pSpriteComponent;
	StateComponent* m_pStateComponent;

	int m_PlayerID;
	int m_Lives;
	bool m_IsRespawning;
};

