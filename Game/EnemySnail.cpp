#include "EnemySnail.h"

#include "ControllerComponent.h"
#include "SnailIdle.h"

EnemySnail::EnemySnail()
	: m_pEnemySnail(nullptr)
	, m_pSpriteComponent(nullptr)
{
	m_pStateMap.insert(std::make_pair<std::string, SnailState*>("idle", new SnailIdle(this)));

	m_pState = m_pStateMap.at("idle");
}

EnemySnail::~EnemySnail()
{
	for (auto state : m_pStateMap)
	{
		delete state.second;
	}
	m_pStateMap.clear();
}

void EnemySnail::Initialize()
{
	m_pEnemySnail = new GameObject();
	m_pEnemySnail->AddComponent(new CollisionComponent(32, 32));
	m_pSpriteComponent = new SpriteComponent("Snail.png", 3, 2, 32);
	m_pSpriteComponent->AddClip(2, true);
	m_pSpriteComponent->AddClip(2, true);
	m_pSpriteComponent->AddClip(2, true);
	m_pSpriteComponent->SetClipIndex(0);
	m_pEnemySnail->AddComponent(m_pSpriteComponent);
	m_pEnemySnail->AddComponent(new ControllerComponent());
}

void EnemySnail::SetPosition(const glm::vec2& position)
{
	m_pEnemySnail->GetTransform()->Translate(position.x, position.y);
}

void EnemySnail::SetAnimationClip(int index) const
{
	m_pSpriteComponent->SetClipIndex(index);
}

void EnemySnail::ChangeState(const std::string& newState)
{
	if (m_pState == m_pStateMap[newState])
		return;

	m_pState->OnExit();
	m_pState = m_pStateMap.at(newState);
	m_pState->OnEnter();
}

void EnemySnail::SetFlipState(const SDL_RendererFlip& flip) const
{
	m_pSpriteComponent->SetFlip(flip);
}

void EnemySnail::Update() const
{
	m_pState->Update();
}

void EnemySnail::Render() const
{

}

GameObject* EnemySnail::GetGameObject() const
{
	return m_pEnemySnail;
}
