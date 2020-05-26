#pragma once
#include <map>

#include "../Game/BobbleState.h"
#include "BaseComponent.h"

class StateComponent : public BaseComponent
{
public:
	StateComponent();
	~StateComponent();

	StateComponent(const StateComponent& other) = delete;
	StateComponent(StateComponent&& other) noexcept = delete;
	StateComponent& operator=(const StateComponent& other) = delete;
	StateComponent& operator=(StateComponent&& other) noexcept = delete;

	void AddState(const std::pair<std::string, State*>& statePair);
	void ChangeState(const std::string& stateName);
	void SetState(const std::string& stateName);

protected:
	void Initialize() override;
	void Update() override;
	void Render() override;

private:
	State* m_pState;
	std::map<std::string, State*> m_StateMap;
};

