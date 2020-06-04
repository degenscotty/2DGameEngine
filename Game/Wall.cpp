#include "Wall.h"

Wall::Wall(const glm::vec2& position, int levelNumber)
	: m_pWall(nullptr)
	, m_Position(position)
	, m_LevelNumber(levelNumber)
{

}

void Wall::Initialize()
{
	m_pWall = new GameObject();

	switch (m_LevelNumber)
	{
	case 0:
	{
		m_pWall->AddComponent(new CollisionComponent(16, 16, false));
	}
	break;
	case 1:
	{
		m_pWall->AddComponent(new TextureComponent("PurpleWall.png"));
	}
	break;
	case 2:
	{
		m_pWall->AddComponent(new TextureComponent("GreenWall.png"));
	}
	break;
	case 3:
	{
		m_pWall->AddComponent(new TextureComponent("EvilWall.png"));
	}
	break;
	default:
		break;
	}

	m_pWall->SetTag("Wall");
	m_pWall->GetTransform()->Translate(m_Position);
}

void Wall::Update() const
{

}

void Wall::Render() const
{

}