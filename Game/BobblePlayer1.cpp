#include "BobblePlayer1.h"

#include "BobbleDead.h"
#include "PlayerCommands.h"
#include "BobbleIdle.h"
#include "BobbleJump.h"
#include "BobbleWalking.h"
#include "Bubble.h"
#include "PopUpManager.h"
#include "ScoreManager.h"

#include "utils.h"

BobblePlayer1::BobblePlayer1()
	: m_pInputManager(InputManager::GetInstance())
	, m_pBobblePlayer(nullptr)
	, m_pControllerComponent(nullptr)
	, m_pCollisionComponent(nullptr)
	, m_pSpriteComponent(nullptr)
	, m_pStateComponent(nullptr)
	, m_PlayerID(1)
	, m_Lives(3)
	, m_IsRespawning(false)
{
}

BobblePlayer1::~BobblePlayer1()
{
}

void BobblePlayer1::Initialize()
{
	m_pBobblePlayer = new GameObject();
	
	m_pCollisionComponent = new CollisionComponent(32, 32, false);
	m_pCollisionComponent->SetCollisionGroup(static_cast<CollisionGroup>(Group1));
	m_pCollisionComponent->SetCollisionIgnoreGroups(static_cast<CollisionGroup>(Group1));
	m_pBobblePlayer->AddComponent(m_pCollisionComponent);

	m_pControllerComponent = new ControllerComponent();
	m_pBobblePlayer->AddComponent(m_pControllerComponent);
	m_pSpriteComponent = new SpriteComponent("Player1.png", 5, 4, 32);
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
	
	m_pBobblePlayer->SetCollisionCallBack(BIND_FN(BobblePlayer1::OnTrigger));

	InputAction* pMoveLeft = new InputAction("Player1MoveLeft", "Player1", new BobbleMoveLeftC(m_pControllerComponent, this), KEY_LEFT, MOUSE_UNKNOWN, BUTTON_STATE::PRESSED);
	InputAction* pMoveRight = new InputAction("Player1MoveRight", "Player1", new BobbleMoveRightC(m_pControllerComponent, this), KEY_RIGHT, MOUSE_UNKNOWN, BUTTON_STATE::PRESSED);
	InputAction* pStopMoveLeft = new InputAction("Player1StopMoveLeft", "Player1", new BobbleStopMoveLeftC(m_pControllerComponent, this), KEY_LEFT, MOUSE_UNKNOWN, BUTTON_STATE::RELEASED);
	InputAction* pStopMoveRight = new InputAction("Player1StopMoveRight", "Player1", new BobbleStopMoveRightC(m_pControllerComponent, this), KEY_RIGHT, MOUSE_UNKNOWN, BUTTON_STATE::RELEASED);
	InputAction* pJump = new InputAction("Player1Jump", "Player1", new BobbleJumpC(m_pControllerComponent, this), KEY_UP, MOUSE_UNKNOWN, BUTTON_STATE::PRESSED);
	InputAction* pShootBubble = new InputAction("Player1ShootBubble", "Player1", new ShootBubbleC( this), KEY_RIGHT_CTRL, MOUSE_UNKNOWN, BUTTON_STATE::RELEASED);
	
	m_pInputManager->AddInputActions(pMoveLeft);
	m_pInputManager->AddInputActions(pMoveRight);
	m_pInputManager->AddInputActions(pJump);
	m_pInputManager->AddInputActions(pStopMoveLeft);
	m_pInputManager->AddInputActions(pStopMoveRight);
	m_pInputManager->AddInputActions(pShootBubble);

	m_pBobblePlayer->SetTag("BobblePlayer");
}

void BobblePlayer1::SetPosition(const glm::vec2& position)
{
	m_pBobblePlayer->GetTransform()->Translate(position.x, position.y);
}

const glm::vec2& BobblePlayer1::GetPosition()
{
	return m_pBobblePlayer->GetTransform()->GetPosition();
}

void BobblePlayer1::SetAnimationClip(int index) const
{
	m_pSpriteComponent->SetClipIndex(index);
}

void BobblePlayer1::SetFlipState(const SDL_RendererFlip& flip) const
{
	m_pSpriteComponent->SetFlip(flip);
}

const SDL_RendererFlip& BobblePlayer1::GetFlipState()
{
	return m_pSpriteComponent->GetFlip();
}

void BobblePlayer1::ChangeState(const std::string& newState)
{
	m_pStateComponent->ChangeState(newState);
}

void BobblePlayer1::Update() const
{
}

void BobblePlayer1::Render() const
{

}

GameObject* BobblePlayer1::GetGameObject() const
{
	return m_pBobblePlayer;
}

void BobblePlayer1::EnableEnemyCollision()
{
	m_pCollisionComponent->SetCollisionIgnoreGroups(static_cast<CollisionGroup>(Group1));
}

void BobblePlayer1::OnTrigger(GameObject* other, bool trigger)
{
	if (other->GetTag() == "Fries")
	{
		PopUpManager::GetInstance()->AddPopUp("2000", this->GetPosition(), {69, 224, 50});
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

	if (!m_IsRespawning && !trigger && (other->GetTag() == "Maita" || other->GetTag() == "ZenChan" || other->GetTag() == "MaitaPlayer") && !m_pControllerComponent->GetFreeze())
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

