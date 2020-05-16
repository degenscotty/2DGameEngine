#pragma once

#include <SDL.h>
#include <string>

struct WindowProps
{
	std::string Title;
	unsigned int Width;
	unsigned int Height;

	WindowProps(const std::string& title = "SDL Engine",
		unsigned int width = 512,
		unsigned int height = 448)
		: Title(title), Width(width), Height(height)
	{
	}
};

// Interface representing a desktop system based Window
class Window
{
public:
	virtual ~Window() {};

	virtual void OnUpdate() = 0;

	virtual unsigned int GetWidth() const = 0;
	virtual unsigned int GetHeight() const = 0;

	virtual SDL_Window* GetSDLWindow() = 0;

	virtual void* GetNativeWindow() const = 0;
	virtual void* GetSDLContext() const = 0;

	static Window* Create(const WindowProps& props = WindowProps());
};

