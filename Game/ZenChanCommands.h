#pragma once
#include "Commands.h"
#include "ZenChan.h"
#include "ControllerComponent.h"

class ZenChanMoveLeftC : public Command
{
public:
	explicit ZenChanMoveLeftC(ControllerComponent* pControllerComponent, ZenChan* pZenChan)
		: m_pControllerComponent(pControllerComponent)
		, m_pZenChan(pZenChan)
	{
	}

	void Execute() override
	{
		m_pControllerComponent->MoveLeft();
		m_pZenChan->SetFlipState(SDL_FLIP_HORIZONTAL);
	}

private:
	ControllerComponent* m_pControllerComponent;
	ZenChan* m_pZenChan;
};

class ZenChanMoveRightC : public Command
{
public:
	explicit ZenChanMoveRightC(ControllerComponent* pControllerComponent, ZenChan* pZenChan)
		: m_pControllerComponent(pControllerComponent)
		, m_pZenChan(pZenChan)
	{
	}

	void Execute() override
	{
		m_pControllerComponent->MoveRight();
		m_pZenChan->SetFlipState(SDL_FLIP_NONE);
	}

private:
	ControllerComponent* m_pControllerComponent;
	ZenChan* m_pZenChan;
};

class ZenChanJumpC : public Command
{
public:
	explicit ZenChanJumpC(ControllerComponent* pControllerComponent, ZenChan* pZenChan)
		: m_pControllerComponent(pControllerComponent)
		, m_pZenChan(pZenChan)
	{
	}

	void Execute() override
	{
		m_pControllerComponent->Jump();
	}

private:
	ControllerComponent* m_pControllerComponent;
	ZenChan* m_pZenChan;
};

class ZenChanStopMovingC : public Command
{
public:
	explicit ZenChanStopMovingC(ControllerComponent* pControllerComponent, ZenChan* pZenChan)
		: m_pControllerComponent(pControllerComponent)
		, m_pZenChan(pZenChan)
	{
	}

	void Execute() override
	{
		m_pControllerComponent->StopMove();
	}

private:
	ControllerComponent* m_pControllerComponent;
	ZenChan* m_pZenChan;
};