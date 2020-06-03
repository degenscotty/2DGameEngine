#pragma once

class State
{
public:
	State() = default;
	virtual ~State() = default;

	State(const State& other) = delete;
	State(State&& other) noexcept = delete;
	State& operator=(const State& other) = delete;
	State& operator=(State&& other) noexcept = delete;

	virtual void Update() = 0;
	virtual void OnEnter() = 0;
	virtual void OnExit() = 0;
};
