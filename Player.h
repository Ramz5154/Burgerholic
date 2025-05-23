#pragma once
#include "ingredients.h"
#include <vector>
#include <SDL2/SDL.h>


class Player
{
	

public:
	int firstIng = 400;
	bool quit;
	bool enter;
	std::vector<ingredients::ingredientsType> playerOrder;

	bool PlaceOrder(SDL_Event& event);

	std::vector<ingredients::ingredientsType> getPlayersOrder() const;

};

