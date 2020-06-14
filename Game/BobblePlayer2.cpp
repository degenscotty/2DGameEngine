#include "BobblePlayer2.h"

#include "BobbleDead.h"
#include "PlayerCommands.h"
#include "BobbleIdle.h"
#include "BobbleJump.h"
#include "BobbleWalking.h"
#include "Bubble.h"
#include "PopUpManager.h"
#include "ScoreManager.h"

#include "utils.h"

BobblePlayer2::BobblePlayer2()
	: m_pInputManager(InputManager::GetInstance())
	, m_pBobblePlayer(nullptr)
	, m_pControllerComponent(nullptr)
	, m_pCollisionComponent(nullptr)
	, m_pSpriteComponent(nullptr)
	, m_pStateComponent(nullptr)
	, m_PlayerID(2)
	, m_Lives(3)
	, m_IsRespawning(false)
{
}

BobblePlayer2::~BobblePlayer2()
{
}

void BobblePlayer2::Initialize()
{
	m_pBobblePlayer = new GameObject();
	
	m_pCollisionComponent = new CollisionComponent(32, 32, false);
	m_pCollisionComponent->SetCollisionGroup(static_cast<CollisionGroup>(Group1));
	m_pCollisionComponent->SetCollisionIgnoreGroups(static_cast<CollisionGroup>(Group1));
	m_pBobblePlayer->AddComponent(m_pCollisionComponent);

	m_pControllerComponent = new ControllerComponent();
	m_pBobblePlayer->AddComponent(m_pControllerComponent);
	m_pSpriteComponent = new SpriteComponent("Player2.png", 5, 4, 32);
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
	
	m_pBobblePlayer->SetCollisionCallBack(BIND_FN(BobblePlayer2::OnTrigger));

	InputAction* pMoveLeft = new InputAction("Player2MoveLeft", "Player2", new BobbleMoveLeftC(m_pControllerComponent, this), KEY_A, MOUSE_UNKNOWN, BUTTON_STATE::PRESSED);
	InputAction* pMoveRight = new InputAction("Player2MoveRight", "Player2", new BobbleMoveRightC(m_pControllerComponent, this), KEY_D, MOUSE_UNKNOWN, BUTTON_STATE::PRESSED);
	InputAction* pStopMoveLeft = new InputAction("Player2StopMoveLeft", "Player2", new BobbleStopMoveLeftC(m_pControllerComponent, this), KEY_A, MOUSE_UNKNOWN, BUTTON_STATE::RELEASED);
	InputAction* pStopMoveRight = new InputAction("Player2StopMoveRight", "Player2", new BobbleStopMoveRightC(m_pControllerComponent, this), KEY_D, MOUSE_UNKNOWN, BUTTON_STATE::RELEASED);
	InputAction* pJump = new InputAction("Player2Jump", "Player2", new BobbleJumpC(m_pControllerComponent, this), KEY_W, MOUSE_UNKNOWN, BUTTON_STATE::PRESSED);
	InputAction* pShootBubble = new InputAction("Player2ShootBubble", "Player2", new ShootBubbleC( this), KEY_LEFT_CTRL, MOUSE_UNKNOWN, BUTTON_STATE::RELEASED);
	
	m_pInputManager->AddInputActions(pMoveLeft);
	m_pInputManager->AddInputActions(pMoveRight);
	m_pInputManager->AddInputActions(pJump);
	m_pInputManager->AddInputActions(pStopMoveLeft);
	m_pInputManager->AddInputActions(pStopMoveRight);
	m_pInputManager->AddInputActions(pShootBubble);

	m_pBobblePlayer->SetTag("BobblePlayer");
}

void BobblePlayer2::SetPosition(const glm::vec2& position)
{
	m_pBobblePlayer->GetTransform()->Translate(position.x, position.y);
}

const glm::vec2& BobblePlayer2::GetPosition()
{
	return m_pBobblePlayer->GetTransform()->GetPosition();
}

void BobblePlayer2::SetAnimationClip(int index) const
{
	m_pSpriteComponent->SetClipIndex(index);
}

void BobblePlayer2::SetFlipState(const SDL_RendererFlip& flip) const
{
	m_pSpriteComponent->SetFlip(flip);
}

const SDL_RendererFlip& BobblePlayer2::GetFlipState()
{
	return m_pSpriteComponent->GetFlip();
}

void BobblePlayer2::ChangeState(const std::string& newState)
{
	m_pStateComponent->ChangeState(newState);
}

void BobblePlayer2::Update() const
{
}

void BobblePlayer2::Render() const
{

}

GameObject* BobblePlayer2::GetGameObject() const
{
	return m_pBobblePlayer;
}

void BobblePlayer2::EnableEnemyCollision()
{
	m_pCollisionComponent->SetCollisionIgnoreGroups(static_cast<CollisionGroup>(Group1));
}

void BobblePlayer2::OnTrigger(GameObject* other, bool trigger)
{
	if (other->GetTag() == "Fries")
	{
		PopUpManager::GetInstance()->AddPopUp("2000", this->GetPosition(), { 69, 224, 50 });
		ScoreManager::GetInstance()->AddScore(2000);
		GarbageCollector::GetInstance()->Destroy(other);
		LevelManager::GetInstance()->DestroyFries(other);
	}

	if (other->GetTag() == "WaterMelon")
	{
		PopUpManager::GetInstance()->AddPopUp("2000", this->GetPosition(), { 69, 224, 50 });
		ScoreManager::GetInstance()->AddScore(2000);
		GarbageCollector::GetInstance()->Destroy(other);
		LevelManager::GetInstance()->DestroyWaterMelon(other);
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

