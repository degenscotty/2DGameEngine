#include "Bubble.h"

#include "BubbleCommands.h"

#include "BubbleIdle.h"
#include "BubbleMaita.h"
#include "BubblePop.h"

#include "utils.h"

Bubble::Bubble()
	: m_pBubble(nullptr)
	, m_pBubbleComponent(nullptr)
	, m_pSpriteComponent(nullptr)
	, m_pStateComponent(nullptr)
	, m_pGarbageCollector(GarbageCollector::GetInstance())
	, m_pLevelManager(LevelManager::GetInstance())
	, m_Active(true)
	, m_BubblePopped(false)
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

	m_pSpriteComponent = new SpriteComponent("Bubble.png", 4, 4, 32);
	m_pSpriteComponent->AddClip(4, false);
	m_pSpriteComponent->AddClip(2, false);
	m_pSpriteComponent->AddClip(2, true);
	m_pSpriteComponent->AddClip(2, true);
	m_pSpriteComponent->SetClipIndex(0);
	m_pBubble->AddComponent(m_pSpriteComponent);

	m_pStateComponent = new StateComponent();

	BubbleState* pBubbleIdle = new BubbleIdle(this);
	m_pStateComponent->AddState("idle", pBubbleIdle);

	BubbleState* pBubbleMaita = new BubbleMaita(this);
	pBubbleMaita->AddCommand("bubbleMaita", new BubbleRMaitaC(this));
	m_pStateComponent->AddState("bubbleMaita", pBubbleMaita);

	BubbleState* pBubblePop = new BubblePop(this);
	m_pStateComponent->AddState("bubblePop", pBubblePop);

	m_pStateComponent->SetState("idle");

	m_pBubble->AddComponent(m_pStateComponent);
	
	m_pBubble->SetCollisionCallBack(BIND_FN(Bubble::OnTrigger));

	m_pBubble->SetTag("Bubble");
}

void Bubble::SetAnimationClip(int index) const
{
	m_pSpriteComponent->SetClipIndex(index);
}

void Bubble::ChangeState(const std::string& newState)
{
	m_pStateComponent->ChangeState(newState);
}

void Bubble::SetPosition(const glm::vec2& position)
{
	m_pBubble->GetTransform()->Translate(position);
}

const glm::vec2& Bubble::GetPosition()
{
	return m_pBubble->GetTransform()->GetPosition();
}

void Bubble::ShootBubble(bool right)
{
	m_pBubbleComponent->ShootBubble(right);
}

void Bubble::Update() const
{
	if (m_pSpriteComponent->GetClipIndex() == 1 && m_pSpriteComponent->CheckEndOfCurrentClip())
	{
		m_pGarbageCollector->Destroy(m_pBubble);
		m_pLevelManager->DestroyBubble(GetGameObject());
	}
}

void Bubble::PopBubble()
{
	auto state = reinterpret_cast<BubbleState*>(m_pStateComponent->GetCurrentState());

	state->PopBubble();
	m_BubblePopped = true;
}

void Bubble::Render() const
{

}

GameObject* Bubble::GetGameObject() const
{
	return m_pBubble;
}

void Bubble::OnTrigger(GameObject* other, bool trigger)
{
	if (other->GetTag() == "Maita" && m_Active && !trigger && !m_BubblePopped)
	{
		this->ChangeState("bubbleMaita");
		m_pGarbageCollector->Destroy(other);
		m_pLevelManager->DestroyMaita(other);
		m_Active = false;
	}

	if (other->GetTag() == "BobblePlayer" && !m_Active && !trigger && !m_BubblePopped && m_pSpriteComponent->GetClipIndex() != 1 && m_pSpriteComponent->GetClipIndex() != 0)
	{
		PopBubble();
	}
}