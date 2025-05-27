#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include "window.h"
#include "Scene1.h"
#include <SDL2/SDL_ttf.h>

int SCREEN_WIDTH = 1080;
int SCREEN_HEIGHT = 720;

int main(int argc, char* args[]) {
    srand(time(0)); //make it random everytime

    if (TTF_Init() == -1) {
        std::cerr << "SDL_ttf could not initialize! Error: " << TTF_GetError() << std::endl;
        return -1;
    }


    if (SDL_Init(SDL_INIT_VIDEO) > 0) {
        std::cerr << "SDL could not initialize: " << SDL_GetError() << std::endl;
        return -1;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        std::cerr << "SDL_image could not initialize! Error: " << IMG_GetError() << std::endl;
        return -1;
    }

    Window window("Burgerholic", SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_Renderer* renderer = window.SDL_GetRenderer();

    if (!renderer) {
        std::cerr << "Renderer could not be created: " << SDL_GetError() << std::endl;
        return -1;
    }

    // Create and run the main game scene
    Scene1 scene(renderer);

    SDL_Event event;
    while (window.gameRunning) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                window.gameRunning = false;
            }
            scene.HandleEvents(event);
        }

        SDL_SetRenderDrawColor(renderer, 169, 169, 169, 255);
        SDL_RenderClear(renderer);

        scene.Update();
        scene.Render(renderer);

        SDL_RenderPresent(renderer);
    }

    window.close();
    IMG_Quit();
    return 0;
}
