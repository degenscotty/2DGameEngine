#pragma once
#include "BaseComponent.h"
#include "GameTime.h"

#include <glm.hpp>

class BubbleComponent : public BaseComponent
{
public:
	BubbleComponent();
	~BubbleComponent();

	BubbleComponent(const BubbleComponent& other) = delete;
	BubbleComponent(BubbleComponent&& other) noexcept = delete;
	BubbleComponent& operator=(const BubbleComponent& other) = delete;
	BubbleComponent& operator=(BubbleComponent&& other) noexcept = delete;

	void SetActive(bool active) { m_Active = active; }

	void ShootBubble(bool right);

protected:
	void Initialize() override;
	void Update() override;
	void Render() override;

public:
	TransformComponent* m_pTransformComponent;
	GameTime* m_pGameTime;

	float m_BubbleUpForce;
	glm::vec2 m_BubbleVelocity;
	float m_BubbleSideForce;

	bool m_Active;
};

