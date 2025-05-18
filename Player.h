#pragma once
#include "ingredients.h"
#include <vector>
#include <SDL2/SDL.h>


class Player
{
public:
	std::vector<ingredients> playerOrder;

	bool PlaceOrder(SDL_Event& event);

};

