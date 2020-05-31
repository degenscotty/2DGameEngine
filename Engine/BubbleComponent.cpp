#include "pch.h"
#include "BubbleComponent.h"
#include "TransformComponent.h"

#include "utils.h"

BubbleComponent::BubbleComponent()
	: m_pTransformComponent(nullptr)
	, m_pGameTime(GameTime::GetInstance())
	, m_BubbleUpForce(-10)
	, m_BubbleVelocity({ 0, 0 })
	, m_BubbleSideForce(25)
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

void BubbleComponent::Update()
{
	if (m_Active)
	{
		if (m_pTransformComponent->GetPosition().x < 250)
			m_BubbleSideForce = utils::lerp(m_BubbleVelocity.x, 25, 0.1f);
		else if (m_pTransformComponent->GetPosition().x > 259)
			m_BubbleSideForce = utils::lerp(m_BubbleVelocity.x, -25, 0.1f);

		m_BubbleVelocity = { m_BubbleSideForce, m_BubbleUpForce };

		m_pTransformComponent->Move(m_BubbleVelocity.x * m_pGameTime->GetElapsedSec(), m_BubbleVelocity.y * m_pGameTime->GetElapsedSec());
	}
}

void BubbleComponent::Render()
{

}