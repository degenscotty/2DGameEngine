#include "pch.h"
#include "ControllerComponent.h"
#include "GameObject.h"

ControllerComponent::ControllerComponent()
	: m_pTransformComponent(nullptr)
	, m_pRigidbodyComponent(nullptr)
	, m_pGameTime(GameTime::GetInstance())
	, m_MoveSpeed(150)
	, m_JumpSpeed(10)
	, m_Jumping(false)
{

}

ControllerComponent::~ControllerComponent()
{

}

void ControllerComponent::Initialize()
{
	if (m_pGameObject != nullptr)
		m_pTransformComponent = GetTransform();
	else
		CORE_ERROR("ControllerComponent::Initialize() > Cannot Initialize ControllerComponent, it is not attached to a GameObject");

	if (m_pGameObject != nullptr)
		m_pRigidbodyComponent = static_cast<RigidbodyComponent*>(GetGameObject()->AddComponent(new RigidbodyComponent()));
	else
		CORE_ERROR("ControllerComponent::Initialize() > Cannot Initialize ControllerComponent, it is not attached to a GameObject");

	m_pRigidbodyComponent->SetTransform(m_pTransformComponent);
}

void ControllerComponent::Jump()
{	
	if (!m_Jumping)
	{
		m_Jumping = true;
		m_pRigidbodyComponent->AddVelocity({ 0, -275 });
	}
}

void ControllerComponent::MoveLeft() const
{
	m_pRigidbodyComponent->SetVelocityX(-150);
}

void ControllerComponent::MoveRight() const
{
	m_pRigidbodyComponent->SetVelocityX(150);
}

void ControllerComponent::StopMove() const
{
	m_pRigidbodyComponent->SetVelocityX(0);
}

void ControllerComponent::Update()
{
	if (m_pRigidbodyComponent->GetVelocity().y == 0)
	{
		m_Jumping = false;
	}
}

void ControllerComponent::Render()
{

}
