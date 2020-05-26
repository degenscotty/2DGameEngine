#pragma once
#include <map>

#include "GameObject.h"
#include "SnailState.h"

class EnemySnail
{
public:
	EnemySnail();
	~EnemySnail();

	EnemySnail(const EnemySnail& other) = delete;
	EnemySnail(EnemySnail&& other) = delete;
	EnemySnail& operator=(const EnemySnail& other) = delete;
	EnemySnail& operator=(EnemySnail&& other) = delete;

	void Initialize();
	void Update() const;
	void Render() const;

	void SetAnimationClip(int index) const;
	void ChangeState(const std::string& newState);
	void SetFlipState(const SDL_RendererFlip& flip) const;
	void SetPosition(const glm::vec2& position);

	GameObject* GetGameObject() const;
private:
	GameObject* m_pEnemySnail;
	SpriteComponent* m_pSpriteComponent;

	std::map<std::string, SnailState*> m_pStateMap;
	SnailState* m_pState;
};

