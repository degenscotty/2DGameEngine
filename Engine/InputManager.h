#pragma once
#include "Commands.h"
#include "Singleton.h"
#include "InputDefinitions.h"

enum class BUTTON_STATE
{
	PRESSED,
	RELEASED,
	DOWN
};

struct InputAction final
{
	explicit InputAction(const std::string& name, Command* pCommand, KeyBoardButton key, MouseButton mouseButton, BUTTON_STATE buttonState)
		: m_ActionName(name)
		, m_pCommand(pCommand)
		, m_ButtonState(buttonState)
		, m_Key(key)
		, m_MouseButton(mouseButton)
		, m_IsTriggered(false)
	{
	}

	~InputAction()
	{
		delete m_pCommand;
	}

	std::string m_ActionName;
	Command* m_pCommand;
	BUTTON_STATE m_ButtonState;
	KeyBoardButton m_Key;
	MouseButton m_MouseButton;
	bool m_IsTriggered;
};

class InputManager : public Singleton<InputManager>
{
public:
	InputManager();
	~InputManager();

	InputManager(const InputManager& other) = delete;
	InputManager(InputManager&& other) noexcept = delete;
	InputManager& operator=(const InputManager& other) = delete;
	InputManager& operator=(InputManager&& other) noexcept = delete;

	void Update();
	void IsInputActionTriggered();
	void ProcessInputActions();

	void ClearInputActions();

	void AddInputActions(InputAction* inputAction);

	bool IsKeyPressed(int keycode);
	bool IsMouseButtonPressed(int button);

	float GetMouseX();
	float GetMouseY();

	const glm::vec2 GetMousePos();

	bool Quit();

	void QuitGame();

private:
	SDL_Event e{};

	bool m_KeyDown[KEYBOARD_SIZE]{};
	bool m_KeyUp[KEYBOARD_SIZE]{};

	bool m_MouseDown[MOUSE_MAX]{};
	bool m_MouseUp[MOUSE_MAX]{};

	int m_MouseX{};
	int m_MouseY{};

	bool m_Quit = false;

	std::vector<InputAction*> m_InputActions;
};


