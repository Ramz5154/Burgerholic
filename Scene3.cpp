#include "Scene3.h"
#include "Scene1.h"
#include <iostream>
#include <SDL2/SDL_ttf.h>
#include <ctime>
#include "Scene0.h"

Scene3::Scene3()
{
}

Scene3::Scene3(SDL_Renderer* renderer) {
	font = TTF_OpenFont("assets/Pixelon.ttf", 100); //font size
	if (!font) {
		std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
	}
	scoreBoard = new ImageRenderer(renderer, "assets/scoreBoard.png");

}

Scene3::~Scene3()
{
}

void Scene3::HandleEvents(SDL_Event& event)
{
}

void Scene3::Update(double deltaTime)
{
}

void Scene3::Render(SDL_Renderer* renderer)
{
	scoreBoard->Render(0, 0, 1080, 720);

	std::string Level = std::to_string(scene1.GetLevel());
	std::string Score = std::to_string(scene1.ordersFinished) + Level;

	renderText(renderer, font, Level, 250, 40);
	
}

int Scene3::GetSceneState()
{
	return scene0.sceneState;
}

void Scene3::renderText(SDL_Renderer* renderer, TTF_Font* font, std::string text, int x, int y)//renders text for customers done
{
	SDL_Color color = { 255, 255, 255 };
	SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_Rect dst = { x, y, surface->w, surface->h };
	SDL_FreeSurface(surface);
	SDL_RenderCopy(renderer, texture, NULL, &dst);
	SDL_DestroyTexture(texture);
}