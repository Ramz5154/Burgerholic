#pragma once
#include "ingredients.h"
#include <vector>
#include <SDL2/SDL.h>

#include <chrono>
#include <thread>

class Player
{
	

public:
	int firstIng = 500;// THIS INT IS USED AS THE FIRST INGRIEDNET X POSITION WHEN CREATING THE SANDWICH 

	bool enter;// USED TO SEND THE ORDER 
	bool quit; // USED TO QUIT THE GAME IN SCENE 1
	std::vector<ingredients::ingredientsType> playerOrder; // THE MAIN VECTOR THAT IS USED FOR THE PLAYERS ORDER. USED TO CREAT AND ORDER 
	
	bool PlaceOrder(SDL_Event& event);// FUNCTION THAT PUSHES INGIRDENTS BY KEY PRESS

	std::vector<ingredients::ingredientsType> getPlayersOrder() const;

};

