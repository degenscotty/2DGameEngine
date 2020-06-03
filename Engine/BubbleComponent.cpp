#include "pch.h"
#include "BubbleComponent.h"
#include "TransformComponent.h"

#include "utils.h"

BubbleComponent::BubbleComponent()
	: m_pTransformComponent(nullptr)
	, m_pGameTime(GameTime::GetInstance())
	, m_BubbleUpForce(-10)
	, m_BubbleVelocity({ 0, 0 })
	, m_BubbleSideForce(15)
	, m_Active(true)
{

}

BubbleComponent::~BubbleComponent()
{

}

void BubbleComponent::Initialize()
{
	if (m_pGameObject != nullptr)
		m_pTransformComponent = GetTransform();
	else
		CORE_ERROR("CollisionComponent::Initialize() > Cannot Initialize CollisionComponent, it is not attached to a GameObject");
}

void BubbleComponent::ShootBubble(bool right)
{
	if (right)
		m_BubbleVelocity.x += 1000;
	else
		m_BubbleVelocity.x -= 1000;
}

void BubbleComponent::ShootBubbleRandom()
{
	m_BubbleVelocity.x += rand() % 2000 + 1 - 1000;
	m_BubbleVelocity.y += rand() % 2000 + 1 - 1000;
}

void BubbleComponent::MoveToPopPosition(const glm::vec2& position)
{
	m_Active = false;

	auto bubblePosition = m_pTransformComponent->GetPosition();
	glm::vec2 positionToMove;

	positionToMove.x = utils::lerp(bubblePosition.x, position.x, 0.1f);
	positionToMove.y = utils::lerp(bubblePosition.y, position.y, 0.1f);

	m_pTransformComponent->Translate(positionToMove.x, positionToMove.y);
}

void BubbleComponent::Update()
{
	if (m_Active)
	{
		if (m_pTransformComponent->GetPosition().x < 206)
			m_BubbleSideForce = utils::lerp(m_BubbleVelocity.x, 5, 0.1f);
		else if (m_pTransformComponent->GetPosition().x >= 306)
			m_BubbleSideForce = utils::lerp(m_BubbleVelocity.x, -5, 0.1f);
		else
		{
			m_BubbleSideForce = utils::lerp(m_BubbleVelocity.x, -(float(rand() % 5 + 1)), 0.05f);
		}

		m_BubbleUpForce = utils::lerp(m_BubbleVelocity.y, -10, 0.1f);

		m_BubbleVelocity = { m_BubbleSideForce, m_BubbleUpForce };

		m_pTransformComponent->Move(m_BubbleVelocity.x * m_pGameTime->GetElapsedSec(), m_BubbleVelocity.y * m_pGameTime->GetElapsedSec());
	}
}

void BubbleComponent::Render()
{

}