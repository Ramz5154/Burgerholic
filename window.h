#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Window
{
public:
	bool gameRunning = true;
	Window();
	Window(const char* title, int width, int height);
	SDL_Renderer* SDL_GetRenderer();
	void close();
private:

	SDL_Window* GameWindow;
	SDL_Renderer* renderer;

};

