#pragma once
#include "ingredients.h"
#include <vector>
#include <SDL2/SDL.h>

#include <chrono>
#include <thread>

class Player
{
	

public:
	int firstIng = 400;
	bool quit;
	bool enter;
	bool cooked = false;
	std::vector<ingredients::ingredientsType> playerOrder;
	std::chrono::time_point<std::chrono::high_resolution_clock> cookStartTime;
	bool PlaceOrder(SDL_Event& event);

	std::vector<ingredients::ingredientsType> getPlayersOrder() const;

};

