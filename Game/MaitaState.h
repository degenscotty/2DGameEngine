#pragma once
#include "State.h"
#include "Commands.h"

#include <map>
#include <string>

class Maita;

class MaitaState : public State
{
public:
	MaitaState(Maita* pMaita) : m_pMaita(pMaita) {}
	~MaitaState()
	{
		for (auto command : m_CommandMap)
		{
			delete command.second;
		}
		m_CommandMap.clear();
	}

	MaitaState(const MaitaState& other) = delete;
	MaitaState(MaitaState&& other) noexcept = delete;
	MaitaState& operator=(const MaitaState& other) = delete;
	MaitaState& operator=(MaitaState&& other) noexcept = delete;

	virtual void Update() = 0;
	virtual void Swap() = 0;
	virtual void OnEnter() = 0;
	virtual void OnExit() = 0;

	virtual void AddCommand(const std::string& commandName, Command* pCommand)
	{
		m_CommandMap.insert(std::make_pair(commandName, pCommand));
	}

protected:
	Maita* m_pMaita;
	std::map<std::string, Command*> m_CommandMap;
};

