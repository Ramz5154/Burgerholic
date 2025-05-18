#pragma once
#include <vector>
#include "ingredients.h"
#include <queue>
#include <string>
#include "SDL2/SDL.h"

class Customer
{
public:
	Customer();
	~Customer();
	int enumSize = 6;
	int random_index;
	std::queue<int> LineUp;
	std::vector<ingredients::ingredientsType> customerOrder;


	std::vector<ingredients::ingredientsType> getCustomersOrder() const;

	void makeRandomOrder();
};

