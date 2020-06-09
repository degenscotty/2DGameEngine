#pragma once
#include "GameObject.h"
#include "StateComponent.h"
#include "BubbleComponent.h"
#include "SpriteComponent.h"
#include "GarbageCollector.h"
#include "GameTime.h"
#include "LevelManager.h"

class Bubble
{
public:
	Bubble();
	~Bubble();

	Bubble(const Bubble& other) = delete;
	Bubble(Bubble&& other) = delete;
	Bubble& operator=(const Bubble& other) = delete;
	Bubble& operator=(Bubble&& other) = delete;

	void Initialize();
	void Update();
	void Render() const;

	void SetPosition(const glm::vec2& position);
	const glm::vec2& GetPosition();
	void ShootBubble(bool right);

	void SetAnimationClip(int index) const;
	void ChangeState(const std::string& newState);
	void PopBubble();

	void MoveToPopPosition(const glm::vec2& position);

	void SetBubblePopped() { m_BubblePopped = true; }

	void SetActive(bool active) { m_Active = active; }

	GameObject* GetGameObject() const;

	void OnTrigger(GameObject* other, bool trigger);

private:
	GameObject* m_pBubble;
	BubbleComponent* m_pBubbleComponent;
	SpriteComponent* m_pSpriteComponent;
	StateComponent* m_pStateComponent;
	GarbageCollector* m_pGarbageCollector;
	GameTime* m_pGameTime;
	LevelManager* m_pLevelManager;

	float m_ActiveTimer;
	float m_ActivationTime;
	bool m_Poppable;

	bool m_Active;
	bool m_BubblePopped;
};

