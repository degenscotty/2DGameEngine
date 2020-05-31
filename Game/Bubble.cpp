#include "Bubble.h"

Bubble::Bubble()
	: m_pBubble(nullptr)
	, m_pBubbleComponent(nullptr)
	, m_pSpriteComponent(nullptr)
{
}

Bubble::~Bubble()
{
	
}

void Bubble::Initialize()
{
	m_pBubble = new GameObject();

	m_pBubble->AddComponent(new CollisionComponent(32, 32, true));
	
	m_pBubbleComponent = new BubbleComponent();
	m_pBubble->AddComponent(m_pBubbleComponent);

	m_pSpriteComponent = new SpriteComponent("Bubble.png", 5, 4, 32);
	m_pSpriteComponent->AddClip(4, false);
	m_pSpriteComponent->AddClip(1, false);
	m_pSpriteComponent->AddClip(2, false);
	m_pSpriteComponent->AddClip(2, true);
	m_pSpriteComponent->AddClip(2, true);
	m_pSpriteComponent->SetClipIndex(0);
	m_pBubble->AddComponent(m_pSpriteComponent);

}

void Bubble::SetAnimationClip(int index) const
{
	m_pSpriteComponent->SetClipIndex(index);
}

void Bubble::SetPosition(const glm::vec2& position)
{
	m_pBubble->GetTransform()->Translate(position);
}

void Bubble::ShootBubble(bool right)
{
	m_pBubbleComponent->ShootBubble(right);
}

void Bubble::Update() const
{
	if (m_pSpriteComponent->GetClipIndex() == 0 && m_pSpriteComponent->CheckEndOfCurrentClip())
		SetAnimationClip(1);
}

void Bubble::Render() const
{
	
}

GameObject* Bubble::GetGameObject() const
{
	return m_pBubble;
}