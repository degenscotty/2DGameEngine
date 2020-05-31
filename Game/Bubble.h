#pragma once
#include "BubbleComponent.h"
#include "GameObject.h"

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

	GameObject* GetGameObject() const;

private:
	GameObject* m_pBubble;
	BubbleComponent* m_pBubbleComponent;
	SpriteComponent* m_pSpriteComponent;
};

