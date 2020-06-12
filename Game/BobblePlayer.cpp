#include "BobblePlayer.h"

#include "BobbleDead.h"
#include "PlayerCommands.h"
#include "BobbleIdle.h"
#include "BobbleJump.h"
#include "BobbleWalking.h"
#include "Bubble.h"
#include "GameOverScene.h"
#include "PopUpManager.h"

#include "utils.h"

BobblePlayer::BobblePlayer()
	: m_pInputManager(InputManager::GetInstance())
	, m_pBobblePlayer(nullptr)
	, m_pControllerComponent(nullptr)
	, m_pCollisionComponent(nullptr)
	, m_pSpriteComponent(nullptr)
	, m_pStateComponent(nullptr)
	, m_Lives(3)
{
}

BobblePlayer::~BobblePlayer()
{
}

void BobblePlayer::Initialize()
{
	m_pBobblePlayer = new GameObject();
	
	m_pCollisionComponent = new CollisionComponent(32, 32, false);
	m_pCollisionComponent->SetCollisionGroup(static_cast<CollisionGroup>(Group1));
	m_pCollisionComponent->SetCollisionIgnoreGroups(static_cast<CollisionGroup>(Group1));
	m_pBobblePlayer->AddComponent(m_pCollisionComponent);

	m_pControllerComponent = new ControllerComponent();
	m_pBobblePlayer->AddComponent(m_pControllerComponent);
	m_pSpriteComponent = new SpriteComponent("Player.png", 5, 4, 32);
	m_pSpriteComponent->AddClip(2, true);
	m_pSpriteComponent->AddClip(2, true);
	m_pSpriteComponent->AddClip(2, false);
	m_pSpriteComponent->AddClip(2, false);
	m_pSpriteComponent->AddClip(4, true);
	m_pSpriteComponent->SetClipIndex(0);
	m_pBobblePlayer->AddComponent(m_pSpriteComponent);
	
	m_pStateComponent = new StateComponent();
	m_pStateComponent->AddState("idle", new BobbleIdle(this));
	m_pStateComponent->AddState("walking", new BobbleWalking(this));
	m_pStateComponent->AddState("jumping", new BobbleJump(this));
	m_pStateComponent->AddState("dead", new BobbleDead(this));
	m_pStateComponent->SetState("idle");
	m_pBobblePlayer->AddComponent(m_pStateComponent);
	
	m_pBobblePlayer->SetCollisionCallBack(BIND_FN(BobblePlayer::OnTrigger));

	InputAction* pMoveLeft = new InputAction("PlayerMoveLeft", new BobbleMoveLeftC(m_pControllerComponent, this), KEY_LEFT, MOUSE_UNKNOWN, BUTTON_STATE::PRESSED);
	InputAction* pMoveRight = new InputAction("PlayerMoveRight", new BobbleMoveRightC(m_pControllerComponent, this), KEY_RIGHT, MOUSE_UNKNOWN, BUTTON_STATE::PRESSED);
	InputAction* pStopMoveLeft = new InputAction("PlayerStopMoveLeft", new BobbleStopMoveLeftC(m_pControllerComponent, this), KEY_LEFT, MOUSE_UNKNOWN, BUTTON_STATE::RELEASED);
	InputAction* pStopMoveRight = new InputAction("PlayerStopMoveRight", new BobbleStopMoveRightC(m_pControllerComponent, this), KEY_RIGHT, MOUSE_UNKNOWN, BUTTON_STATE::RELEASED);
	InputAction* pJump = new InputAction("PlayerJump", new BobbleJumpC(m_pControllerComponent, this), KEY_SPACE, MOUSE_UNKNOWN, BUTTON_STATE::PRESSED);
	InputAction* pShootBubble = new InputAction("ShootBubble", new ShootBubbleC( this), KEY_RIGHT_CTRL, MOUSE_UNKNOWN, BUTTON_STATE::RELEASED);
	
	m_pInputManager->AddInputActions(pMoveLeft);
	m_pInputManager->AddInputActions(pMoveRight);
	m_pInputManager->AddInputActions(pJump);
	m_pInputManager->AddInputActions(pStopMoveLeft);
	m_pInputManager->AddInputActions(pStopMoveRight);
	m_pInputManager->AddInputActions(pShootBubble);

	m_pBobblePlayer->SetTag("BobblePlayer");
}

void BobblePlayer::SetPosition(const glm::vec2& position)
{
	m_pBobblePlayer->GetTransform()->Translate(position.x, position.y);
}

const glm::vec2& BobblePlayer::GetPosition()
{
	return m_pBobblePlayer->GetTransform()->GetPosition();
}

void BobblePlayer::SetAnimationClip(int index) const
{
	m_pSpriteComponent->SetClipIndex(index);
}

void BobblePlayer::SetFlipState(const SDL_RendererFlip& flip) const
{
	m_pSpriteComponent->SetFlip(flip);
}

const SDL_RendererFlip& BobblePlayer::GetFlipState()
{
	return m_pSpriteComponent->GetFlip();
}

void BobblePlayer::ChangeState(const std::string& newState)
{
	m_pStateComponent->ChangeState(newState);
}

void BobblePlayer::Update() const
{
}

void BobblePlayer::Render() const
{

}

GameObject* BobblePlayer::GetGameObject() const
{
	return m_pBobblePlayer;
}

void BobblePlayer::EnableEnemyCollision()
{
	m_pCollisionComponent->SetCollisionIgnoreGroups(static_cast<CollisionGroup>(Group1));
}

void BobblePlayer::OnTrigger(GameObject* other, bool trigger)
{
	if (other->GetTag() == "Fries")
	{
		PopUpManager::GetInstance()->AddPopUp("2000", this->GetPosition(), {69, 224, 50});
		GarbageCollector::GetInstance()->Destroy(other);
	}

	if (!m_IsRespawning && !trigger && (other->GetTag() == "Maita" || other->GetTag() == "ZenChan") && !m_pControllerComponent->GetFreeze())
	{
		--m_Lives;

		if (CheckDead())
		{
			GarbageCollector::GetInstance()->Destroy(SceneManager::GetInstance()->GetActiveScene());
			SceneManager::GetInstance()->SetActiveScene(L"GameOverScene");
			return;
		}

		m_pCollisionComponent->SetCollisionIgnoreGroups(static_cast<CollisionGroup>(Group1 | Group2));
		m_IsRespawning = true;

		ChangeState("dead");
		m_pControllerComponent->SetFreeze(2.5f);
	}
}

