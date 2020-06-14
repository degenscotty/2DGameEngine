#pragma once
#include "State.h"
#include "Commands.h"

#include <map>
#include <string>

class Maita;

class MaitaStateAI : public State
{
public:
	MaitaStateAI(Maita* pMaita) : m_pMaita(pMaita) {}
	~MaitaStateAI()
	{
		for (auto command : m_CommandMap)
		{
			delete command.second;
		}
		m_CommandMap.clear();
	}

	MaitaStateAI(const MaitaStateAI& other) = delete;
	MaitaStateAI(MaitaStateAI&& other) noexcept = delete;
	MaitaStateAI& operator=(const MaitaStateAI& other) = delete;
	MaitaStateAI& operator=(MaitaStateAI&& other) noexcept = delete;

	virtual void Update() = 0;
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

