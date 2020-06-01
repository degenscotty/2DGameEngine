#include "pch.h"
#include "InputManager.h"

InputManager::InputManager()
{

}

InputManager::~InputManager()
{
	for (auto inputAction : m_InputActions)
	{
		delete inputAction;
	}

	m_InputActions.clear();
}

void InputManager::ProcessInputActions()
{
	for (auto inputAction : m_InputActions)
	{
		if (inputAction->m_IsTriggered)
		{
			inputAction->m_pCommand->Execute();
			inputAction->m_IsTriggered = false;
		}
	}
}

void InputManager::IsInputActionTriggered()
{
	for (auto inputAction : m_InputActions)
	{
		if (inputAction->m_Key > KEY_UNKNOWN && inputAction->m_Key < KEYBOARD_SIZE + 1)
		{
			if (inputAction->m_ButtonState == BUTTON_STATE::PRESSED || inputAction->m_ButtonState == BUTTON_STATE::DOWN)
			{
				if (m_KeyDown[inputAction->m_Key])
				{
					inputAction->m_IsTriggered = true;
				}
			}
			else
			{
				if (m_KeyUp[inputAction->m_Key])
				{
					inputAction->m_IsTriggered = true;
				}
			}
		}
		else if (inputAction->m_MouseButton > -1 && inputAction->m_MouseButton < MOUSE_MAX)
		{
			if (inputAction->m_ButtonState == BUTTON_STATE::PRESSED || inputAction->m_ButtonState == BUTTON_STATE::DOWN)
			{
				if (m_MouseDown[inputAction->m_MouseButton])
				{
					inputAction->m_IsTriggered = true;
				}
			}
			else
			{
				if (m_MouseUp[inputAction->m_MouseButton])
				{
					inputAction->m_IsTriggered = true;
				}
			}
		}
		else
		{
			CORE_INFO("InputManager::IsInputActionTriggered() > INVALID INPUT :: INPUTACTION -> {0}", inputAction->m_ActionName);
		}
	}
}

void InputManager::Update()
{
	for (int i{ 0 }; i < KEYBOARD_SIZE; i++)
	{
		if (m_KeyDown[i] == true && m_KeyUp[i] == true)
		{
			m_KeyDown[i] = false;
		}
		else if (m_KeyDown[i] == false && m_KeyUp[i] == true)
		{
			m_KeyDown[i] = false;
		}
		m_KeyUp[i] = false;
	}

	for (int i{ 0 }; i < MOUSE_MAX; i++)
	{
		m_MouseDown[i] = false;
		m_MouseDown[i] = false;
	}


	if (SDL_PollEvent(&e) != 0)
	{
		// Handle the polled event
		switch (e.type)
		{
		case SDL_QUIT:
		{
			m_Quit = true;
		}
		break;
		case SDL_KEYDOWN:
		{
			if (e.key.repeat != 0)
			{
				m_KeyDown[e.key.keysym.scancode] = true;
			}
			else
			{
				m_KeyDown[e.key.keysym.scancode] = true;
			}
		}
		break;
		case SDL_KEYUP:
		{
			m_KeyUp[e.key.keysym.scancode] = true;
		}
		break;
		case SDL_MOUSEMOTION:
		{
			m_MouseX = e.motion.x;
			m_MouseY = e.motion.y;
		}
		break;
		case SDL_MOUSEBUTTONDOWN:
		{
			if (e.button.button == SDL_BUTTON_LEFT)
			{
				m_MouseDown[MOUSE_LEFT] = true;
			}
			if (e.button.button == SDL_BUTTON_RIGHT)
			{
				m_MouseDown[MOUSE_RIGHT] = true;
			}
		}
		break;
		case SDL_MOUSEBUTTONUP:
		{
			if (e.button.button == SDL_BUTTON_LEFT)
			{
				m_MouseUp[MOUSE_LEFT] = true;
			}
			if (e.button.button == SDL_BUTTON_RIGHT)
			{
				m_MouseUp[MOUSE_RIGHT] = true;
			}
		}
		break;
		}
	}

	IsInputActionTriggered();
	ProcessInputActions();
}

void InputManager::AddInputActions(InputAction* inputAction)
{
	m_InputActions.push_back(inputAction);
}

bool InputManager::IsKeyPressed(int keycode)
{
	return m_KeyDown[keycode];
}

bool InputManager::IsMouseButtonPressed(int button)
{
	return m_MouseDown[button];
}

float InputManager::GetMouseX()
{
	return (float)m_MouseX;
}

float InputManager::GetMouseY()
{
	return (float)m_MouseY;
}

const glm::vec2 InputManager::GetMousePos()
{
	return { (float)m_MouseX, (float)m_MouseY };
}

bool InputManager::Quit()
{
	return m_Quit;
}

void InputManager::QuitGame()
{
	m_Quit = true;
}

