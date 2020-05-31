#include "pch.h"
#include "BaseComponent.h"

#include "GameObject.h"
#include "TransformComponent.h"

BaseComponent::BaseComponent()
	: m_pGameObject{ nullptr }
	, m_Initlialized(false)
{

}

void BaseComponent::CheckInitialized()
{
	if (m_pGameObject->GetScene()->IsInitialized()) 
		Initialize();
}

TransformComponent* BaseComponent::GetTransform() const
{
	if (m_pGameObject == nullptr)
	{
		CORE_ERROR("Failed to retrieve TransformComponent")
			return nullptr;
	}

	return m_pGameObject->GetTransform();
}
