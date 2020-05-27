#pragma once
#include "Commands.h"
#include "ControllerComponent.h"
#include "Maita.h"

class MaitaMoveLeftC : public Command
{
public:
	explicit MaitaMoveLeftC(ControllerComponent* pControllerComponent, Maita* pMaita)
		: m_pControllerComponent(pControllerComponent)
		, m_pEnemyMaita(pMaita)
	{
	}

	void Execute() override
	{
		m_pControllerComponent->MoveLeft();
		m_pEnemyMaita->SetFlipState(SDL_FLIP_NONE);
	}

private:
	ControllerComponent* m_pControllerComponent;
	Maita* m_pEnemyMaita;
};

class MaitaMoveRightC : public Command
{
public:
	explicit MaitaMoveRightC(ControllerComponent* pControllerComponent, Maita* pMaita)
		: m_pControllerComponent(pControllerComponent)
		, m_pEnemyMaita(pMaita)
	{
	}

	void Execute() override
	{
		m_pControllerComponent->MoveRight();
		m_pEnemyMaita->SetFlipState(SDL_FLIP_HORIZONTAL);
	}

private:
	ControllerComponent* m_pControllerComponent;
	Maita* m_pEnemyMaita;
};

class MaitaJumpC : public Command
{
public:
	explicit MaitaJumpC(ControllerComponent* pControllerComponent, Maita* pMaita)
		: m_pControllerComponent(pControllerComponent)
		, m_pEnemyMaita(pMaita)
	{
	}

	void Execute() override
	{
		m_pControllerComponent->Jump();
	}

private:
	ControllerComponent* m_pControllerComponent;
	Maita* m_pEnemyMaita;
};

class MaitaStopMovingC : public Command
{
public:
	explicit MaitaStopMovingC(ControllerComponent* pControllerComponent, Maita* pMaita)
		: m_pControllerComponent(pControllerComponent)
		, m_pEnemyMaita(pMaita)
	{
	}

	void Execute() override
	{
		m_pControllerComponent->StopMove();
	}

private:
	ControllerComponent* m_pControllerComponent;
	Maita* m_pEnemyMaita;
};
