#include "ZenChan.h"

#include "ZenChanCommands.h"

#include "ZenChanIdle.h"
#include "ZenChanSeeking.h"

#include "CollisionGroups.h"
#include "utils.h"

ZenChan::ZenChan()
	: m_pZenChan(nullptr)
	, m_pTransformComponent(nullptr)
	, m_pSpriteComponent(nullptr)
	, m_pStateComponent(nullptr)
	, m_CanJump(false)
{
}

ZenChan::~ZenChan()
{
}

void ZenChan::Initialize()
{
	m_pZenChan = new GameObject();
	m_pTransformComponent = m_pZenChan->GetTransform();

	CollisionComponent* pCollisionComponent = new CollisionComponent(32, 32, false);
	pCollisionComponent->SetCollisionGroup(static_cast<CollisionGroup>(Group2));
	pCollisionComponent->SetCollisionIgnoreGroups(static_cast<CollisionGroup>(Group1 | Group2));
	m_pZenChan->AddComponent(pCollisionComponent);
	
	auto pCollisionComponentTrigger(new CollisionComponent(32, 32, true));
	pCollisionComponentTrigger->SetOffset({ 0, -56 });
	m_pZenChan->AddComponent(pCollisionComponentTrigger);
	
	m_pSpriteComponent = new SpriteComponent("Snail.png", 3, 2, 32);
	m_pSpriteComponent->AddClip(2, true);
	m_pSpriteComponent->AddClip(2, true);
	m_pSpriteComponent->AddClip(2, true);
	m_pSpriteComponent->SetClipIndex(0);
	m_pZenChan->AddComponent(m_pSpriteComponent);
	ControllerComponent* pControllerComponent = new ControllerComponent();
	pControllerComponent->SetMoveSpeed(60);
	m_pZenChan->AddComponent(pControllerComponent);
	
	m_pStateComponent = new StateComponent();

	ZenChanState* pZenChanIdle = new ZenChanIdle(this);
	pZenChanIdle->AddCommand("stopmove", new ZenChanStopMovingC(pControllerComponent, this));
	m_pStateComponent->AddState("idle", pZenChanIdle);

	ZenChanState* pZenChanSeeking = new ZenChanSeeking(this);
	pZenChanSeeking->AddCommand("moveleft", new ZenChanMoveLeftC(pControllerComponent, this));
	pZenChanSeeking->AddCommand("moveright", new ZenChanMoveRightC(pControllerComponent, this));
	pZenChanSeeking->AddCommand("jump", new ZenChanJumpC(pControllerComponent, this));
	m_pStateComponent->AddState("seeking", pZenChanSeeking);

	m_pStateComponent->SetState("idle");
	m_pZenChan->AddComponent(m_pStateComponent);
	m_pZenChan->SetCollisionCallBack(BIND_FN(ZenChan::OnTrigger));

	m_pZenChan->SetTag("ZenChan");
}

void ZenChan::SetPosition(const glm::vec2& position)
{
	m_pTransformComponent->Translate(position.x, position.y);
}

glm::vec2 ZenChan::GetPosition()
{
	return m_pTransformComponent->GetPosition();
}

void ZenChan::SetAnimationClip(int index) const
{
	m_pSpriteComponent->SetClipIndex(index);
}

void ZenChan::ChangeState(const std::string& newState)
{
	m_pStateComponent->ChangeState(newState);
}

void ZenChan::SetFlipState(const SDL_RendererFlip& flip) const
{
	m_pSpriteComponent->SetFlip(flip);
}

void ZenChan::Update() const
{
}

void ZenChan::Render() const
{
}

GameObject* ZenChan::GetGameObject()
{
	return m_pZenChan;
}

void ZenChan::SetJump(bool canJump)
{
	m_CanJump = canJump;
}

void ZenChan::OnTrigger(GameObject* other, bool trigger)
{
	if (!trigger && other->GetTag() == "Wall" && other->GetTransform()->GetPosition().y < m_pTransformComponent->GetPosition().y)
		m_CanJump = true;
}
