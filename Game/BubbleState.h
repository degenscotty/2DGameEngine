#pragma once
#include <map>
#include <string>

#include "Commands.h"
#include "State.h"

class Bubble;

class BubbleState : public State
{
public:
	BubbleState(Bubble* pBubble) : m_pBubble(pBubble) {}
	~BubbleState()
	{
		for (auto command : m_CommandMap)
		{
			delete command.second;
		}
		m_CommandMap.clear();
	}

	BubbleState(const BubbleState& other) = delete;
	BubbleState(BubbleState&& other) noexcept = delete;
	BubbleState& operator=(const BubbleState& other) = delete;
	BubbleState& operator=(BubbleState&& other) noexcept = delete;

	virtual void Update() = 0;
	virtual void Swap() = 0;
	virtual void OnEnter() = 0;
	virtual void OnExit() = 0;

	virtual void AddCommand(const std::string& commandName, Command* pCommand)
	{
		m_CommandMap.insert(std::make_pair(commandName, pCommand));
	}

protected:
	Bubble* m_pBubble;
	std::map<std::string, Command*> m_CommandMap;
};

