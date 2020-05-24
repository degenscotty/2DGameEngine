#include "pch.h"
#include "RigidbodyComponent.h"

RigidbodyComponent::RigidbodyComponent()
	: m_pTransformComponent(nullptr)
	, m_pGameTime(GameTime::GetInstance())
	, m_Velocity(0, 0)
	, m_Gravity(400)
{

}

RigidbodyComponent::~RigidbodyComponent()
{

}

void RigidbodyComponent::SetTransform(TransformComponent* pTransformComponent)
{
	m_pTransformComponent = pTransformComponent;
}

void RigidbodyComponent::Initialize()
{
}

void RigidbodyComponent::Update()
{
	CORE_INFO("PlayerVelocity == [{0}, {1}]", m_Velocity.x, m_Velocity.y);
	
	m_Velocity.y += m_Gravity * m_pGameTime->GetElapsedSec();

	m_pTransformComponent->Move(m_Velocity.x * m_pGameTime->GetElapsedSec(), m_Velocity.y * m_pGameTime->GetElapsedSec());
}

void RigidbodyComponent::SetVelocity(const glm::vec2& velocity)
{
	m_Velocity = velocity;
}

void RigidbodyComponent::SetVelocityX(float velocityX)
{
	m_Velocity.x = velocityX;
}

void RigidbodyComponent::SetVelocityY(float velocityY)
{
	m_Velocity.y = velocityY;
}

const glm::vec2& RigidbodyComponent::GetVelocity()
{
	return m_Velocity;
}

void RigidbodyComponent::AddVelocity(const glm::vec2& velocity)
{
	m_Velocity += velocity;
}

void RigidbodyComponent::Render()
{

}