#pragma once
#include <vector>
#include "ingredients.h"
#include <queue>
class Customer
{
public:
	std::queue<Customer> LineUp;
	std::vector<ingredients> customerOrder;

};

