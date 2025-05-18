#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


#include <iostream>
#include "ingredients.h"
#include "Customer.h"
#include <string>
#include "Player.h"
#include "window.h"

int SCREEN_WIDTH = 1080;	
int	SCREEN_HEIGHT = 720;

int main(int argc, char* args[]) {
	
	{
		/*
		Customer customer;
		ingredients ingredientsMenu;
		Player player;

		customer.customerOrder.push_back(ingredients::BUN);
		customer.customerOrder.push_back(ingredients::BUN);

		std::cout << customer.customerOrder[0];
		std::cout << ingredientsMenu.toString( ingredients::CHEESE) ;
		std::cout << ingredientsMenu.toString(customer.customerOrder[0]) << ' ';*/
	}
	
	
	if (SDL_Init(SDL_INIT_VIDEO) > 0) {
		printf("sdl could not intialize", SDL_GetError());
	}

	Window window("SDL Window", SCREEN_WIDTH, SCREEN_HEIGHT);
	SDL_Renderer* renderer = window.SDL_GetRenderer();

		if (renderer == nullptr) {
			printf("renderer could not be created", SDL_GetError());
		}

		
		SDL_Event event;
		
		Player player;
		

		while (window.gameRunning) {
			while (SDL_PollEvent(&event) != 0) {
				if (event.type == SDL_QUIT) {
					window.gameRunning = false;
				}
				player.PlaceOrder(event);
			}
			SDL_SetRenderDrawColor(renderer, 169, 169, 169, 1);
			

			SDL_RenderClear(renderer);

			SDL_RenderPresent(renderer);
			


		}



	window.close();

	return 0;
	
}