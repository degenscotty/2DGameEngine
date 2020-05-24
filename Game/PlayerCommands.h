#pragma once
#include "Commands.h"
#include "ControllerComponent.h"

class MoveLeftCommand : public Command
{
public:
	explicit MoveLeftCommand(ControllerComponent* pControllerComponent)
		: m_pControllerComponent(pControllerComponent)
	{
	}

	void Execute() override
	{
		m_pControllerComponent->MoveLeft();
	}
	
private:
	ControllerComponent* m_pControllerComponent;
};

class MoveRightCommand : public Command
{
public:
	explicit MoveRightCommand(ControllerComponent* pControllerComponent)
		: m_pControllerComponent(pControllerComponent)
	{
	}

	void Execute() override
	{
		m_pControllerComponent->MoveRight();
	}

private:
	ControllerComponent* m_pControllerComponent;
};

class JumpCommand : public Command
{
public:
	explicit JumpCommand(ControllerComponent* pControllerComponent)
		: m_pControllerComponent(pControllerComponent)
	{
	}

	void Execute() override
	{
		m_pControllerComponent->Jump();
	}

private:
	ControllerComponent* m_pControllerComponent;
};

class StopMoveRightCommand : public Command
{
public:
	explicit StopMoveRightCommand(ControllerComponent* pControllerComponent)
		: m_pControllerComponent(pControllerComponent)
	{
	}

	void Execute() override
	{
		m_pControllerComponent->StopMove();
	}

private:
	ControllerComponent* m_pControllerComponent;
};

class StopMoveLeftCommand : public Command
{
public:
	explicit StopMoveLeftCommand(ControllerComponent* pControllerComponent)
		: m_pControllerComponent(pControllerComponent)
	{
	}

	void Execute() override
	{
		m_pControllerComponent->StopMove();
	}

private:
	ControllerComponent* m_pControllerComponent;
};



