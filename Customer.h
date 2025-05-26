#pragma once
#include <vector>
#include "ingredients.h"
#include <queue>
#include <string>
#include "SDL2/SDL.h"
#include "ImageRenderer.h"
class Customer
{
public:
	Customer();
	~Customer();
	int enumSize = 6;
	int firstBurger = -100;
	int secondBurger = 100;
	int thirdBurger = 300;
	int random_index;
	//std::queue<std::vector<ingredients::ingredientsType>> LineUp;
	std::vector<std::vector<ingredients::ingredientsType>> LineUp;
	std::vector<ImageRenderer*> customerLineUp;
	std::vector<ingredients::ingredientsType> customerOrder;


	std::vector<ingredients::ingredientsType> getCustomersOrder() const;

	void makeRandomOrder();
};

