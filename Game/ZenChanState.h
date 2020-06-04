#pragma once
#include "State.h"
#include "Commands.h"

#include <map>
#include <string>

class ZenChan;

class ZenChanState : public State
{
public:
	ZenChanState(ZenChan* pZenChan) : m_pZenChan(pZenChan) {}
	~ZenChanState()
	{
		for (auto command : m_CommandMap)
		{
			delete command.second;
		}
		m_CommandMap.clear();
	}

	ZenChanState(const ZenChanState& other) = delete;
	ZenChanState(ZenChanState&& other) noexcept = delete;
	ZenChanState& operator=(const ZenChanState& other) = delete;
	ZenChanState& operator=(ZenChanState&& other) noexcept = delete;

	virtual void Update() = 0;
	virtual void OnEnter() = 0;
	virtual void OnExit() = 0;

	virtual void AddCommand(const std::string& commandName, Command* pCommand)
	{
		m_CommandMap.insert(std::make_pair(commandName, pCommand));
	}

protected:
	ZenChan* m_pZenChan;
	std::map<std::string, Command*> m_CommandMap;
};

