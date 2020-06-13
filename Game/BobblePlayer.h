#pragma once
#include "SpriteComponent.h"

class GameObject;

class BobblePlayer
{
public:
	BobblePlayer() = default;
	virtual ~BobblePlayer() = default;

	BobblePlayer(const BobblePlayer& other) = delete;
	BobblePlayer(BobblePlayer&& other) = delete;
	BobblePlayer& operator=(const BobblePlayer& other) = delete;
	BobblePlayer& operator=(BobblePlayer&& other) = delete;

	virtual void Initialize() = 0;
	virtual void Update() const = 0;
	virtual void Render() const = 0;

	virtual void SetAnimationClip(int index) const = 0;
	virtual void ChangeState(const std::string& newState) = 0;
	virtual void SetFlipState(const SDL_RendererFlip& flip) const = 0;
	virtual const SDL_RendererFlip& GetFlipState() = 0;
	virtual void SetPosition(const glm::vec2& position) = 0;
	virtual const glm::vec2& GetPosition() = 0;

	virtual GameObject* GetGameObject() const = 0;

	virtual bool CheckDead() = 0;
	virtual void SetIsRespawning(bool respawn) = 0;
	virtual bool GetIsRespawning() = 0;
	virtual void EnableEnemyCollision() = 0;

	virtual void OnTrigger(GameObject* other, bool trigger) {};

private:
};

