#include "Player.h"
#include <SDL2/SDL.h>
#include <iostream>
#include "Customer.h"
#include "ingredients.h"
#include "Scene1.h"

bool Player::PlaceOrder(SDL_Event& event) // BY KEY PRESS WILL ADD INBGRIEDNET TO THE VECTOR 
//CREATE THE PLAYERS ORDER
{                                           
    
    bool isRunning = true;
   
 
   if (event.type == SDL_KEYDOWN) {
      switch (event.key.keysym.sym) {
        case SDLK_e:
     printf("BUN ");
     playerOrder.push_back(ingredients::ingredientsType::BUN); //PUSHES INGREDIENT INTO VECTOR
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
          quit = true;
       break;
      case SDLK_RETURN:
          enter = true; // IF YOU PRESS ENTER YOU WILL SUBMIT THE ORDER TO ME COMPARED TO THE CUSTOMERS ORDER
          break;
      default:
          printf("you pressed an invalid key"); // PRESS ANYTHING ELSE AND WILL PRINT INVALID
        }
     }          
    
    return true;


}

std::vector<ingredients::ingredientsType> Player::getPlayersOrder() const
{
    return playerOrder; // JUST GETS THE PLAYERS ORDER
}


