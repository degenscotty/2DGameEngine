#pragma once
#include "GameObject.h"
#include "StateComponent.h"

class Maita
{
public:
	Maita();
	~Maita();

	Maita(const Maita& other) = delete;
	Maita(Maita&& other) = delete;
	Maita& operator=(const Maita& other) = delete;
	Maita& operator=(Maita&& other) = delete;

	void Initialize();
	void Update() const;
	void Render() const;

	void SetAnimationClip(int index) const;
	void ChangeState(const std::string& newState);
	void SetFlipState(const SDL_RendererFlip& flip) const;
	void SetPosition(const glm::vec2& position);

	GameObject* GetGameObject() const;
	glm::vec2 GetPosition();
	bool GetCanJump() { return m_CanJump; }
	void SetJump(bool canJump);

	void OnTrigger(GameObject* other);
private:
	TransformComponent* m_pTransformComponent;
	GameObject* m_pEnemyMaita;
	SpriteComponent* m_pSpriteComponent;
	StateComponent* m_pStateComponent;

	bool m_CanJump;
};

