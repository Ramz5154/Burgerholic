#include "Player.h"
#include <SDL2/SDL.h>
#include <iostream>
#include "Customer.h"
#include "ingredients.h"


bool Player::PlaceOrder(SDL_Event& event)
{
   
    bool isRunning = true;
   
 
   if (event.type == SDL_KEYDOWN) {
      switch (event.key.keysym.sym) {
        case SDLK_e:
     printf("BUN");
     playerOrder.push_back(ingredients::ingredientsType::BUN);
        break;
        case SDLK_b:
            playerOrder.push_back(ingredients::ingredientsType::BURGER);
            printf("BURGER");
      case SDLK_ESCAPE:
       isRunning = false;
       break;

        }
     }          
    
    return true;


}

std::vector<ingredients::ingredientsType> Player::getPlayersOrder() const
{
    return playerOrder;
}


