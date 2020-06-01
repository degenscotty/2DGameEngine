#pragma once
#include "GameObject.h"
#include "StateComponent.h"
#include "BubbleComponent.h"
#include "SpriteComponent.h"
#include "GarbageCollector.h"

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
	void Update() const;
	void Render() const;

	void SetPosition(const glm::vec2& position);
	void ShootBubble(bool right);

	void SetAnimationClip(int index) const;
	void ChangeState(const std::string& newState);

	void SetActive(bool active) { m_Active = active; }

	GameObject* GetGameObject() const;

	void OnTrigger(GameObject* pGameObject, bool trigger);

private:
	GameObject* m_pBubble;
	BubbleComponent* m_pBubbleComponent;
	SpriteComponent* m_pSpriteComponent;
	StateComponent* m_pStateComponent;
	GarbageCollector* m_pGarbageCollector;

	bool m_Active;
};

