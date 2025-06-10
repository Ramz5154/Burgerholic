#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Memory.h"
#include <iostream>
#include "window.h"
#include "Scene1.h"
#include "Scene0.h"
#include "Scene3.h"
#include <SDL2/SDL_ttf.h>
#include <chrono>
int SCREEN_WIDTH = 1080;
int SCREEN_HEIGHT = 720;



Scene* currentScene;


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
    //currentScene = new Scene3(renderer, NULL, NULL);
    currentScene = new Scene0(renderer);

    SDL_Event event;
    auto lastTime = std::chrono::high_resolution_clock::now();

    while (window.gameRunning) {
        // Timing
        auto currentTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsedTime = currentTime - lastTime;
        double deltaTime = elapsedTime.count();
        lastTime = currentTime;

        // Event handling
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                window.gameRunning = false;
            }

            currentScene->HandleEvents(event);
        }

        // Logic and rendering
        SDL_SetRenderDrawColor(renderer, 169, 169, 169, 255);
        SDL_RenderClear(renderer);

        currentScene->Update(deltaTime);
        currentScene->Render(renderer);

        SDL_RenderPresent(renderer);

        // Scene switching
        int nextScene = currentScene->GetSceneState();
        switch (nextScene)
        {
        case 0:
            delete currentScene;
            currentScene = new Scene0(renderer);
            break;
        case 1:
            delete currentScene;
            currentScene = new Scene1(renderer);
            break;
        case 2:
        {
            Scene1* scene1 = dynamic_cast<Scene1*>(currentScene);
            int finalLevel = 1;
            int finalScore = 0;

            if (scene1) {
                finalLevel = scene1->GetLevel();
                finalScore = scene1->GetScore();
            }

            delete currentScene;
            currentScene = new Scene3(renderer, finalLevel, finalScore);
            break;
        }
        }
      
    }

    // Cleanup
    delete currentScene;
    //PrintSummary();
    window.close();
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();

    return 0;
}