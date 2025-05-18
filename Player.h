#pragma once
#include "ingredients.h"
#include <vector>
#include <SDL2/SDL.h>


class Player
{
public:
	std::vector<ingredients::ingredientsType> playerOrder;

	bool PlaceOrder(SDL_Event& event);

	std::vector<ingredients::ingredientsType> getPlayersOrder() const;

};

