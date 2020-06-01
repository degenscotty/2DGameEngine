#pragma once
#include "Commands.h"
#include "Bubble.h"

class BubbleRMaitaC : public Command
{
public:
	explicit BubbleRMaitaC(Bubble* pBubble)
		: m_pBubble(pBubble)
	{
	}

	void Execute() override
	{
	}

private:
	Bubble* m_pBubble;
};