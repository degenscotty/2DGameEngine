#include "pch.h"
#include "StateComponent.h"

StateComponent::StateComponent()
	: m_pState(nullptr)
{

}

StateComponent::~StateComponent()
{
	for (auto state : m_StateMap)
	{
		delete state.second;
	}
	m_StateMap.clear();
}
void StateComponent::Initialize()
{

}

void StateComponent::AddState(const std::string& stateName, State* pState)
{
	m_StateMap.insert(std::make_pair(stateName, pState));
}

void StateComponent::SetState(const std::string& stateName)
{
	if (m_StateMap.at(stateName))
		m_pState = m_StateMap.at(stateName);
}

void StateComponent::ChangeState(const std::string& stateName)
{
	if (m_pState && m_pState != m_StateMap[stateName])
	{
		m_pState->OnExit();
		m_pState = m_StateMap.at(stateName);
		m_pState->OnEnter();
	}
}

void StateComponent::Update()
{
	if (m_pState)
		m_pState->Update();
}

void StateComponent::Render()
{

}