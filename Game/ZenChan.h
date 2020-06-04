#pragma once
#include "GameObject.h"
#include "SpriteComponent.h"
#include "ControllerComponent.h"
#include "StateComponent.h"
#include "TransformComponent.h"

class ZenChan
{
public:
	ZenChan();
	~ZenChan();

	ZenChan(const ZenChan& other) = delete;
	ZenChan(ZenChan&& other) = delete;
	ZenChan& operator=(const ZenChan& other) = delete;
	ZenChan& operator=(ZenChan&& other) = delete;

	void Initialize();
	void Update() const;
	void Render() const;

	void SetAnimationClip(int index) const;
	void ChangeState(const std::string& newState);
	void SetFlipState(const SDL_RendererFlip& flip) const;
	void SetPosition(const glm::vec2& position);

	GameObject* GetGameObject();
	glm::vec2 GetPosition();
	bool GetCanJump() { return m_CanJump; }
	void SetJump(bool canJump);

	void OnTrigger(GameObject* other, bool trigger);
private:
	TransformComponent* m_pTransformComponent;
	GameObject* m_pZenChan;
	SpriteComponent* m_pSpriteComponent;
	StateComponent* m_pStateComponent;
	ControllerComponent* m_pControllerComnponent;

	bool m_CanJump;
};

