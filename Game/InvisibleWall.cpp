#include "InvisibleWall.h"

InvisibleWall::InvisibleWall(const glm::vec2& position)
	: m_pInvisibleWall(nullptr)
	, m_Position(position)
{
	
}

void InvisibleWall::Initialize()
{
	m_pInvisibleWall = new GameObject();

	m_pInvisibleWall->SetTag("InvisibleWall");
	m_pInvisibleWall->GetTransform()->Translate(m_Position);
}

void InvisibleWall::Update() const
{
	
}

void InvisibleWall::Render() const
{
	
}