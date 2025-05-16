#pragma once
#include <vector>
#include "ingredients.h"
#include <queue>
#include <string>
class Customer
{
public:
	std::queue<int> LineUp;
	std::vector<ingredients::ingredientsType> customerOrder;

};

