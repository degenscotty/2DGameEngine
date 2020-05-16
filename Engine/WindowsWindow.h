#pragma once
#include "Window.h"
#include "InputManager.h"

class WindowsWindow final : public Window
{
public:
	WindowsWindow(const WindowProps& props);
	virtual ~WindowsWindow();

	void OnUpdate() override;

	unsigned int GetWidth() const override { return m_Data.Width; }
	unsigned int GetHeight() const override { return m_Data.Height; }

	virtual void* GetNativeWindow() const { return m_pWindow; }
	virtual void* GetSDLContext() const { return m_Context; }

	SDL_Window* GetSDLWindow() { return m_pWindow; }
	
private:
	void Init(const WindowProps& props);
	void Shutdown();
	
private:
	SDL_Window* m_pWindow;
	SDL_GLContext m_Context;
	InputManager* m_pInput;

	struct WindowData
	{
		std::string Title;
		unsigned int Width, Height;
	};

	WindowData m_Data;
};
