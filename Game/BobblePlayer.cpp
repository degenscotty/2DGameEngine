#include "BobblePlayer.h"

#include "BobbleIdle.h"
#include "BobbleWalking.h"
#include "PlayerCommands.h"

BobblePlayer::BobblePlayer()
	: m_pInputManager(InputManager::GetInstance())
	, m_pBobblePlayer(nullptr)
	, m_pSpriteComponent(nullptr)
	, m_pState()
{
	m_pStateMap.insert(std::make_pair<std::string, BobbleState*>("idle", new BobbleIdle(this)));
	m_pStateMap.insert(std::make_pair<std::string, BobbleState*>("walking", new BobbleWalking(this)));

	m_pState = m_pStateMap.at("idle");
}

BobblePlayer::~BobblePlayer()
{
	for (auto state : m_pStateMap)
	{
		delete state.second;
	}
	m_pStateMap.clear();
}

void BobblePlayer::Initialize()
{
	m_pBobblePlayer = new GameObject();
	m_pBobblePlayer->AddComponent(new CollisionComponent(32, 32));
	auto* pControllerComponent = new ControllerComponent();
	m_pBobblePlayer->AddComponent(pControllerComponent);

	// ---------------------------------------------------------------------------------------------------- //
	
	m_pSpriteComponent = new SpriteComponent("Player.png", 4, 2, 32);
	m_pSpriteComponent->AddClip(2, true);
	m_pSpriteComponent->AddClip(2, true);
	m_pSpriteComponent->AddClip(2, false);
	m_pSpriteComponent->AddClip(2, false);
	m_pSpriteComponent->SetClipIndex(0);
	
	m_pBobblePlayer->AddComponent(m_pSpriteComponent);

	// ---------------------------------------------------------------------------------------------------- //

	InputAction* pMoveLeft = new InputAction("PlayerMoveLeft", new MoveLeftCommand(pControllerComponent, m_pSpriteComponent), KEY_LEFT, MOUSE_UNKNOWN, BUTTON_STATE::PRESSED);
	InputAction* pMoveRight = new InputAction("PlayerMoveRight", new MoveRightCommand(pControllerComponent, m_pSpriteComponent), KEY_RIGHT, MOUSE_UNKNOWN, BUTTON_STATE::PRESSED);
	InputAction* pStopMoveLeft = new InputAction("PlayerStopMoveLeft", new StopMoveLeftCommand(pControllerComponent, m_pSpriteComponent), KEY_LEFT, MOUSE_UNKNOWN, BUTTON_STATE::RELEASED);
	InputAction* pStopMoveRight = new InputAction("PlayerStopMoveRight", new StopMoveRightCommand(pControllerComponent, m_pSpriteComponent), KEY_RIGHT, MOUSE_UNKNOWN, BUTTON_STATE::RELEASED);
	InputAction* pJump = new InputAction("PlayerJump", new JumpCommand(pControllerComponent, m_pSpriteComponent), KEY_SPACE, MOUSE_UNKNOWN, BUTTON_STATE::PRESSED);

	m_pInputManager->AddInputActions(pMoveLeft);
	m_pInputManager->AddInputActions(pMoveRight);
	m_pInputManager->AddInputActions(pJump);
	m_pInputManager->AddInputActions(pStopMoveLeft);
	m_pInputManager->AddInputActions(pStopMoveRight);

	m_pBobblePlayer->GetTransform()->Translate(0, 384);
}

void BobblePlayer::SetAnimationClip(int index)
{
	m_pSpriteComponent->SetClipIndex(index);
}

void BobblePlayer::ChangeState(const std::string& newState)
{
	m_pState->OnExit();
	m_pState = m_pStateMap.at(newState);
	m_pState->OnEnter();
}

void BobblePlayer::Update()
{
	m_pState->Update();
}

void BobblePlayer::Render()
{

}

GameObject* BobblePlayer::GetGameObject()
{
	return m_pBobblePlayer;
}

