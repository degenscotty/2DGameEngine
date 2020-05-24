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

class MoveUpCommand : public Command
{
public:
	explicit MoveUpCommand(ControllerComponent* pControllerComponent)
		: m_pControllerComponent(pControllerComponent)
	{
	}

	void Execute() override
	{
		m_pControllerComponent->MoveUp();
	}

private:
	ControllerComponent* m_pControllerComponent;
};

class MoveDownCommand : public Command
{
public:
	explicit MoveDownCommand(ControllerComponent* pControllerComponent)
		: m_pControllerComponent(pControllerComponent)
	{
	}

	void Execute() override
	{
		m_pControllerComponent->MoveDown();
	}

private:
	ControllerComponent* m_pControllerComponent;
};


