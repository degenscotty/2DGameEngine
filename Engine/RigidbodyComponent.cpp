#include "pch.h"
#include "RigidbodyComponent.h"

RigidbodyComponent::RigidbodyComponent()
	: m_pTransformComponent(nullptr)
	, m_pGameTime(GameTime::GetInstance())
	, m_Velocity(0, 0)
	, m_Gravity(800)
{

}

RigidbodyComponent::~RigidbodyComponent()
{

}

void RigidbodyComponent::Initialize()
{
	if (m_pGameObject != nullptr)
		m_pTransformComponent = GetTransform();
	else
		CORE_ERROR("RigidbodyComponent::Initialize() > Cannot Initialize RigidbodyComponent, it is not attached to a GameObject");
}

void RigidbodyComponent::SetTransform(TransformComponent* pTransformComponent)
{
	m_pTransformComponent = pTransformComponent;
}

void RigidbodyComponent::Update()
{	
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