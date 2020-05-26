#pragma once
#include <map>

#include "GameObject.h"
#include "MaitaState.h"
#include "StateComponent.h"

class EnemyMaita
{
public:
	EnemyMaita();
	~EnemyMaita();

	EnemyMaita(const EnemyMaita& other) = delete;
	EnemyMaita(EnemyMaita&& other) = delete;
	EnemyMaita& operator=(const EnemyMaita& other) = delete;
	EnemyMaita& operator=(EnemyMaita&& other) = delete;

	void Initialize();
	void Update() const;
	void Render() const;

	void SetAnimationClip(int index) const;
	void ChangeState(const std::string& newState);
	void SetFlipState(const SDL_RendererFlip& flip) const;
	void SetPosition(const glm::vec2& position);

	GameObject* GetGameObject() const;
private:
	GameObject* m_pEnemyMaita;
	SpriteComponent* m_pSpriteComponent;
	StateComponent* m_pStateComponent;
};

