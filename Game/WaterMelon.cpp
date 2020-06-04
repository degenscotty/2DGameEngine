#include "WaterMelon.h"

WaterMelon::WaterMelon()
	: m_pWaterMelon(nullptr)
{
	
}

void WaterMelon::Initialize()
{
	m_pWaterMelon = new GameObject();

	m_pWaterMelon->AddComponent(new TextureComponent("WaterMelon.png"));
	m_pWaterMelon->AddComponent(new CollisionComponent(32, 32, false));
	m_pWaterMelon->AddComponent(new RigidbodyComponent());

	m_pWaterMelon->SetTag("Fries");
}

void WaterMelon::Update() const
{
	
}

void WaterMelon::Render() const
{
	
}

void WaterMelon::SetPosition(const glm::vec2& position)
{
	m_pWaterMelon->GetTransform()->Translate(position);
}

const glm::vec2& WaterMelon::GetPosition()
{
	return m_pWaterMelon->GetTransform()->GetPosition();
}

GameObject* WaterMelon::GetGameObject() const
{
	return m_pWaterMelon;
}