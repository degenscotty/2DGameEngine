#include "pch.h"
#include "FPSComponent.h"

FPSComponent::FPSComponent()
	: m_pGameTime(GameTime::GetInstance())
	, m_pTransformComponent(nullptr)
	, m_pTextComponent(nullptr)
	, m_FPS(0)
	, m_FPSUpdateTime(1)
	, m_Time(0)
	, m_Counter(0)
	, m_Sum(0)
{

}

FPSComponent::~FPSComponent()
{

}

void FPSComponent::Initialize()
{
	if (m_pGameObject != nullptr)
		m_pTransformComponent = GetTransform();
	else
		CORE_ERROR("FPSComponent::Initialize() > Cannot Initialize FPSComponent, it is not attached to a GameObject");
	
	m_pTextComponent = static_cast<TextComponent*>(GetGameObject()->AddComponent(new TextComponent(std::to_string(m_FPS), 20)));
	m_pTextComponent->SetTransform(m_pTransformComponent);
	m_pTextComponent->SetColor({ 0, 255, 0 });
}

void FPSComponent::Update()
{
	m_Time += m_pGameTime->GetElapsedSec();

	m_FPS = m_pGameTime->GetFPS();

	++m_Counter;
	m_Sum += m_FPS;

	if (m_Counter >= m_FPS)
	{
		m_pTextComponent->SetText(std::to_string(int(m_Sum / m_Counter)));
		m_Counter = 0;
		m_Sum = 0;
	}
}

void FPSComponent::Render()
{

}