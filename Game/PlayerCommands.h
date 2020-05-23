#pragma once
#include "Commands.h"
#include "ControllerComponent.h"
#include "TestPlayer.h"

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

