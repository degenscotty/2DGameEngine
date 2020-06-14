#pragma once
#include "Commands.h"
#include "ControllerComponent.h"
#include "Maita.h"
#include "MaitaPlayer.h"

class MaitaMoveLeftAIC : public Command
{
public:
	explicit MaitaMoveLeftAIC(ControllerComponent* pControllerComponent, Maita* pMaita)
		: m_pControllerComponent(pControllerComponent)
		, m_pMaita(pMaita)
	{
	}

	void Execute() override
	{
		m_pControllerComponent->MoveLeft();
		m_pMaita->SetFlipState(SDL_FLIP_NONE);
	}

private:
	ControllerComponent* m_pControllerComponent;
	Maita* m_pMaita;
};

class MaitaMoveRightAIC : public Command
{
public:
	explicit MaitaMoveRightAIC(ControllerComponent* pControllerComponent, Maita* pMaita)
		: m_pControllerComponent(pControllerComponent)
		, m_pMaita(pMaita)
	{
	}

	void Execute() override
	{
		m_pControllerComponent->MoveRight();
		m_pMaita->SetFlipState(SDL_FLIP_HORIZONTAL);
	}

private:
	ControllerComponent* m_pControllerComponent;
	Maita* m_pMaita;
};

class MaitaJumpAIC : public Command
{
public:
	explicit MaitaJumpAIC(ControllerComponent* pControllerComponent, Maita* pMaita)
		: m_pControllerComponent(pControllerComponent)
		, m_pMaita(pMaita)
	{
	}

	void Execute() override
	{
		m_pControllerComponent->Jump();
	}

private:
	ControllerComponent* m_pControllerComponent;
	Maita* m_pMaita;
};

class MaitaStopMovingAIC : public Command
{
public:
	explicit MaitaStopMovingAIC(ControllerComponent* pControllerComponent, Maita* pMaita)
		: m_pControllerComponent(pControllerComponent)
		, m_pMaita(pMaita)
	{
	}

	void Execute() override
	{
		m_pControllerComponent->StopMove();
	}

private:
	ControllerComponent* m_pControllerComponent;
	Maita* m_pMaita;
};

class MaitaMoveLeftC : public Command
{
public:
	explicit MaitaMoveLeftC(ControllerComponent* pControllerComponent, MaitaPlayer* pMaitaPlayer)
		: m_pControllerComponent(pControllerComponent)
		, m_pMaitaPlayer(pMaitaPlayer)
	{
	}

	void Execute() override
	{
		m_pControllerComponent->MoveLeft();
		m_pMaitaPlayer->SetFlipState(SDL_FLIP_NONE);
	}

private:
	ControllerComponent* m_pControllerComponent;
	MaitaPlayer* m_pMaitaPlayer;
};

class MaitaMoveRightC : public Command
{
public:
	explicit MaitaMoveRightC(ControllerComponent* pControllerComponent, MaitaPlayer* pMaitaPlayer)
		: m_pControllerComponent(pControllerComponent)
		, m_pMaitaPlayer(pMaitaPlayer)
	{
	}

	void Execute() override
	{
		m_pControllerComponent->MoveRight();
		m_pMaitaPlayer->SetFlipState(SDL_FLIP_HORIZONTAL);
	}

private:
	ControllerComponent* m_pControllerComponent;
	MaitaPlayer* m_pMaitaPlayer;
};

class MaitaJumpC : public Command
{
public:
	explicit MaitaJumpC(ControllerComponent* pControllerComponent, MaitaPlayer* pMaitaPlayer)
		: m_pControllerComponent(pControllerComponent)
		, m_pMaitaPlayer(pMaitaPlayer)
	{
	}

	void Execute() override
	{
		m_pControllerComponent->Jump();
	}

private:
	ControllerComponent* m_pControllerComponent;
	MaitaPlayer* m_pMaitaPlayer;
};

class MaitaStopMovingC : public Command
{
public:
	explicit MaitaStopMovingC(ControllerComponent* pControllerComponent, MaitaPlayer* pMaitaPlayer)
		: m_pControllerComponent(pControllerComponent)
		, m_pMaitaPlayer(pMaitaPlayer)
	{
	}

	void Execute() override
	{
		m_pControllerComponent->StopMove();
	}

private:
	ControllerComponent* m_pControllerComponent;
	MaitaPlayer* m_pMaitaPlayer;
};

