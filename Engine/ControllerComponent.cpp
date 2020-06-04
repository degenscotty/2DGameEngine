#include "pch.h"
#include "ControllerComponent.h"
#include "GameObject.h"

ControllerComponent::ControllerComponent()
	: m_pTransformComponent(nullptr)
	, m_pRigidbodyComponent(nullptr)
	, m_pGameTime(GameTime::GetInstance())
	, m_MoveSpeed(150)
	, m_JumpSpeed(375)
	, m_FreezeTime(0.5f)
	, m_FreezeTimer(0.0f)
	, m_Frozen(false)
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

void ControllerComponent::SetMoveSpeed(float moveSpeed)
{
	m_MoveSpeed = moveSpeed;
}

void ControllerComponent::Jump()
{
	if (!m_Frozen)
	{
		if (!m_Jumping)
		{
			m_Jumping = true;
			m_pRigidbodyComponent->AddVelocity({ 0, -m_JumpSpeed });
		}
	}
}

void ControllerComponent::MoveLeft() const
{
	if (!m_Frozen)
		m_pRigidbodyComponent->SetVelocityX(-m_MoveSpeed);
}

void ControllerComponent::MoveRight() const
{
	if (!m_Frozen)
		m_pRigidbodyComponent->SetVelocityX(m_MoveSpeed);
}

void ControllerComponent::StopMove() const
{
	m_pRigidbodyComponent->SetVelocityX(0);
}

void ControllerComponent::Update()
{
	if (m_Frozen == true)
	{
		m_FreezeTimer += m_pGameTime->GetElapsedSec();

		if (m_FreezeTimer >= m_FreezeTime)
		{
			m_FreezeTimer = 0.0f;
			m_Frozen = false;
		}
	}

	if (m_pRigidbodyComponent->GetVelocity().y == 0)
	{
		m_Jumping = false;
	}

	if (m_pTransformComponent->GetPosition().y > 448)
	{
		m_pRigidbodyComponent->SetVelocityY(0);
		m_pRigidbodyComponent->SetVelocityX(0);
		m_pTransformComponent->Translate(m_pTransformComponent->GetPosition().x, -32);
		m_Frozen = true;
	}
	if (m_pTransformComponent->GetPosition().y < (4 * 16) && m_pRigidbodyComponent->GetVelocity().y < 0)
	{
		m_pRigidbodyComponent->SetVelocityY(0);
		m_pTransformComponent->Translate(m_pTransformComponent->GetPosition().x, (4 * 16));
	}
}

void ControllerComponent::Render()
{

}
