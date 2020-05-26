#pragma once
#include "Commands.h"
#include "ControllerComponent.h"
#include "BobblePlayer.h"

class MoveLeftCommand : public Command
{
public:
	explicit MoveLeftCommand(ControllerComponent* pControllerComponent, BobblePlayer* pBobblePlayer)
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

class MoveRightCommand : public Command
{
public:
	explicit MoveRightCommand(ControllerComponent* pControllerComponent, BobblePlayer* pBobblePlayer)
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

class JumpCommand : public Command
{
public:
	explicit JumpCommand(ControllerComponent* pControllerComponent, BobblePlayer* pBobblePlayer)
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

class StopMoveRightCommand : public Command
{
public:
	explicit StopMoveRightCommand(ControllerComponent* pControllerComponent, BobblePlayer* pBobblePlayer)
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

class StopMoveLeftCommand : public Command
{
public:
	explicit StopMoveLeftCommand(ControllerComponent* pControllerComponent, BobblePlayer* pBobblePlayer)
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



