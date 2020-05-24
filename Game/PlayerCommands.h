#pragma once
#include "Commands.h"
#include "ControllerComponent.h"
#include "SpriteComponent.h"

class MoveLeftCommand : public Command
{
public:
	explicit MoveLeftCommand(ControllerComponent* pControllerComponent, SpriteComponent* pSpriteComponent)
		: m_pControllerComponent(pControllerComponent)
		, m_pSpriteComponent(pSpriteComponent)
	{
	}

	void Execute() override
	{
		m_pControllerComponent->MoveLeft();
		m_pSpriteComponent->SetClipIndex(1);
		m_pSpriteComponent->SetFlip(SDL_FLIP_HORIZONTAL);
	}

private:
	ControllerComponent* m_pControllerComponent;
	SpriteComponent* m_pSpriteComponent;
};

class MoveRightCommand : public Command
{
public:
	explicit MoveRightCommand(ControllerComponent* pControllerComponent, SpriteComponent* pSpriteComponent)
		: m_pControllerComponent(pControllerComponent)
		, m_pSpriteComponent(pSpriteComponent)
	{
	}

	void Execute() override
	{
		m_pControllerComponent->MoveRight();
		m_pSpriteComponent->SetClipIndex(1);
		m_pSpriteComponent->SetFlip(SDL_FLIP_NONE);
	}

private:
	ControllerComponent* m_pControllerComponent;
	SpriteComponent* m_pSpriteComponent;
};

class JumpCommand : public Command
{
public:
	explicit JumpCommand(ControllerComponent* pControllerComponent, SpriteComponent* pSpriteComponent)
		: m_pControllerComponent(pControllerComponent)
		, m_pSpriteComponent(pSpriteComponent)
	{
	}

	void Execute() override
	{
		m_pControllerComponent->Jump();
	}

private:
	ControllerComponent* m_pControllerComponent;
	SpriteComponent* m_pSpriteComponent;
};

class StopMoveRightCommand : public Command
{
public:
	explicit StopMoveRightCommand(ControllerComponent* pControllerComponent, SpriteComponent* pSpriteComponent)
		: m_pControllerComponent(pControllerComponent)
		, m_pSpriteComponent(pSpriteComponent)
	{
	}

	void Execute() override
	{
		m_pControllerComponent->StopMove();
		m_pSpriteComponent->SetClipIndex(0);
	}

private:
	ControllerComponent* m_pControllerComponent;
	SpriteComponent* m_pSpriteComponent;
};

class StopMoveLeftCommand : public Command
{
public:
	explicit StopMoveLeftCommand(ControllerComponent* pControllerComponent, SpriteComponent* pSpriteComponent)
		: m_pControllerComponent(pControllerComponent)
		, m_pSpriteComponent(pSpriteComponent)
	{
	}

	void Execute() override
	{
		m_pControllerComponent->StopMove();
		m_pSpriteComponent->SetClipIndex(0);
	}

private:
	ControllerComponent* m_pControllerComponent;
	SpriteComponent* m_pSpriteComponent;
};



