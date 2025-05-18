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
     printf("BUN ");
     playerOrder.push_back(ingredients::ingredientsType::BUN);
        break;
        case SDLK_b:
            playerOrder.push_back(ingredients::ingredientsType::RAWBURGER);
            printf("RAW BURGER ");
            break;
        case SDLK_l:
            playerOrder.push_back(ingredients::ingredientsType::LETTUCE);
            printf("LETTUCE ");
            break;
        case SDLK_t:
            playerOrder.push_back(ingredients::ingredientsType::TOMATO);
            printf("TOMATO ");
            break;
        case SDLK_k:
            playerOrder.push_back(ingredients::ingredientsType::KETCHUP);
            printf("KETCHUP ");
            break;
        case SDLK_c:
            playerOrder.push_back(ingredients::ingredientsType::CHEESE);
            printf("CHEESE ");
            break;
      case SDLK_ESCAPE:
       isRunning = false;
       break;
      default:
          printf("you pressed an invalid key");
        }
     }          
    
    return true;


}

std::vector<ingredients::ingredientsType> Player::getPlayersOrder() const
{
    return playerOrder;
}


