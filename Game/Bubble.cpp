#include "Bubble.h"

#include "BubbleCommands.h"

#include "BubbleIdle.h"
#include "BubbleMaita.h"
#include "BubbleMaitaDead.h"
#include "BubbleZenChan.h"
#include "BubbleZenChanDead.h"
#include "BubblePop.h"

#include "utils.h"

Bubble::Bubble(BubbleColor color)
	: m_pBubble(nullptr)
	, m_pBubbleComponent(nullptr)
	, m_pSpriteComponent(nullptr)
	, m_pStateComponent(nullptr)
	, m_pGarbageCollector(GarbageCollector::GetInstance())
	, m_pGameTime(GameTime::GetInstance())
	, m_pLevelManager(LevelManager::GetInstance())
	, m_BubbleColor(color)
	, m_ActiveTimer(0.0f)
	, m_ActivationTime(0.5f)
	, m_Poppable(false)
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
	if (m_BubbleColor == BubbleColor::GREEN)
		m_pSpriteComponent = new SpriteComponent("BubbleGreen.png", 7, 4, 32);
	else
		m_pSpriteComponent = new SpriteComponent("BubbleBlue.png", 7, 4, 32);
	m_pSpriteComponent->AddClip(4, false);
	m_pSpriteComponent->AddClip(1, false);
	m_pSpriteComponent->AddClip(2, false);
	m_pSpriteComponent->AddClip(2, true);
	m_pSpriteComponent->AddClip(2, true);
	m_pSpriteComponent->AddClip(4, true);
	m_pSpriteComponent->AddClip(4, true);
	m_pSpriteComponent->SetClipIndex(0);
	m_pBubble->AddComponent(m_pSpriteComponent);

	m_pStateComponent = new StateComponent();

	BubbleState* pBubbleIdle = new BubbleIdle(this);
	m_pStateComponent->AddState("idle", pBubbleIdle);

	BubbleState* pBubbleMaita = new BubbleMaita(this);
	pBubbleMaita->AddCommand("releaseMaita", new BubbleRMaitaC(this));
	m_pStateComponent->AddState("bubbleMaita", pBubbleMaita);

	BubbleState* pBubbleMaitaDead = new BubbleMaitaDead(this);
	pBubbleMaitaDead->AddCommand("shootRandom", new BubbleRandomDirectionC(m_pBubbleComponent));
	pBubbleMaitaDead->AddCommand("spawnFries", new BubbleSpawnFriesC(this));
	m_pStateComponent->AddState("bubbleMaitaDead", pBubbleMaitaDead);

	BubbleState* pBubbleZenChan = new BubbleZenChan(this);
	pBubbleZenChan->AddCommand("releaseZenChan", new BubbleRZenChanC(this));
	m_pStateComponent->AddState("bubbleZenChan", pBubbleZenChan);

	BubbleState* pBubbleZenChanDead = new BubbleZenChanDead(this);
	pBubbleZenChanDead->AddCommand("shootRandom", new BubbleRandomDirectionC(m_pBubbleComponent));
	pBubbleZenChanDead->AddCommand("spawnWaterMelon", new BubbleSpawnWaterMelonC(this));
	m_pStateComponent->AddState("bubbleZenChanDead", pBubbleZenChanDead);

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
	if (newState == "bubblePop")
		m_BubblePopped = true;

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

State* Bubble::GetCurrentState()
{
	return m_pStateComponent->GetCurrentState();
}

void Bubble::ShootBubble(bool right)
{
	m_pBubbleComponent->ShootBubble(right);
}

void Bubble::Update()
{
	m_ActiveTimer += m_pGameTime->GetElapsedSec();

	if (m_ActiveTimer > m_ActivationTime)
	{
		m_ActiveTimer = 0.0f;
		m_Poppable = true;
	}

	if (m_pSpriteComponent->GetClipIndex() == 0 && m_pSpriteComponent->CheckEndOfCurrentClip())
	{
		m_pSpriteComponent->SetClipIndex(1);
	}

	if (m_pSpriteComponent->GetClipIndex() == 2 && m_pSpriteComponent->CheckEndOfCurrentClip())
	{
		m_pGarbageCollector->Destroy(m_pBubble);
		m_pLevelManager->DestroyBubble(GetGameObject());
	}
}

void Bubble::MoveToPopPosition(const glm::vec2& position)
{
	m_pBubbleComponent->MoveToPopPosition(position);
}

void Bubble::PopBubble()
{
	m_BubblePopped = true;
	auto state = reinterpret_cast<BubbleState*>(m_pStateComponent->GetCurrentState());

	state->PopBubble();
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
	else if (other->GetTag() == "ZenChan" && m_Active && !trigger && !m_BubblePopped)
	{
		this->ChangeState("bubbleZenChan");
		m_pGarbageCollector->Destroy(other);
		m_pLevelManager->DestroyZenChan(other);
		m_Active = false;
	}
	else if (m_Poppable && other->GetTag() == "BobblePlayer" && !trigger && !m_BubblePopped && m_pSpriteComponent->GetClipIndex() != 0)
	{
		PopBubble();
	}
}