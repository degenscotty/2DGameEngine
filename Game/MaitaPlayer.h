#pragma once
#include "SpriteComponent.h"
#include "ControllerComponent.h"
#include "GameObject.h"
#include "InputManager.h"
#include "StateComponent.h"

class GameObject;

class MaitaPlayer final
{
public:
	MaitaPlayer();
	~MaitaPlayer() = default;

	MaitaPlayer(const MaitaPlayer& other) = delete;
	MaitaPlayer(MaitaPlayer&& other) = delete;
	MaitaPlayer& operator=(const MaitaPlayer& other) = delete;
	MaitaPlayer& operator=(MaitaPlayer&& other) = delete;

	void Initialize();
	void Update() const;
	void Render() const;

	void SetAnimationClip(int index) const;
	void ChangeState(const std::string& newState);
	void SetFlipState(const SDL_RendererFlip& flip) const;
	const SDL_RendererFlip& GetFlipState() const;
	void SetPosition(const glm::vec2& position) const;
	const glm::vec2& GetPosition() const;

	GameObject* GetGameObject() const;

	void OnTrigger(GameObject* other, bool trigger);

private:
	InputManager* m_pInputManager;
	
	GameObject* m_pMaitaPlayer;
	ControllerComponent* m_pControllerComponent;
	CollisionComponent* m_pCollisionComponent;
	SpriteComponent* m_pSpriteComponent;
	StateComponent* m_pStateComponent;
};

