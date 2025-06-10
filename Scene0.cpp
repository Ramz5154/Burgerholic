#include "Scene0.h"
#include <iostream>



Scene0::Scene0()
{
}

Scene0::Scene0(SDL_Renderer* renderer)
{
	mainMenu = new ImageRenderer(renderer, "assets/MainMenu.png");
	quit = { 270,515,550,100 };
	start = { 270,245,550,100 };
}

Scene0::~Scene0()
{
    delete mainMenu;
}

void Scene0::HandleEvents(SDL_Event& event)
{
    if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
        int mouseX = event.button.x;
        int mouseY = event.button.y;

        if (mouseX >= quit.x && mouseX <= quit.x + quit.w &&
            mouseY >= quit.y && mouseY <= quit.y + quit.h) {
            event.type = SDL_QUIT;
            SDL_PushEvent(&event);
        }

        else if (mouseX >= start.x && mouseX <= start.x + start.w &&
            mouseY >= start.y && mouseY <= start.y + start.h) {
            sceneState = 1;
        }
    }
}

int Scene0::GetSceneState()  {
    return sceneState;
}

void Scene0::Update(double deltaTime)
{

}



void Scene0::Render(SDL_Renderer* renderer)
{
	
	mainMenu->Render(0, 0, 1080, 720);

	//SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	//SDL_RenderFillRect(renderer, &start); // to make the button visable
}
