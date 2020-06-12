#include "Maita.h"

#include "MaitaCommands.h"

#include "MaitaIdle.h"
#include "MaitaSeeking.h"

#include "CollisionGroups.h"
#include "utils.h"

Maita::Maita()
	: m_pEnemyMaita(nullptr)
	, m_pTransformComponent(nullptr)
	, m_pSpriteComponent(nullptr)
	, m_pStateComponent(nullptr)
	, m_CanJump(false)
{
}

Maita::~Maita()
{
}

void Maita::Initialize()
{
	m_pEnemyMaita = new GameObject();
	m_pTransformComponent = m_pEnemyMaita->GetTransform();

	CollisionComponent* pCollisionComponent = new CollisionComponent(32, 32, false);
	pCollisionComponent->SetCollisionGroup(static_cast<CollisionGroup>(Group2));
	pCollisionComponent->SetCollisionIgnoreGroups(static_cast<CollisionGroup>(Group2));
	m_pEnemyMaita->AddComponent(pCollisionComponent);
	
	auto pCollisionComponentTrigger(new CollisionComponent(32, 32, true));
	pCollisionComponentTrigger->SetOffset({ 0, -56 });
	m_pEnemyMaita->AddComponent(pCollisionComponentTrigger);
	
	m_pSpriteComponent = new SpriteComponent("Maita.png", 3, 2, 32);
	m_pSpriteComponent->AddClip(2, true);
	m_pSpriteComponent->AddClip(2, true);
	m_pSpriteComponent->AddClip(2, true);
	m_pSpriteComponent->SetClipIndex(0);
	m_pEnemyMaita->AddComponent(m_pSpriteComponent);
	ControllerComponent* pControllerComponent = new ControllerComponent();
	pControllerComponent->SetMoveSpeed(60);
	m_pEnemyMaita->AddComponent(pControllerComponent);
	
	m_pStateComponent = new StateComponent();

	MaitaState* pMatiaIdle = new MaitaIdle(this);
	pMatiaIdle->AddCommand("stopmove", new MaitaStopMovingC(pControllerComponent, this));
	m_pStateComponent->AddState("idle", pMatiaIdle);

	MaitaState* pMatiaSeeking = new MaitaSeeking(this);
	pMatiaSeeking->AddCommand("moveleft", new MaitaMoveLeftC(pControllerComponent, this));
	pMatiaSeeking->AddCommand("moveright", new MaitaMoveRightC(pControllerComponent, this));
	pMatiaSeeking->AddCommand("jump", new MaitaJumpC(pControllerComponent, this));
	m_pStateComponent->AddState("seeking", pMatiaSeeking);

	m_pStateComponent->SetState("idle");
	m_pEnemyMaita->AddComponent(m_pStateComponent);
	m_pEnemyMaita->SetCollisionCallBack(BIND_FN(Maita::OnTrigger));

	m_pEnemyMaita->SetTag("Maita");
}

void Maita::SetPosition(const glm::vec2& position)
{
	m_pTransformComponent->Translate(position.x, position.y);
}

glm::vec2 Maita::GetPosition()
{
	return m_pTransformComponent->GetPosition();
}

void Maita::SetAnimationClip(int index) const
{
	m_pSpriteComponent->SetClipIndex(index);
}

void Maita::ChangeState(const std::string& newState)
{
	m_pStateComponent->ChangeState(newState);
}

void Maita::SetFlipState(const SDL_RendererFlip& flip) const
{
	m_pSpriteComponent->SetFlip(flip);
}

void Maita::Update() const
{
}

void Maita::Render() const
{
}

GameObject* Maita::GetGameObject()
{
	return m_pEnemyMaita;
}

void Maita::SetJump(bool canJump)
{
	m_CanJump = canJump;
}

void Maita::OnTrigger(GameObject* other, bool trigger)
{
	if (!trigger && other->GetTag() == "Wall" && other->GetTransform()->GetPosition().y < m_pTransformComponent->GetPosition().y)
		m_CanJump = true;
}
