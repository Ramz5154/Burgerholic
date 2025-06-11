#include "window.h"

//https://medium.com/nerd-for-tech/creating-a-window-using-sdl2-0bcca0f6e449
//HOW TO MAKE A WINDOW 


Window::Window(const char* title, int width, int height)
{
	GameWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);


	if (GameWindow == nullptr) {
		printf("gameWindow is null", SDL_GetError());
	}

	renderer = SDL_CreateRenderer(GameWindow, -1, SDL_RENDERER_ACCELERATED);

	if (renderer == nullptr) {
		printf("renderer is null ", SDL_GetError());
	}

}

SDL_Renderer* Window::SDL_GetRenderer()
{
	return renderer;
	
}

void Window::close()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(GameWindow);

	renderer = NULL;
	GameWindow = NULL;

	SDL_Quit();
}
