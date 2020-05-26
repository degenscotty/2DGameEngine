#include "EnemyMaita.h"

#include "ControllerComponent.h"
#include "MaitaIdle.h"

EnemyMaita::EnemyMaita()
	: m_pEnemyMaita(nullptr)
	, m_pSpriteComponent(nullptr)
	, m_pStateComponent(nullptr)
{
}

EnemyMaita::~EnemyMaita()
{
}

void EnemyMaita::Initialize()
{
	m_pEnemyMaita = new GameObject();
	m_pEnemyMaita->AddComponent(new CollisionComponent(32, 32));
	m_pSpriteComponent = new SpriteComponent("Maita.png", 3, 2, 32);
	m_pSpriteComponent->AddClip(2, true);
	m_pSpriteComponent->AddClip(2, true);
	m_pSpriteComponent->AddClip(2, true);
	m_pSpriteComponent->SetClipIndex(0);
	m_pEnemyMaita->AddComponent(m_pSpriteComponent);
	m_pEnemyMaita->AddComponent(new ControllerComponent());
	m_pStateComponent = new StateComponent();
	m_pStateComponent->AddState(std::make_pair("idle", new MaitaIdle(this)));
	m_pStateComponent->SetState("idle");
	m_pEnemyMaita->AddComponent(m_pStateComponent);
}

void EnemyMaita::SetPosition(const glm::vec2& position)
{
	m_pEnemyMaita->GetTransform()->Translate(position.x, position.y);
}

void EnemyMaita::SetAnimationClip(int index) const
{
	m_pSpriteComponent->SetClipIndex(index);
}

void EnemyMaita::ChangeState(const std::string& newState)
{
	m_pStateComponent->SetState(newState);
}

void EnemyMaita::SetFlipState(const SDL_RendererFlip& flip) const
{
	m_pSpriteComponent->SetFlip(flip);
}

void EnemyMaita::Update() const
{
}

void EnemyMaita::Render() const
{
}

GameObject* EnemyMaita::GetGameObject() const
{
	return m_pEnemyMaita;
}
