#pragma once
#include "Commands.h"
#include "ControllerComponent.h"
#include "SceneManager.h"
#include "BobblePlayer.h"
#include "Bubble.h"

class BobbleMoveLeftC : public Command
{
public:
	explicit BobbleMoveLeftC(ControllerComponent* pControllerComponent, BobblePlayer* pBobblePlayer)
		: m_pControllerComponent(pControllerComponent)
		, m_pBobblePlayer(pBobblePlayer)
	{
	}

	void Execute() override
	{
		m_pControllerComponent->MoveLeft();
		m_pBobblePlayer->ChangeState("walking");
		m_pBobblePlayer->SetFlipState(SDL_FLIP_HORIZONTAL);
	}

private:
	ControllerComponent* m_pControllerComponent;
	BobblePlayer* m_pBobblePlayer;
};

class BobbleMoveRightC : public Command
{
public:
	explicit BobbleMoveRightC(ControllerComponent* pControllerComponent, BobblePlayer* pBobblePlayer)
		: m_pControllerComponent(pControllerComponent)
		, m_pBobblePlayer(pBobblePlayer)
	{
	}

	void Execute() override
	{
		m_pControllerComponent->MoveRight();
		m_pBobblePlayer->ChangeState("walking");
		m_pBobblePlayer->SetFlipState(SDL_FLIP_NONE);
	}

private:
	ControllerComponent* m_pControllerComponent;
	BobblePlayer* m_pBobblePlayer;
};

class BobbleJumpC : public Command
{
public:
	explicit BobbleJumpC(ControllerComponent* pControllerComponent, BobblePlayer* pBobblePlayer)
		: m_pControllerComponent(pControllerComponent)
		, m_pBobblePlayer(pBobblePlayer)
	{
	}

	void Execute() override
	{
		m_pControllerComponent->Jump();
		m_pBobblePlayer->ChangeState("jumping");
	}

private:
	ControllerComponent* m_pControllerComponent;
	BobblePlayer* m_pBobblePlayer;
};

class BobbleStopMoveRightC : public Command
{
public:
	explicit BobbleStopMoveRightC(ControllerComponent* pControllerComponent, BobblePlayer* pBobblePlayer)
		: m_pControllerComponent(pControllerComponent)
		, m_pBobblePlayer(pBobblePlayer)
	{
	}

	void Execute() override
	{
		m_pControllerComponent->StopMove();
		m_pBobblePlayer->ChangeState("idle");
		m_pBobblePlayer->SetFlipState(SDL_FLIP_NONE);
	}

private:
	ControllerComponent* m_pControllerComponent;
	BobblePlayer* m_pBobblePlayer;
};

class BobbleStopMoveLeftC : public Command
{
public:
	explicit BobbleStopMoveLeftC(ControllerComponent* pControllerComponent, BobblePlayer* pBobblePlayer)
		: m_pControllerComponent(pControllerComponent)
		, m_pBobblePlayer(pBobblePlayer)
	{
	}

	void Execute() override
	{
		m_pControllerComponent->StopMove();
		m_pBobblePlayer->ChangeState("idle");
		m_pBobblePlayer->SetFlipState(SDL_FLIP_HORIZONTAL);
	}

private:
	ControllerComponent* m_pControllerComponent;
	BobblePlayer* m_pBobblePlayer;
};

class ShootBubbleC : public Command
{
public:
	explicit ShootBubbleC(BobblePlayer* pBobblePlayer)
		: m_pBobblePlayer(pBobblePlayer)
		, m_pSceneManager(SceneManager::GetInstance())
		, m_pLevelManager(LevelManager::GetInstance())
	{
	}

	void Execute() override
	{
		Bubble* pBubble = new Bubble();

		pBubble->Initialize();
		pBubble->SetPosition(m_pBobblePlayer->GetPosition());
		
		if (m_pBobblePlayer->GetFlipState() == SDL_FLIP_NONE)
			pBubble->ShootBubble(true);
		else
			pBubble->ShootBubble(false);
		
		m_pSceneManager->GetActiveScene()->Add(pBubble->GetGameObject());

		m_pLevelManager->AddBubble(pBubble);
	}

private:
	BobblePlayer* m_pBobblePlayer;
	SceneManager* m_pSceneManager;
	LevelManager* m_pLevelManager;
};



