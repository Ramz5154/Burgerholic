#include "Player.h"
#include <SDL2/SDL.h>
#include <iostream>


bool Player::PlaceOrder()
{
    SDL_Event event;
    bool isRunning = true;
    
    while (isRunning) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                case SDLK_e:
                    printf("nice");
                   
                    break;

                case SDLK_ESCAPE:
                    isRunning = true;
                    break;

                }
            }
        }
    }

  

    return true;


}

