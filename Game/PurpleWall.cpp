#include "PurpleWall.h"

PurpleWall::PurpleWall(const glm::vec2& position)
	: m_pPurpleWall(nullptr)
	, m_Position(position)
{
	
}

void PurpleWall::Initialize()
{
	m_pPurpleWall = new GameObject();
	m_pPurpleWall->AddComponent(new TextureComponent("PurpleWall.png"));

	m_pPurpleWall->SetTag("PurpleWall");
	m_pPurpleWall->GetTransform()->Translate(m_Position);
}

void PurpleWall::Update() const
{
	
}

void PurpleWall::Render() const
{
	
}