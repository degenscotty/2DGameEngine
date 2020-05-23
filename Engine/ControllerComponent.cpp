#include "pch.h"
#include "ControllerComponent.h"

ControllerComponent::ControllerComponent()
	: m_pTransformComponent(nullptr)
	, m_pGameTime(GameTime::GetInstance())
	, m_MoveSpeed(150)
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
}

void ControllerComponent::Jump()
{

}

void ControllerComponent::MoveLeft()
{
	m_pTransformComponent->Move(-(m_MoveSpeed * m_pGameTime->GetElapsedSec()), 0);
}

void ControllerComponent::MoveRight()
{
	m_pTransformComponent->Move(m_MoveSpeed * m_pGameTime->GetElapsedSec(), 0);
}

void ControllerComponent::Update()
{
}

void ControllerComponent::Render()
{

}
