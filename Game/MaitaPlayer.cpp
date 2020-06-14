#include "MaitaPlayer.h"

#include "MaitaCommands.h"
#include "Bubble.h"
#include "MaitaWalking.h"
#include "PopUpManager.h"

#include "utils.h"

MaitaPlayer::MaitaPlayer()
	: m_pInputManager(InputManager::GetInstance())
	, m_pMaitaPlayer(nullptr)
	, m_pControllerComponent(nullptr)
	, m_pCollisionComponent(nullptr)
	, m_pSpriteComponent(nullptr)
	, m_pStateComponent(nullptr)

{
}

void MaitaPlayer::Initialize()
{
	m_pMaitaPlayer = new GameObject();

	m_pCollisionComponent = new CollisionComponent(32, 32, false);
	m_pCollisionComponent->SetCollisionGroup(static_cast<CollisionGroup>(Group2));
	m_pCollisionComponent->SetCollisionIgnoreGroups(static_cast<CollisionGroup>(Group2));
	m_pMaitaPlayer->AddComponent(m_pCollisionComponent);

	m_pSpriteComponent = new SpriteComponent("Maita.png", 3, 2, 32);
	m_pSpriteComponent->AddClip(2, true);
	m_pSpriteComponent->AddClip(2, true);
	m_pSpriteComponent->AddClip(2, true);
	m_pSpriteComponent->SetClipIndex(0);
	m_pMaitaPlayer->AddComponent(m_pSpriteComponent);
	m_pControllerComponent = new ControllerComponent();
	m_pMaitaPlayer->AddComponent(m_pControllerComponent);

	m_pStateComponent = new StateComponent();
	m_pStateComponent->AddState("walking", new MaitaWalking(this));
	m_pMaitaPlayer->AddComponent(m_pStateComponent);

	m_pStateComponent->SetState("walking");

	m_pMaitaPlayer->SetCollisionCallBack(BIND_FN(MaitaPlayer::OnTrigger));

	InputAction* pMoveLeft = new InputAction("PlayerMaitaMoveLeft", new MaitaMoveLeftC(m_pControllerComponent, this), KEY_A, MOUSE_UNKNOWN, BUTTON_STATE::PRESSED);
	InputAction* pMoveRight = new InputAction("PlayerMaitaMoveRight", new MaitaMoveRightC(m_pControllerComponent, this), KEY_D, MOUSE_UNKNOWN, BUTTON_STATE::PRESSED);
	InputAction* pStopMoveLeft = new InputAction("PlayerMaitaStopMoveLeft", new MaitaStopMovingC(m_pControllerComponent, this), KEY_A, MOUSE_UNKNOWN, BUTTON_STATE::RELEASED);
	InputAction* pStopMoveRight = new InputAction("PlayerMaitaStopMoveRight", new MaitaStopMovingC(m_pControllerComponent, this), KEY_D, MOUSE_UNKNOWN, BUTTON_STATE::RELEASED);
	InputAction* pJump = new InputAction("PlayerMaitaJump", new MaitaJumpC(m_pControllerComponent, this), KEY_W, MOUSE_UNKNOWN, BUTTON_STATE::PRESSED);
	
	m_pInputManager->AddInputActions(pMoveLeft);
	m_pInputManager->AddInputActions(pMoveRight);
	m_pInputManager->AddInputActions(pJump);
	m_pInputManager->AddInputActions(pStopMoveLeft);
	m_pInputManager->AddInputActions(pStopMoveRight);

	m_pMaitaPlayer->SetTag("MaitaPlayer");
}

void MaitaPlayer::SetPosition(const glm::vec2& position) const
{
	m_pMaitaPlayer->GetTransform()->Translate(position.x, position.y);
}

const glm::vec2& MaitaPlayer::GetPosition() const
{
	return m_pMaitaPlayer->GetTransform()->GetPosition();
}

void MaitaPlayer::SetAnimationClip(int index) const
{
	m_pSpriteComponent->SetClipIndex(index);
}

void MaitaPlayer::SetFlipState(const SDL_RendererFlip& flip) const
{
	m_pSpriteComponent->SetFlip(flip);
}

const SDL_RendererFlip& MaitaPlayer::GetFlipState() const
{
	return m_pSpriteComponent->GetFlip();
}

void MaitaPlayer::ChangeState(const std::string& newState)
{
	m_pStateComponent->ChangeState(newState);
}

void MaitaPlayer::Update() const
{
}

void MaitaPlayer::Render() const
{
}

GameObject* MaitaPlayer::GetGameObject() const
{
	return m_pMaitaPlayer;
}

void MaitaPlayer::OnTrigger(GameObject* other, bool trigger)
{
}

